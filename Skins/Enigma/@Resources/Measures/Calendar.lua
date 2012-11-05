function Initialize()
	iStartOnMondays = SELF:GetNumberOption('StartOnMonday', 0) > 0
	iLeadingZeroes = SELF:GetNumberOption('LeadingZeroes', 0) > 0
	iEDaysColor ='StyleCalendarText'..(SELF:GetNumberOption('ExtraDays') > 0 and 'Extra' or 'Invisible')
	
	local sRange =  SELF:GetOption('Range', 'month'):gsub('%s', ''):lower()
	if not ('month|week'):find(sRange) then ErrMsg(nil, 'Invalid Range: %s', sRange) end
	if sRange == 'week' then
		Range = {
			days = 7,
			formula = function(input) return Date.day + ((input - 1) - Rotate(Date.wday - 1)) end,
			week = function() return 1 end,
		}
	else
		Range = {
			days = 42,
			formula = function(input) return input - iStartDay end;
			week = function() return math.ceil((Date.day + iStartDay) / 7) end,
		}
	end

	iDayOnLastUpdate = 0

	local tLabels = Delim(SELF:GetOption('DayLabels'))
	if #tLabels < 7 then tLabels = {'S', 'M', 'T', 'W', 'R', 'F', 'S'} end
	for i = 1, 7 do
		SKIN:Bang('!SetOption', ('Day%dLabel'):format(i), 'Text', tLabels[iStartOnMondays and (i % 7 + 1) or i])
	end
	
	hFile = {}
	local Files = SELF:GetNumberOption('ShowEvents', 0) > 0 and Delim(SELF:GetOption('EventFile')) or {}
	if #Files > 1 then
		local Folder = table.remove(Files, 1) -- Remove Folder name from table.
		if not Folder:match('[\\/]$') then Folder = Folder .. '\\' end -- Add trailing forward slash.
		for k, v in ipairs(Files) do -- Concatenate Folder to each file.
			Files[k] = Folder .. v
		end
	end
	for _ , FileName in ipairs(Files) do -- For each event file.
		local file = io.open(SKIN:MakePathAbsolute(FileName), 'r') -- Open file in read only.
		if file then -- File is open.
			local open, content, close = file:read('*all'):gsub('<!%-%-.-%-%->', ''):match('^.-<([^>]+)>(.+)<([^>]+)>$')
			file:close()
			if open:lower():match('(%S+)') == 'eventfile' and close:lower() == '/eventfile' then
				local eFile, eSet = Keys(open), {}
				local default = {month = '', day = '', year = false, desc = '', title = false, color = '',}
				for tag, line in content:gmatch('<([^%s>]+)([^>]*)>') do
					local ntag = tag:lower()

					if ntag == 'set' then
						table.insert(eSet, Keys(line))
					elseif ntag == '/set' then
						table.remove(eSet)
					elseif ntag == 'event' then
						local Tmp, dSet, tbl = Keys(line), {}, {}
						for _, column in ipairs(eSet) do
							for key, value in pairs(column) do
								dSet[key] = value
							end
						end
						for key, value in pairs(default) do tbl[key] = Tmp[key] or dSet[key] or eFile[key] or value end
						table.insert(hFile, tbl)
					else
						ErrMsg(nil, 'Invalid Event Tag <%s> in %s', tag, FileName)
					end
				end
			else
				ErrMsg(nil, 'Invalid Event File: %s', FileName)
			end
		else -- File could not be opened.
			ErrMsg(nil, 'File Read Error: %s', FileName)
		end
	end
end -- Initialize

function Update()
	Date = os.date('*t')
	if Date.day ~= iDayOnLastUpdate then
		iDayOnLastUpdate = Date.day
		local tstart = os.time{day = 1, month = Date.month, year = Date.year, isdst = false,}
		local nstart = os.time{day = 1, month = (Date.month % 12 + 1), year = (Date.year + (Date.month == 12 and 1 or 0)), isdst = false,}
		mLength, pLength, iStartDay = (nstart - tstart) / 86400, tonumber(os.date('%d', tstart - 86400)), Rotate(tonumber(os.date('%w', tstart)))
		
		Events()
		
		----------------------------------------------
		-- !SETOPTIONS
		
		for wday = 1, 7 do -- Set Weekday Labels styles
			local Styles = {'StyleCalendarLabelBackground'}
			if wday == 1 then
				table.insert(Styles, 'StyleCalendarLabelBackgroundFirst')
			end
			if Rotate(Date.wday - 1) == (wday - 1) then
				table.insert(Styles, 'StyleCalendarLabelBackgroundCurrent')
			end
			SKIN:Bang('!SetOption', ('Day%dLabelBackground'):format(wday), 'MeterStyle', table.concat(Styles, '|'))
		end

		for meter = 1, Range.days  do
			local styles, event, day, color = {'StyleCalendarText'}, '', Range.formula(meter)
			if meter == 1 then
				table.insert(styles, 'StyleCalendarTextFirst')
			elseif (meter % 7) == 1 then
				table.insert(styles, 'StyleCalendarNewWeek')
			end
			
			if day > 0 and day <= mLength and Hol[day] then
				table.insert(styles, 'StyleCalendarEvent')
				event = table.concat(Hol[day]['text'], '\n')
				-- Compress multiple custom colors
				for _, value in ipairs(Hol[day].color) do
					if value ~= '' then
						if not color then
							color = value
						elseif color ~= value then
							color = ''
							break
						end
					end
				end
			end
			
			if day < 1 then -- Previous Month
				day = day + pLength
				table.insert(styles, iEDaysColor)
			elseif day > mLength then -- Next Month
				day = day - mLength
				table.insert(styles, iEDaysColor)
			elseif Date.day == a then -- Today
				table.insert(styles, 'StyleCalendarIndicatorText')
			end
			
			for k,v in pairs{ -- Meter Properties
				MeterStyle = table.concat(styles, '|'),
				Text = iLeadingZeroes and ('%02d'):format(day) or day,
				ToolTipText = event,
				SolidColor = color or '',
			} do SKIN:Bang('!SetOption', 'Day' .. meter, k, v) end
		end
		for k, v in pairs{ -- Skin Variables
			ThisWeek = Range.week(),
			Week = Rotate(Date.wday - 1),
		} do SKIN:Bang('!SetVariable', k, v) end
	end
	return rMessage or 'Success!'
