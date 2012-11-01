function Initialize()
	sRange = SELF:GetOption('Range', 'month'):lower()
	iStartOnMondays = SELF:GetNumberOption('StartOnMonday', 0) > 0
	iLeadingZeroes = SELF:GetNumberOption('LeadingZeroes', 0) > 0
	iEDaysColor ='StyleCalendarText'..(SELF:GetNumberOption('ExtraDays') > 0 and 'Extra' or 'Invisible')
	
	Error=false
	
	iRange = {month = 42, week = 7}
	if not iRange[sRange] then sRange = 'month' end
	tCurrMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	iDayOnLastUpdate = 0

	local tLabels = Delim(SELF:GetOption('DayLabels'))
	if #tLabels < 7 then tLabels = {'S', 'M', 'T', 'W', 'R', 'F', 'S'} end
	for i = 1, 7 do
		SKIN:Bang('!SetOption', 'Day'..i..'Label', 'Text', tLabels[iStartOnMondays and (i % 7 + 1) or i])
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
	for _ ,FileName in ipairs(Files) do -- For each event file.
		local file=io.open(SKIN:MakePathAbsolute(FileName), 'r') -- Open file in read only.
		if file then -- File is open.
			local open, content, close = file:read('*all'):gsub('<!%-%-.-%-%->', ''):match('^.-<([^>]+)>(.+)<([^>]+)>$')
			file:close()
			if open:lower():match('([^%s]+)') == 'eventfile' and close:lower() == '/eventfile' then
				local eFile, eSet = Keys(open), {}
				local default = {month='', day='', year=false, desc='', title=false, color='',}
				local sw={ -- Define Event File tags
					set = function(x) table.insert(eSet, Keys(x)) end,
					['/set'] = function(x) table.remove(eSet) end,
					event = function(x)
						local Tmp, dSet, tbl = Keys(x), ParseTbl(eSet), {}
						for key, value in pairs(default) do tbl[key] = Tmp[key] or dSet[key] or eFile[key] or value end
						table.insert(hFile, tbl)
					end,
					default = function(x, y) ErrMsg(0, 'Invalid Event Tag:', y) end, -- Error
				}
				for line in content:gmatch('%b<>') do
					local tag = line:match('^<([^%s>]+)')
					local f = sw[tag:lower()] or sw.default
					f(line, tag)
				end
			else
				ErrMsg(0, 'Invalid Event File:', FileName)
			end
		else -- File could not be opened.
			ErrMsg(0, 'File Read Error:', FileName)
		end
	end
end -- Initialize

function Update()
	Date = os.date('*t')
	if Date.day ~= iDayOnLastUpdate then
		iDayOnLastUpdate = Date.day
		tCurrMonth[2] = 28+((((Date.year % 4) == 0 and (Date.year % 100) ~= 0) or (Date.year % 400) == 0) and 1 or 0)
		iStartDay = Rotate(tonumber(os.date('%w', os.time{year = Date.year, month = Date.month, day = 1})))
		
		Events()
		
		----------------------------------------------
		-- !SETOPTIONS
		
		local case = {
			week = function(z) return Date.day + ((z - 1) - Rotate(Date.wday - 1)) end,
			month = function(z) return z-iStartDay end,
		}
		for meter = 1, iRange[sRange]  do
			local styles, event, color, day = {'StyleCalendarText'}, '', '', case[sRange](meter)
			if meter == 1 then
				table.insert(styles, 'StyleCalendarTextFirst')
			elseif (meter % 7) == 1 then
				table.insert(styles, 'StyleCalendarNewWeek')
			end
			
			if day > 0 and day <= tCurrMonth[Date.month] and Hol[day] then
				table.insert(styles, 'StyleCalendarEvent')
				event = table.concat(Hol[day]['text'], '\n')
				color = eColor(Hol[day]['color'])
			end
			
			if day < 1 then -- Previous Month
				day = day + tCurrMonth[Date.month == 1 and 12 or (Date.month - 1) ]
				table.insert(styles, iEDaysColor)
			elseif day > tCurrMonth[Date.month] then -- Next Month
				day = day - tCurrMonth[Date.month]
				table.insert(styles, iEDaysColor)
			elseif Date.day == a then -- Today
				table.insert(styles, 'StyleCalendarIndicatorText')
			end
			
			for k,v in pairs{
				MeterStyle = table.concat(styles, '|'),
				Text = iLeadingZeroes and string.format('%02d', day) or day,
				ToolTipText = event,
				SolidColor = color
			} do SKIN:Bang('!SetOption', 'Day' .. meter, k, v) end
		end
		if sRange == 'month' then
			SKIN:Bang('!SetVariable', 'ThisWeek', math.ceil((Date.day + iStartDay) / 7))
		end
		SKIN:Bang('!SetVariable', 'Week', Rotate(Date.wday - 1))
	end
	return Error and 'Error!' or 'Success!'
