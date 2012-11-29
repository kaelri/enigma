-- LuaCalendar v4.1 by Smurfier (smurfier20@gmail.com)
-- This work is licensed under a Creative Commons Attribution-Noncommercial-Share Alike 3.0 License.

function Initialize()
	Settings = {
		Name = 'Calendar', -- String
		Color = 'SolidColor', -- String
		Range = SELF:GetOption('Range', 'month'):lower(), -- String
		HideLastWeek = false, -- Boolean
		LeadingZeroes = SELF:GetNumberOption('LeadingZeroes', 0) > 0, -- Boolean
		StartOnMonday = SELF:GetNumberOption('StartOnMonday', 0) > 0, -- Boolean
		LabelFormat = '{$MName}, {$Year}', -- String
		NextFormat = '{$day}: {$desc}', -- String
		Locale = SELF:GetNumberOption('UseLocalMonths', 0) > 0, -- Boolean
		--MonthNames = Delim(SELF:GetOption('MonthLabels')), -- Table
	}
	-- MeterStyle Names
	local iEDaysColor ='StyleCalendarText' .. (SELF:GetNumberOption('ExtraDays') > 0 and 'Extra' or 'Invisible')

	Meters = {
		Labels = { -- Week Day Labels
			Name = 'Day%dLabel',
			Styles = {
				Normal = 'StyleCalendarLabel',
				First = 'StyleCalendarLabelFirst',
				Current = 'StyleCalendarLabelCurrent',
			},
		},
		Days = { -- Month Days
			Name = 'Day%d',
			Styles = {
				Normal = 'StyleCalendarText',
				FirstDay = 'StyleCalendarTextFirst',
				NewWeek = 'StyleCalendarNewWeek',
				Current = 'StyleCalendarIndicatorText',
				LastWk = iEDaysColor,
				PrevMnth = iEDaysColor,
				NxtMnth = iEDaysColor,
				Wknd = 'WeekendStyle',
				Holiday = 'StyleCalendarEvent',
			},
		},
	}

	-- Weekday labels text
	SetLabels(Delim(SELF:GetOption('DayLabels', 'S|M|T|W|R|F|S')))
	--Events File
	if SELF:GetNumberOption('ShowEvents', 0) > 0 then LoadEvents(ExpandFolder(Delim(SELF:GetOption('EventFile')))) end
end -- Initialize
function Update()
	CombineScroll(0)

	-- If in the current month or if browsing and Month changes to that month, set to Real Time
	if (Time.stats.inmonth and Time.show.month ~= Time.curr.month) or ((not Time.stats.inmonth) and Time.show.month == Time.curr.month and Time.show.year == Time.curr.year) then
		Move()
	end
	
	if Time.show.month ~= Time.old.month or Time.show.year ~= Time.old.year then -- Recalculate and Redraw if Month and/or Year changes
		Time.old = {month = Time.show.month, year = Time.show.year, day = Time.curr.day}
		Events()
		Draw()
	elseif Time.curr.day ~= Time.old.day then -- Redraw if Today changes
		Time.old.day = Time.curr.day
		Draw()
	end
	
	return ReturnError()
end -- Update

function CombineScroll(input)
	if input and not Scroll then
		Scroll = input
	elseif Scroll ~= 0 and input == 0 then
		Move(Scroll / math.abs(Scroll))
		Scroll = 0
	else
		Scroll = Scroll + input
	end
end

Time = { -- Used to store and call date functions and statistics
	curr = setmetatable({}, {__index = function(_, index) return os.date('*t')[index] end,}),
	old = {day = 0, month = 0, year = 0,},
	show = {month = 0, year = 0,},
	stats = setmetatable({inmonth = true,}, {__index = function(_, index)
		local tstart = os.time{day = 1, month = Time.show.month, year = Time.show.year, isdst = false,}
		local nstart = os.time{day = 1, month = (Time.show.month % 12 + 1), year = (Time.show.year + (Time.show.month == 12 and 1 or 0)), isdst = false,}
		
		return ({
			clength = ((nstart - tstart) / 86400),
			plength = (tonumber(os.date('%d', tstart - 86400))),
			startday = rotate(tonumber(os.date('%w', tstart))),
		})[index]
	end,}),
} -- Time

