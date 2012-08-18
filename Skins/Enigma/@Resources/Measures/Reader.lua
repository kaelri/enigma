function Initialize(Feed)
	-- GET GENERAL OPTIONS
	VariablePrefix  = SELF:GetOption('VariablePrefix', '')
	MinItems        = SELF:GetNumberOption('MinItems', 0)
	TimestampFormat = SELF:GetOption('TimestampFormat', '%I.%M %p on %d %B %Y')
	Debug           = SELF:GetNumberOption('Debug', 0)

	Feeds = {}

	-- GET MEASURE NAMES
	local AllMeasureNames = SELF:GetOption('MeasureName', '')
	for MeasureName in string.gmatch(AllMeasureNames, '[^%|]+') do
		table.insert(Feeds, {
			Measure     = SKIN:GetMeasure(MeasureName),
			MeasureName = MeasureName,
			Raw         = nil,
			Type        = nil,
			Title       = nil,
			Link        = nil,
			Items       = nil,
			Error       = nil
			})
	end

	-- EVENT FILE MODULE
	Initialize_EventFile()

	-- SET STARTING FEED
	f = Feed or f or 1
end

function Update()
	-- INPUT WEBPARSER DATA
	-- Kept in a separate function so that measures can update "silently."
	Input()

	-- CHECK FOR INPUT ERRORS
	local e = Feeds[f]['Error']
	if e then
		OutputError(e)
		return e['Description']
	end

	-- OUTPUT
	SKIN:Bang('!SetVariable', VariablePrefix..'CurrentFeed',   f)
	SKIN:Bang('!SetVariable', VariablePrefix..'NumberOfItems', #Feeds[f]['Items'])
	SKIN:Bang('!SetVariable', VariablePrefix..'FeedTitle',     Feeds[f]['Title'])
	SKIN:Bang('!SetVariable', VariablePrefix..'FeedLink',      Feeds[f]['Link'])

	local t = Feeds[f]['Type']

	for i = 1, (MinItems > #Feeds[f]['Items'] and MinItems or #Feeds[f]['Items']) do
		local Item = Feeds[f]['Items'][i]
		for k, v in pairs{
			ItemTitle = Item['Title'] or '',
			ItemLink  = Item['Link']  or 'No item found.',
			ItemDate  = Item['Date']  and Types[t]['DateToString'](Item['Date']) or '',
		} do
			SKIN:Bang('!SetVariable', VariablePrefix..k..i, v)
		end
	end
	
	-- FINISH ACTION   
	local FinishAction = SELF:GetOption('FinishAction', '')
	if FinishAction ~= '' then
		SKIN:Bang(FinishAction)
	end

	return 'Finished #'..f..' ('..Feeds[f]['MeasureName']..'). Type: '..Feeds[f]['Type']..'. Items: '..#Feeds[f]['Items']..'.'
end

function Input(Feed)
	local f = Feed or f

	local Raw = Feeds[f]['Measure']:GetStringValue()

	if Raw == '' then
		Feeds[f]['Error'] = {
			Description = 'Waiting for data from WebParser.',
			Title       = 'Loading...',
			Link        = 'http://enigma.kaelri.com/support'
			}
		return false
	elseif Raw ~= Feeds[f]['Raw'] then
		Feeds[f]['Raw'] = Raw

		-- DETERMINE FEED FORMAT AND CONTENTS
		local t = IdentifyType(Raw)

		if not t then
			Feeds[f]['Error'] = {
				Description = 'Could not identify a valid feed format.',
				Title       = 'Invalid Feed Format',
				Link        = 'http://enigma.kaelri.com/support'
				}
			return false
		end

		Feeds[f]['Type'] = t

		-- CREATE DATABASE
		Feeds[f]['Title'] = string.match(Raw, '<title.->(.-)</title>')      or ''
		Feeds[f]['Link']  = string.match(Raw, Types[t]['Link'])             or ''

		-- Future versions will check for existing items in the database and add only
		-- newer items. For now, we simply recreate the table each time.
		Feeds[f]['Items'] = {}
		for Item in string.gmatch(Raw, Types[t]['Item']) do
			local ItemTitle = string.match(Item, '<title.->(.-)</title>' )  or ''
			local ItemLink  = string.match(Item, Types[t]['ItemLink'])      or ''
			local ItemDate  = string.match(Item, Types[t]['ItemDate'])      or ''
			local ItemDate  = Types[t]['DateToNumber'](ItemDate)
			table.insert(Feeds[f]['Items'], {
				Title = ItemTitle,
				Link  = ItemLink,
				Date  = ItemDate
				})
		end

		if #Feeds[f]['Items'] == 0 then
			Feeds[f]['Error'] = {
				Description = 'No items found.',
				Title       = Feeds[f]['Title'],
				Link        = Feeds[f]['Link']
			}
			return false
		end
		
		-- EVENT FILE MODULE
		Update_EventFile()
	end

	Feeds[f]['Error'] = nil
	return true
end

-----------------------------------------------------------------------
-- FORMAT FUNCTIONS

function IdentifyType(RawString)
	-- COLLAPSE CONTAINER TAGS
	for _, v in ipairs{ 'item', 'entry' } do
		RawString = string.gsub(RawString, '<'..v..'.->.+</'..v..'>', '<'..v..'></'..v..'>') -- e.g. '<entry.->.+</entry>' --> '<entry></entry>'
	end

	--DEFINE RSS MARKER TESTS
	--Each of these test functions will be run in turn, until one of them gets a solid match on the format type.
	local TestRSS = {
		function(a)
			-- If the feed contains these tags outside of <item> or <entry>, RSS is confirmed.
			for _, v in ipairs{ '<rss', '<channel', '<lastBuildDate', '<pubDate', '<ttl', '<description' } do
				if string.match(a, v) then
					return 'RSS'
				end
			end
			return false
		end,

		function(a)
			-- Alternatively, if the feed contains these tags outside of <item> or <entry>, Atom is confirmed.
			for _, v in ipairs{ '<feed', '<subtitle' } do
				if string.match(a, v) then
					return 'Atom'
				end
			end
			return false
		end,

		function(a)
			-- If no markers are present, we search for <item> or <entry> tags to confirm the type.
			local HaveItems   = string.match(a, '<item')
			local HaveEntries = string.match(a, '<entry')

			if HaveItems and not HaveEntries then
				return 'RSS'
			elseif HaveEntries and not HaveItems then
				return 'Atom'
			else
				-- If both kinds of tags are present, and no markers are given, then I give up because your feed is ridiculous.
				-- If neither tag is present, then no type can be confirmed.
				return false
			end
		end
		}

	-- RUN RSS MARKER TESTS
	local Class = false
	for _, v in ipairs(TestRSS) do
		Class = v(RawString)
		if Class then break end
	end

	-- DETECT SUBTYPE AND RETURN
	if Class == 'RSS' then
		return 'RSS'
	elseif Class == 'Atom' then
		if string.match(RawString, 'xmlns:gCal') then
			return 'GoogleCalendar'
		elseif string.match(RawString, '<subtitle>rememberthemilk.com</subtitle>') then
			return 'RememberTheMilk'
		else
			return 'Atom'
		end
	else
		return false
	end
end

function GoogleCalendar_DateToNumber(DateString)
	local year, month, day, hour, min, sec
	if string.match(DateString, 'T') then
		year, month, day, hour, min, sec = string.match(DateString, '(.+)%-(.+)%-(.+)T(.+):(.+):(.+)%.')
	else
		year, month, day = string.match(DateString, '(.+)%-(.+)%-(.+)')
		hour = 0
		min  = 0
		sec  = 0
	end
	return os.time{ year = year, month = month, day = day, hour = hour, min = min, sec = sec }
end

function NoChange(a)
	return a
end

-----------------------------------------------------------------------
-- EXTERNAL COMMANDS

function ShowNext()
	f = (f % #Feeds) + 1
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function ShowPrevious()
	f = (f == 1) and #Feeds or (f - 1)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function Show(a)
	f = tonumber(a)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function Refresh(a)
	a = a and tonumber(a) or f
	if a == f then
		SKIN:Bang('!UpdateMeasure', SELF:GetName())
	else
		Input(a)
	end
end

-----------------------------------------------------------------------
--ERRORS

function OutputError(e)
	for k, v in pairs{
		NumberOfItems = 0,
		FeedTitle     = e['Title'],
		FeedLink      = e['Link'],
		ItemTitle1    = e['Description'],
		ItemLink1     = e['Link'],
		ItemDate1     = ''
	} do
		SKIN:Bang('!SetVariable', VariablePrefix..k, v)
	end

	for i = 2, MinItems do
		SKIN:Bang('!SetVariable', VariablePrefix..'ItemTitle'..i, '')
		SKIN:Bang('!SetVariable', VariablePrefix..'ItemLink'..i,  '')
		SKIN:Bang('!SetVariable', VariablePrefix..'ItemDate'..i,  '')
	end

	if Debug == 1 then
		SKIN:Bang('!Log', 'Reader: '..e['Description'])
	end
end

-----------------------------------------------------------------------
-- EVENT FILE MODULE

function Initialize_EventFile()
	local WriteEvents = SELF:GetNumberOption('WriteEvents', 0)
	if WriteEvents == 1 then
		local i = 0
		local AllEventFiles = SELF:GetOption('EventFile')
		for EventFile in string.gmatch(SELF:GetOption('EventFile',''),'[^%|]+') do
			i = i + 1
			if Feeds[i] then 
				Feeds[i]['EventFile'] = EventFile
			end
		end
	end
end

function Update_EventFile()
	if (Feeds[f]['Type'] == 'GoogleCalendar') and Feeds[f]['EventFile'] then
		--CREATE XML TABLE
		local File = {}
		table.insert(File, '<EventFile Title="'..Feeds[f]['Title']..'">')
		for i, v in ipairs(Feeds[f]['Items']) do
			local ItemDate = os.date('*t', v['Date'])
			table.insert(File, '<Event Month="'..ItemDate['month']..'" Day="'..ItemDate['day']..'" Desc="'..v['Title']..'"/>')
		end
		table.insert(File, '</EventFile>')
		
		--WRITE FILE
		local hFile = io.output(Feeds[f]['EventFile'], 'w')
		if io.type(hFile) == 'file' then
			io.write(table.concat(File, '\r\n'))
			io.close(hFile)
		else
			SKIN:Bang('!Log', 'Reader: cannot open file: '..Feeds[f]['EventFile'])
		end
	end
end

-----------------------------------------------------------------------
-- CONSTANTS

-- DEFINE PATTERNS FOR PARSING AND FORMATTING DIFFERENT FEED TYPES
Types = {
	GoogleCalendar = {
		Link         = '<link.-rel=.-alternate.-href=["\'](.-)["\']',
		Item         = '<entry.-</entry>',
		ItemLink     = '<link.-href=["\'](.-)["\']',
		ItemDate     = 'startTime=["\'](.-)["\']',
		DateToNumber = GoogleCalendar_DateToNumber,
		DateToString = function(DateNumber) return os.date(TimestampFormat, DateNumber) end
		},
	RememberTheMilk = {
		Link         = '<link.-rel=.-alternate.-href=["\'](.-)["\']',
		Item         = '<entry.-</entry>',
		ItemLink     = '<link.-href=["\'](.-)["\']',
		ItemDate     = '<span class=["\']rtm_due_value["\']>(.-)</span>',
		DateToNumber = NoChange,
		DateToString = NoChange
		},
	RSS = {
		Link         = '<link.->(.-)</link>',
		Item         = '<item.-</item>',
		ItemLink     = '<link.->(.-)</link>',
		ItemDate     = '<pubDate.->(.-)</pubDate>',
		DateToNumber = NoChange,
		DateToString = NoChange
		},
	Atom = {
		Link         = '<link.-href=["\'](.-)["\']',
		Item         = '<entry.-</entry>',
		ItemLink     = '<link.-href=["\'](.-)["\']',
		ItemDate     = '<updated.->(.-)</updated>',
		DateToNumber = NoChange,
		DateToString = NoChange
		}
	}