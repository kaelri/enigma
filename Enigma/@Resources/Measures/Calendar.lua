function Initialize()
	sRange = string.lower(SELF:GetOption('Range','month'))
	iStarOnMondays = SELF:GetNumberOption('StartOnMonday',0)>0
	iLeadingZeroes = SELF:GetNumberOption('LeadingZeroes',0)>0
	iEDaysColor = SELF:GetNumberOption('ExtraDays')>0 and ' | StyleCalendarTextExtra' or ' | StyleCalendarTextInvisible'
	
	iRange = {month=42,week=7}
	if not iRange[sRange] then sRange='month' end
	tCurrMonth = {31,28,31,30,31,30,31,31,30,31,30,31}
	iDayOnLastUpdate=0
	
	tMeterStyles = {}
	for a = 1, iRange[sRange] do
		local mSkin = SKIN:GetMeter('Day'..a)
		tMeterStyles[a] = mSkin:GetOption('MeterStyle')
	end
	local tLabels = {'S','M','T','W','R','F','S'}
	for i=1,7 do
		SKIN:Bang('!SetOption','Day'..i..'Label','Text',tLabels[iStartOnMondays and i%7+1 or i])
	end
end

function Update()
	local Date = os.date('*t')
	if Date.day ~= iDayOnLastUpdate then
		iDayOnLastUpdate=Date.day
		tCurrMonth[2] = 28+(((Date.year%4==0 and Date.year%100~=0) or Date.year%400==0) and 1 or 0)
		local iStartDay = Rotate(tonumber(os.date('%w', os.time({year=Date.year, month=Date.month, day=1}))))
		
		----------------------------------------------
		-- !SETOPTIONS
		
		
		local case={
			week=function(z) return Date.day+((z-1)-Rotate(Date.wday-1)) end,
			month=function(z) return z-iStartDay end,
		}
		for a = 1, iRange[sRange]  do
			mStyle=''
			b=case[sRange](a)
			if b<1 then
				b=b+tCurrMonth[Date.month==1 and 12 or Date.month-1 ]
				mStyle=iEDaysColor
			elseif b>tCurrMonth[Date.month] then
				b=b-tCurrMonth[Date.month]
				mStyle=iEDaysColor
			end
			for k,v in pairs({
				MeterStyle=tMeterStyles[a]..mStyle,
				Text=iLeadingZeroes and string.format('%02d',b) or b,
			}) do SKIN:Bang('!SetOption','Day'..a,k,v) end
		end
		if sRange == 'month' then
			SKIN:Bang('!SetVariable','ThisWeek',math.ceil((Date.day+iStartDay)/7))
		end
		SKIN:Bang('!SetVariable','Week',Rotate(Date.wday-1))
		SKIN:Bang('!SetOption','Indicator2','Text',Date.day)
	end
	return 'Success!'
end

function Rotate(a) return iStartOnMondays and (a-1+7)%7 or a end