PROPERTIES = {
	VariablePrefix = '';
	Range = '';
}

function Initialize()
	sVariablePrefix = PROPERTIES.VariablePrefix
	sRange = PROPERTIES.Range
	if sRange == 'Month' then
		iRange = 42
	elseif sRange == 'Week' then
		iRange = 7
	end
	iStartOnMondays = tonumber(SKIN:GetVariable(sVariablePrefix.."CalendarMondays"))
	iLeadingZeroes = tonumber(SKIN:GetVariable(sVariablePrefix.."CalendarLeadingZeroes"))
	iDisableDays = tonumber(SKIN:GetVariable(sVariablePrefix.."CalendarExtraDays"))
	iEDaysColor = iDisableDays == 1 and " | StyleCalendarTextExtra" or " | StyleCalendarTextInvisible"
	
	tMeterStyles = {}
	for a = 1, iRange do
		mSkin = SKIN:GetMeter(sVariablePrefix..'Day'..a)
		tMeterStyles[a] = mSkin:GetOption('MeterStyle')
	end
	tCurrMonth = {31;iFeb;31;30;31;30;31;31;30;31;30;31;}
	tPrevMonth = {31;31;iFeb;31;30;31;30;31;31;30;31;30;}
	tLabelsStartingSunday = {'S'; 'M'; 'T'; 'W'; 'R'; 'F'; 'S';}
	tLabelsStartingMonday = {'M'; 'T'; 'W'; 'R'; 'F'; 'S'; 'S';}
	
	iDayOnLastUpdate=0
end

function Update()
	local iToday = tonumber(os.date("%d"))
	if iToday ~= iDayOnLastUpdate then
		local iYear = os.date("%Y")
		local iFeb = 28+((iYear%4)==0 and 1 or 0)
		local iMonth = tonumber(os.date("%m"))
		local iWeekDay = tonumber(os.date("%w"))
		local when = os.time({year=iYear, month=iMonth, day=1})
		local iStartDay = os.date("%w", when)
		
		----------------------------------------------
		-- START ON SUNDAY OR MONDAY
		
		if iStartOnMondays == 1 then
			iStartDay = (iStartDay == 0) and 6 or iStartDay-1
			iWeekDay = (iWeekDay == 0) and 6 or iWeekDay-1
		end
		
		----------------------------------------------
		-- !SETOPTIONS
		
		if iStartOnMondays == 1 then
			for i = 1, 7 do
				SKIN:Bang('!SetOption "'..sVariablePrefix..'Day'..i..'Label" "Text" "'..tLabelsStartingMonday[i]..'"')
			end
		else
			for i = 1, 7 do
				SKIN:Bang('!SetOption "'..sVariablePrefix..'Day'..i..'Label" "Text" "'..tLabelsStartingSunday[i]..'"')
			end
		end
		
		for a = 1, iRange  do
			if sRange == 'Week' then
				b = iToday+((a-1)-iWeekDay)
			elseif sRange == 'Month' then
				b = a - iStartDay
			end
			if b < 1 then
				b = b + tPrevMonth[iMonth]
				SKIN:Bang('!SetOption "'..sVariablePrefix..'Day'..a..'" "MeterStyle" "'..tMeterStyles[a]..iEDaysColor..'"')
			elseif b > tCurrMonth[iMonth] then
				b = b-tCurrMonth[iMonth]
				SKIN:Bang('!SetOption "'..sVariablePrefix..'Day'..a..'" "MeterStyle" "'..tMeterStyles[a]..iEDaysColor..'"')
			else
				SKIN:Bang('!SetOption "'..sVariablePrefix..'Day'..a..'" "MeterStyle" "'..tMeterStyles[a]..'"')
			end
			if iLeadingZeroes == 1 then b = string.format("%02d",b) end
			SKIN:Bang('!SetOption "'..sVariablePrefix..'Day'..a..'" "Text" "'..b..'"')
		end
		if sRange == 'Month' then
			iThisWeek = math.ceil((iToday+iStartDay)/7)
			SKIN:Bang("!SetVariable "..sVariablePrefix.."ThisWeek "..iThisWeek)
		end
		SKIN:Bang("!SetVariable "..sVariablePrefix.."Week "..iWeekDay)
	end
	iDayOnLastUpdate=iToday
	SKIN:Bang('!SetOption "'..sVariablePrefix..'Indicator2" "Text" "'..iToday..'"')
	return 'Success!'
end