Range = setmetatable({ -- Makes allowance for either Month or Week ranges
	month = {
		formula = function(input) return input - Time.stats.startday end,
		days = 42,
		week = function() return math.ceil((Time.curr.day + Time.stats.startday) / 7) end,
	},
	week = {
		formula = function(input) return Time.curr.day +((input - 1) - rotate(Time.curr.wday - 1)) end,
		days = 7,
		week = function() return 1 end,
		nomove = true,
	},
	}, { __index = function(tbl, index) return ErrMsg(tbl.month, 'Invalid Range: %s', index) end,
}) -- Range

function MLabels(input) -- Makes allowance for Month Names
	if Settings.Locale then
		os.setlocale('', 'time')
		return os.date('%B', os.time{year = 2000, month = input, day = 1})
	elseif type(Settings.MonthNames) == 'table' then
		return Settings.MonthNames[input] or ErrMsg(input, 'Not enough indices in MonthNames')
	else
		return input
	end
end -- MLabels

function Delim(input, sep) -- Separates an input string by a delimiter
	test(type(input) == 'string', 'Delim: input must be a string. Received %s instead', type(input))
	if sep then test(type(sep) == 'string', 'Delim: sep must be a string. Received %s instead', type(sep)) end
	local tbl = {}
	for word in input:gmatch('[^' .. (sep or '|') .. ']+') do table.insert(tbl, word:match('^%s*(.-)%s*$')) end
	return tbl
end -- Delim

function ExpandFolder(input) -- Makes allowance for when the first value in a table represents the folder containing all objects.
	test(type(input) == 'table', 'ExpandFolder: input must be a table. Received %s instead.', type(input))
	if #input > 1 then
		local folder = table.remove(input, 1)
		if not folder:match('[/\\]$') then folder = folder .. '\\' end
		for k, v in ipairs(input) do input[k] = SKIN:MakePathAbsolute(folder .. v) end
	end
	return input
end -- ExpandFolder

function SetLabels(tbl) -- Sets weekday labels
	test(type(tbl) == 'table', 'SetLabels must recieve a table')
	if #tbl < 7 then tbl = ErrMsg({'S', 'M', 'T', 'W', 'T', 'F', 'S'}, 'Invalid SetLabels input') end
	for a = 1, 7 do SKIN:Bang('!SetOption', Meters.Labels.Name:format(a), 'Text', tbl[Settings.StartOnMonday and (a % 7 + 1) or a]) end
end -- SetLabels

function LoadEvents(FileTable)
	test(type(FileTable) == 'table', 'LoadEvents: input must be a table. Received %s instead.', type(FileTable))

	hFile = {}
	local default = {
		month = {value = '', ktype = 'string'},
		day = {value = '', ktype = 'string'},
		year = {value = false, ktype = 'number'},
		descri = {value = '', ktype = 'string', spaces = true},
		title = {value = false, ktype = 'string'},
		color = {value = false, ktype = 'color'},
		['repeat'] = {value = false, ktype = 'string'},
		multip = {value = 1, ktype = 'number', round = 0},
		annive = {value = false, ktype = 'boolean'},
		inacti = {value = false, ktype = 'boolean'},
	}

	local Keys = function(line, source)
		local tbl = {}
		
		local funcs = {
			color = function(key, input)
				input = input:gsub('%s', '')
				if input:len() == 0 then
					return false
				elseif input:match(',') then
					local hex = {}
					for rgb in input:gmatch('%d+') do table.insert(hex, ('%02X'):format(tonumber(rgb))) end
					for i = #hex, 4 do table.insert(hex, 'FF') end
					return table.concat(hex)
				else
					return input
				end
			end, -- color
			number = function(key, input)
				local num = tonumber((input:gsub('%s', '')))
				return (num and default[key].round) and ('%.' .. default[key].round .. 'f'):format(num) or num
			end, -- number
			string = function(key, input) return default[key].spaces and input:match('^%s*(.-)%s*$') or (input:gsub('%s', '')) end,
			boolean = function(key, input) return input:gsub('%s', ''):lower() == 'true' end,
		}
	
		local escape = {quot='"', lt='<', gt='>', amp='&',} -- XML escape characters

		for key, value in line:gmatch('(%a+)="([^"]+)"') do
			local nkey = key:sub(1, 6):lower()
			if default[nkey] then
				tbl[nkey] = funcs[(default[nkey].ktype)](nkey, value:gsub('&([^;]+);', escape):gsub('\r?\n', ' '))
			else
				ErrMsg(nil, 'Invalid key %s=%q in %s', key, value, source)
			end
		end
	
		return tbl
	end

	for _, FileName in ipairs(FileTable) do
		local File, fName = test(io.open(FileName, 'r'), 'File Read Error: %s', fName), FileName:match('[^/\\]+$')
		
		local open, content, close = File:read('*all'):gsub('<!%-%-.-%-%->', ''):match('^.-<([^>]+)>(.+)<([^>]+)>[^>]*$')
		File:close()

		test(open:match('%S+'):lower() == 'eventfile' and close:lower() == '/eventfile', 'Invalid Event File: %s', fName)
		local eFile, eSet = Keys(open, fName), {}
			
		for tag, line in content:gmatch('<([^%s>]+)([^>]*)>') do
			local ntag = tag:lower()

			if ntag == 'set' then
				table.insert(eSet, Keys(line, fName))
			elseif ntag == '/set' then
				table.remove(eSet)
			elseif ntag == 'event' then
				local Tmp, dSet, tbl = Keys(line, fName), {}, {}
				for _, column in ipairs(eSet) do
					for key, value in pairs(column) do dSet[key] = value end
				end
				for k, v in pairs(default) do tbl[k] = Tmp[k] or dSet[k] or eFile[k] or v.value end
				if not tbl.inacti then table.insert(hFile, tbl) end
			else
				ErrMsg(nil, 'Invalid Event Tag <%s> in %s', tag, fName)
			end
		end
	end