end -- Update

function Events() -- Parse Events table.
	Hol={}
	
	for _,event in ipairs(hFile) do
		if SKIN:ParseFormula('(' .. Vars(event.month, event.desc) .. ')') == Date.month or event.month == '*' then
			
			local day = SKIN:ParseFormula('(' .. Vars(event.day, event.desc) .. ')') or ErrMsg(0, 'Invalid Event Day', event.day, 'in', event.desc)
			local color = event.color:match(',') and ConvertToHex(event.color) or event.color
			local desc = table.concat{
				event.desc,
				event.year and ' (' .. math.abs(Date.year - event.year) .. ')' or '',
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

function eColor(tbl) -- Makes allowance for multiple custom colors.
	local color
	-- Remove Empty Colors
	for k, v in ipairs(tbl) do if v == '' then table.remove(tbl, k) end end
	
	for _,value in ipairs(tbl) do
		if color then
			if color ~= value then
				return ''
			end
		else
			color = value
		end
	end
	
	return color
end -- eColor

function Easter() -- Returns a timestamp representing easter of the current year.
	local a, b, c, h, L, m = (Date.year % 19), math.floor(Date.year / 100), (Date.year % 100), 0, 0, 0
	local d, e, f, i, k = math.floor(b / 4), (b % 4), math.floor((b + 8) / 25), math.floor(c / 4), (c % 4)
	h = (19 * a + b - d - math.floor((b - f + 1) / 3) + 15) % 30
	L = (32 + 2 * e + 2 * i - h - k) % 7
	m = math.floor((a + 11 * h + 22 * L) / 451)
	
	return os.time{month = math.floor((h + L - 7 * m + 114) / 31), day = ((h + L - 7 * m + 114) % 31 + 1), year = Date.year}
end -- Easter

function BuiltInEvents(default) -- Makes allowance for events that require complex calculations.
	local tbl = default or {}
	local AddVar = function(name, timestamp)
		local temp = os.date('*t', timestamp)
		tbl[name..'month'] = temp.month
		tbl[name..'day'] = temp.day
	end
	-- Define {variables} here.
	local sEaster = Easter()
	AddVar('easter', sEaster)
	AddVar('goodfriday', (sEaster - 2 * 86400))
	AddVar('ashwednesday', (sEaster - 46 * 86400))
	AddVar('mardigras', (sEaster - 47 * 86400))
	
	return tbl
end -- BuiltInEvents

function Vars(line,source) -- Makes allowance for {Variables}
	local D, W = {sun=0, mon=1, tue=2, wed=3, thu=4, fri=5, sat=6}, {first=0, second=1, third=2, fourth=3, last=4}
	local tbl = BuiltInEvents{year = Date.year, today = Date.day, month = Date.month}
	
	return tostring(line):gsub('{([^}]+)}', function(variable)
		local strip = variable:lower()
		local v1,v2 = strip:match('(.+)(...)')
		if tbl[strip] then
			return tbl[strip]
		elseif W[v1 or ''] and D[v2 or ''] then -- Variable day.
			local L,wD = (36 + D[v2] - iStartDay), Rotate(D[v2])
			return W[v1] < 4 and (wD + 1 - iStartDay + (iStartDay > wD and 7 or 0) + 7 * W[v1]) or (L - math.ceil((L - tCurrMonth[Date.month]) / 7) * 7)
		else -- Error
			return ErrMsg(0, 'Invalid Variable', variable, source and 'in '..source or '')
		end
	end)
end -- Vars

function ErrMsg(...) -- Used to display errors
	Error=true
	print(table.concat(arg, ' ', 2))
	return arg[1]
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

function ParseTbl(input) -- Compresses matrix into a single table.
	local tbl = {}
	
	for _,column in ipairs(input) do
		for key,value in pairs(column) do
			tbl[key] = value
		end
	end
	
	return tbl
end -- ParseTbl