end -- Update

function Events() -- Parse Events table.
	Hol={}
	
	for _,event in ipairs(hFile) do
		if SKIN:ParseFormula(('(%s)'):format(Vars(event.month, event.desc))) == Date.month or event.month == '*' then
			
			local day = SKIN:ParseFormula(('(%s)'):format(Vars(event.day, event.desc))) or ErrMsg(0, 'Invalid Event Day %s in %s', event.day, event.desc)
			local color = event.color:match(',') and ConvertToHex(event.color) or event.color
			local desc = table.concat{
				event.desc,
				event.year and (' (%s)'):format(math.abs(Date.year - event.year)) or '',
				event.title and ' -' .. event.title or '',
			}
			
			if Hol[day] then
				table.insert(Hol[day]['text'], desc)
				table.insert(Hol[day]['color'], color)
			else
				Hol[day] = {text = {desc}, color = {color},}
			end
		end
	end
end -- Events

function Easter() -- Returns a timestamp representing easter of the current year.
	local a, b, c, h, L, m = (Date.year % 19), math.floor(Date.year / 100), (Date.year % 100), 0, 0, 0
	local d, e, f, i, k = math.floor(b / 4), (b % 4), math.floor((b + 8) / 25), math.floor(c / 4), (c % 4)
	h = (19 * a + b - d - math.floor((b - f + 1) / 3) + 15) % 30
	L = (32 + 2 * e + 2 * i - h - k) % 7
	m = math.floor((a + 11 * h + 22 * L) / 451)
	
	return os.time{month = math.floor((h + L - 7 * m + 114) / 31), day = ((h + L - 7 * m + 114) % 31 + 1), year = Date.year}
end -- Easter

function Vars(line, source) -- Makes allowance for {Variables}
	local tbl = setmetatable({year = Date.year, today = Date.day, month = Date.month},
		{ __index = function(_, var)
			local D, W = {sun=0, mon=1, tue=2, wed=3, thu=4, fri=5, sat=6}, {first=0, second=1, third=2, fourth=3, last=4}
			local v1,v2 = var:match('(.+)(...)')
			if W[v1 or ''] and D[v2 or ''] then -- Variable day.
				if v1 == 'last' then
					local L = (36 + D[v2] - iStartDay)
					return L - math.ceil((L - mLength) / 7) * 7
				else
					return Rotate(D[v2]) + 1 - iStartDay + (iStartDay > Rotate(D[v2]) and 7 or 0) + 7 * W[v1]
				end
			else -- Error
				return ErrMsg(0, 'Invalid Variable {%s} in %s', var, source)
			end
		end})
	
	-- Built In Events
	local AddVar = function(name, timestamp)
		local temp = os.date('*t', timestamp)
		tbl[name:lower() .. 'month'] = temp.month
		tbl[name:lower() .. 'day'] = temp.day
	end
	-- Define {variables} here.
	local sEaster = Easter()
	AddVar('easter', sEaster)
	AddVar('goodfriday', (sEaster - 2 * 86400))
	AddVar('ashwednesday', (sEaster - 46 * 86400))
	AddVar('mardigras', (sEaster - 47 * 86400))

	return tostring(line):gsub('{([^}]+)}', function(variable) return tbl[variable:gsub('%s', ''):lower()] end)
end -- Vars

function ErrMsg(...) -- Used to display errors
	local value = table.remove(arg, 1)
	rMessage = string.format(unpack(arg))
	print('Calendar: ' .. rMessage)
	return value
end -- ErrMsg

function Rotate(value) return iStartOnMondays and ((value - 1 + 7) % 7) or value end

function Keys(line, default) -- Converts Key="Value" sets to a table
	local tbl = default or {}
	local escape = { quot = '"', lt = '<', gt = '>', amp = '&' } -- XML escape characters
	
	for key, value in line:gmatch('(%a+)="([^"]+)"') do
		value = value:gsub('&([^;]+);', escape)
		tbl[key:lower()] = tonumber(value) or value
	end
	
	return tbl
end -- Keys

function Delim(line) -- Separate String by Delimiter
	local tbl = {}
	for word in line:gmatch('[^|]+') do table.insert(tbl, word) end
	return tbl
end -- Delim

function ConvertToHex(color) -- Converts RGB colors to HEX
	local hex = {}
	
	color = color:gsub('%s', '')
	for rgb in color:gmatch('%d+') do
		table.insert(hex, string.format('%02X',tonumber(rgb)))
	end
	
	return table.concat(hex)
end -- ConvertToHex