end -- LoadEvents

function Events() -- Parse Events table.
	Hol = setmetatable({}, { __call = function(self) -- Returns a list of events
		local Evns = {}
	
		for day = Time.stats.inmonth and Time.curr.day or 1, Time.stats.clength do -- Parse through month days to keep days in order
			if self[day] then
				local tbl = setmetatable({day = day, desc = table.concat(self[day]['text'], ', ')},
					{ __index = function(_, input) return ErrMsg('', 'Invalid NextFormat variable {%s}', input) end,})
				table.insert(Evns, (Settings.NextFormat:gsub('{%$([^}]+)}', function(variable) return tbl[variable:lower()] end)) )
			end
		end
	
		return table.concat(Evns, '\n')
	end})

	local AddEvn = function(day, desc, color, ann)
		desc = desc:format(ann and (' (%s)'):format(ann) or '')
		if Hol[day] then
			table.insert(Hol[day].text, desc)
			table.insert(Hol[day].color, color)
		else
			Hol[day] = {text = {desc}, color = {color},}
		end
	end
	
	local formula = function(input, source) return SKIN:ParseFormula(('(%s)'):format(Vars(input, source))) end
	local tstamp = function(d, m, y) return os.time{day = d, month = m, year= y, isdst = false} end

	for _, event in ipairs(hFile or {}) do
		local eMonth = formula(event.month, event.descri)
		if  eMonth == Time.show.month or event['repeat'] then
			local day = formula(event.day, event.descri) or ErrMsg(0, 'Invalid Event Day %s in %s', event.day, event.descri)
			local desc = event.descri .. '%s' .. (event.title and ' -' .. event.title or '')

			local nrepeat = (event['repeat'] or ''):lower()

			if nrepeat == 'week' then
				if eMonth and event.year and day then
					local stamp = tstamp(day, eMonth, event.year)
					local test = tstamp(day, Time.show.month, Time.show.year) >= stamp
					local mstart = tstamp(1, Time.show.month, Time.show.year)
					local multi = event.multip * 604800
					local first = mstart + ((stamp - mstart) % multi)

					for a = 0, 4 do
						local tstamp = first + a * multi
						local temp = os.date('*t', tstamp)
						if temp.month == Time.show.month and test then
							AddEvn(temp.day, desc, event.color, event.annive and ((tstamp - stamp) / multi + 1) or false)
						end
					end
				end
			elseif nrepeat == 'year' then
				local test = (event.year and event.multip > 1) and ((Time.show.year - event.year) % event.multip) or 0

				if eMonth == Time.show.month and test == 0 then
					AddEvn(day, desc, event.color, event.annive and (Time.show.year - event.year / event.multip) or false)
				end
			elseif nrepeat == 'month' then
				if eMonth and event.year then
					if Year >= event.year then
						local ydiff = Time.show.year - event.year - 1
						local mdiff = ydiff == -1 and (Time.show.month - eMonth) or ((12 - eMonth) + Time.show.month + (ydiff * 12))
						local estamp, mstart = tstamp(1, eMonth, event.year), tstamp(1, Time.show.month, Time.show.year)

						if (mdiff % event.multip) == 0 and mstart >= estamp then
							AddEvn(day, desc, event.color, event.annive and (mdiff / event.multip + 1) or false)
						end
					end
				else
					AddEvn(day, desc, event.color, false)
				end
			elseif event.year == Time.show.year then
				AddEvn(day, desc, event.color)
			end
		end
	end
end -- Events

function Draw() -- Sets all meter properties and calculates days
	local LastWeek = Settings.HideLastWeek and math.ceil((Time.stats.startday + Time.stats.clength) / 7) < 6
	
	for wday = 1, 7 do -- Set Weekday Labels styles
		local Styles = {Meters.Labels.Styles.Normal}
		if wday == 1 then
			table.insert(Styles, Meters.Labels.Styles.First)
		end
		if rotate(Time.curr.wday - 1) == (wday - 1) and Time.stats.inmonth then
			table.insert(Styles, Meters.Labels.Styles.Current)
		end
		SKIN:Bang('!SetOption', Meters.Labels.Name:format(wday), 'MeterStyle', table.concat(Styles, '|'))
	end

	for meter = 1, Range[Settings.Range].days do -- Calculate and set day meters
		local Styles, day, event, color = {Meters.Days.Styles.Normal}, Range[Settings.Range].formula(meter)

		if meter == 1 then
			table.insert(Styles, Meters.Days.Styles.FirstDay)
		elseif (meter % 7) == 1 then
			table.insert(Styles, Meters.Days.Styles.NewWeek)
		end
		-- Holiday ToolTip and Style
		if Hol then
			if day > 0 and day <= Time.stats.clength and Hol[day] then
				event = table.concat(Hol[day].text, '\n')
				table.insert(Styles, Meters.Days.Styles.Holiday)

				for _, value in ipairs(Hol[day].color) do
					if value then
						if not color then
							color = value
						elseif color ~= value then
							color = ''
							break
						end
					end
				end
			end
		end
		
		if (Time.curr.day + Time.stats.startday) == meter and Time.stats.inmonth then
			table.insert(Styles, Meters.Days.Styles.Current)
		elseif meter > 35 and LastWeek then
			table.insert(Styles, Meters.Days.Styles.LastWk)
		elseif day < 1 then
			day = day + Time.stats.plength
			table.insert(Styles, Meters.Days.Styles.PrevMnth)
		elseif day > Time.stats.clength then
			day = day - Time.stats.clength
			table.insert(Styles, Meters.Days.Styles.NxtMnth)
		elseif (meter % 7) == 0 or (meter % 7) == (Settings.StartOnMonday and 6 or 1) then
			table.insert(Styles, Meters.Days.Styles.Wknd)
		end
		
		for k, v in pairs{ -- Define meter properties
			Text = LZero(day),
			MeterStyle = table.concat(Styles, '|'),
			ToolTipText = event or '',
			[Settings.Color] = color or '',
		} do SKIN:Bang('!SetOption', Meters.Days.Name:format(meter), k, v) end
	end
	
	local sVars = { -- Define skin variables
		ThisWeek = Range[Settings.Range].week(),
		Week = rotate(Time.curr.wday - 1),
		Today = LZero(Time.curr.day),
		Month = MLabels(Time.show.month),
		Year = Time.show.year,
		MonthLabel = Vars(Settings.LabelFormat, 'MonthLabel'),
		LastWkHidden = LastWeek and 1 or 0,
		NextEvent = Hol and Hol() or '',
	}
	-- Week Numbers for the current month
	local FirstWeek = os.time{day = (6 - Time.stats.startday), month = Time.show.month, year = Time.show.year}
	for i = 0, 5 do sVars['WeekNumber' .. (i + 1)] = math.ceil(tonumber(os.date('%j', (FirstWeek + (i * 604800)))) / 7) end
	-- Set Skin Variables
	for k, v in pairs(sVars) do SKIN:Bang('!SetVariable', k, v) end
end -- Draw

function Move(value) -- Move calendar through the months
	if value then test(type(value) == 'number', 'Move: input must be a number. Received %s instead.', type(value)) end
	if Range[Settings.Range].nomove or not value then
		Time.show = Time.curr
	elseif math.ceil(value) ~= value then
		ErrMsg(nil, 'Invalid Move Parameter %s', value)
	else
		local mvalue = Time.show.month + value - (math.modf(value / 12)) * 12
		local mchange = value < 0 and (mvalue < 1 and 12 or 0) or (mvalue > 12 and -12 or 0)
		Time.show = {month = (mvalue + mchange), year = (Time.show.year + (math.modf(value / 12)) - mchange / 12),}
	end

	Time.stats.inmonth = Time.show.month == Time.curr.month and Time.show.year == Time.curr.year
	SKIN:Bang('!SetVariable', 'NotCurrentMonth', Time.stats.inmonth and 0 or 1)
end -- Move

function Easter(year) -- Returns a timestamp representing easter of the current year
	local a, b, c, h, L, m = (year % 19), math.floor(year / 100), (year % 100), 0, 0, 0
	local d, e, f, i, k = math.floor(b/4), (b % 4), math.floor((b + 8) / 25), math.floor(c / 4), (c % 4)
	h = (19 * a + b - d - math.floor((b - f + 1) / 3) + 15) % 30
	L = (32 + 2 * e + 2 * i - h - k) % 7
	m = math.floor((a + 11 * h + 22 * L) / 451)
	
	return os.time{month = math.floor((h + L - 7 * m + 114) / 31), day = ((h + L - 7 * m + 114) % 31 + 1), year = year}
end -- Easter

function Vars(line, source) -- Makes allowance for {Variables}
	local tbl = setmetatable({mname = MLabels(Time.show.month), year = Time.show.year, today = LZero(Time.curr.day), month = Time.show.month},
		{ __index = function(_, input)
			local D, W = {sun = 0, mon = 1, tue = 2, wed = 3, thu = 4, fri = 5, sat = 6}, {first = 0, second = 1, third = 2, fourth = 3, last = 4}
			local v1, v2 = input:match('(.+)(...)')
			if W[v1 or ''] and D[v2 or ''] then -- Variable day
				if v1 == 'last' then
					--local LastWeekDay = os.date('%w', os.time{month= Time.show.month, year = Time.show.year, day= Time.stats.clength, isdst=false,}) - D[v2]
					--return Time.stats.clength - LastWeekDay - (LastWeekDay < 0 and 7 or 0)
					local L = 36 + D[v2] - Time.stats.startday
					return L - math.ceil((L - Time.stats.clength) / 7) * 7
				else
					return rotate(D[v2]) + 1 - Time.stats.startday + (Time.stats.startday > rotate(D[v2]) and 7 or 0) + 7 * W[v1]
				end
			else -- Error
				return ErrMsg(0, 'Invalid Variable {%s} in %s', input, source)
			end
		end})
	-- Built in Events
	local SetVar = function(name, timestamp)
		local temp = os.date('*t', timestamp)
		tbl[name:lower() .. 'month'] = temp.month
		tbl[name:lower() .. 'day'] = temp.day
	end
	
	local sEaster, day = Easter(Time.show.year), 86400
	SetVar('easter', sEaster)
	SetVar('goodfriday', sEaster - 2 * day)
	SetVar('ashwednesday', sEaster - 46 * day)
	SetVar('mardigras', sEaster - 47 * day)

	return line:gsub('{%$([^}]+)}', function(variable) return tbl[variable:gsub('%s', ''):lower()] end)
end -- Vars

function rotate(value) -- Makes allowance for StartOnMonday
	return Settings.StartOnMonday and ((value - 1 + 7) % 7) or value
end -- rotate

function LZero(value) -- Makes allowance for LeadingZeros
	return Settings.LeadingZeroes and ('%02d'):format(value) or value
end -- LZero

function ErrMsg(...) -- Used to display errors
	local value = table.remove(arg, 1)
	local msg = string.format(unpack(arg))
	if not rMessage then
		rMessage = {msg}
	else
		table.insert(rMessage, msg)
	end
	return value
end -- ErrMsg

function ReturnError() -- Used to prevent duplicate error messages
	if rMessage then
		local temp = {}
		for k, v in ipairs(rMessage) do
			local count = 0
			for k2, v2 in ipairs(temp) do
				if v == v2 then count = count +1 end
			end
			if count == 0 then table.insert(temp, v) end
		end
		for k, v in ipairs(temp) do print(Settings.Name .. ': ' .. v) end
		Error, rMessage = rMessage[#rMessage], nil
		return Error
	else
		return Error or 'Success!'
	end
end -- ReturnError

function test(...) -- clone of assert
	local rvalue = table.remove(arg, 1)
	if not rvalue then
		ErrMsg(nil, unpack(arg))
	end
	return rvalue
end -- test