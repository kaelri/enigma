function Initialize()
	-- GET GENERAL SETTINGS
	VariablePrefix  = SELF:GetOption('VariablePrefix',  ''                    )
	MinItems        = SELF:GetNumberOption('MinItems',  0                     )
	TimestampFormat = SELF:GetOption('TimestampFormat', '%I.%M %p on %d %B %Y')
	
	-- DEFINE PATTERNS FOR IDENTIFYING AND PARSING DIFFERENT FEED TYPES
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
	
	-- GET FEED MEASURES
	GetMeasures = function()
		AllMeasureNames = SELF:GetOption('FeedMeasureName', '')

		Feeds = {}

		for MeasureName in string.gmatch(AllMeasureNames, '[^%|]+') do
			table.insert(Feeds, {
				Measure     = SKIN:GetMeasure(MeasureName),
				MeasureName = MeasureName,
				Raw         = nil,
				Type        = nil,
				Title       = nil,
				Link        = nil,
				Items       = {}
				})
		end
	end
	GetMeasures()

	-- START ON FEED 1
	f = 1
	
	-- INITIALIZE GOOGLE CALENDAR MODULE
	EventFile('Initialize')
end

function Update()
	-- COPY CURRENT FEED NUMBER TO SKIN
	SKIN:Bang('!SetVariable', 'CurrentFeed', f)

	-- GET DATA
	local Raw = Feeds[f]['Measure']:GetStringValue()

	if Raw == '' then
		return 'Waiting for WebParser...'
	elseif Raw ~= Feeds[f]['Raw'] then
		Feeds[f]['Raw'] = Raw

		-- DETERMINE FEED FORMAT AND CONTENTS
		local t = IdentifyType(Raw)

		if not t then
			local ErrorDescription = 'Could not identify a valid feed format.'
			Error('Invalid Feed Format', 'http://enigma.kaelri.com/support', ErrorDescription)
			return ErrorDescription
		end

		Feeds[f]['Type'] = t

		-- CREATE DATABASE
		Feeds[f]['Title'] = string.match(Raw, '<title.->(.-)</title>')      or ''
		Feeds[f]['Link']  = string.match(Raw, Types[t]['Link'])             or ''
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
			local ErrorDescription = 'No items found.'
			Error(Feeds[f]['Title'], Feeds[f]['Link'], ErrorDescription)
			return ErrorDescription
		end
		
		-- WRITE TO EVENT FILE
		EventFile('Update')
	end

	-- OUTPUT
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

-- HELPER FUNCTIONS
function NoChange(a)
	return a
end

function GoogleCalendar_DateToNumber(DateString)
	local year, month, day, hour, min, sec
	if string.match(DateString, 'T') then
		year, month, day, hour, min, sec = string.match(DateString, '(.+)%-(.+)%-(.+)T(.+):(.+):(.+)%.')
	else
		year, month, day = string.match(input, '(.+)%-(.+)%-(.+)')
		hour = 0
		min  = 0
		sec  = 0
	end
	return os.time{ year = year, month = month, day = day, hour = hour, min = min, sec = sec }
end

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

-- SWITCHERS
function SwitchToNext()
	f = (f % #Feeds) + 1
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function SwitchToPrevious()
	f = (f == 1) and #Feeds or (f - 1)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function SwitchTo(a)
	f = tonumber(a)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

--ERRORS
function Error(ErrorName, ErrorLink, ErrorDescription)
	for k, v in pairs{
		NumberOfItems = 0;
		FeedTitle     = ErrorName,
		FeedLink      = ErrorLink,
		ItemTitle1    = ErrorDescription,
		ItemLink1     = ErrorLink,
		ItemDate1     = '',
	} do
		SKIN:Bang('!SetVariable', VariablePrefix..k, v)
	end

	for i = 2, MinItems do
		SKIN:Bang('!SetVariable', VariablePrefix..'ItemTitle'..i, '')
		SKIN:Bang('!SetVariable', VariablePrefix..'ItemLink'..i,  '')
		SKIN:Bang('!SetVariable', VariablePrefix..'ItemDate'..i,  '')
	end

	SKIN:Bang('!Log', 'Reader: '..ErrorDescription)
end

--EVENT FILE MODULE
function EventFile(Command)
	if SELF:GetNumberOption('WriteEvents', 0) == 0 then
		return
	elseif Command == 'Initialize' then
		local i = 0
		for Filepath in string.gmatch(SELF:GetOption('EventFile',''),'[^%|]+') do
			i = i + 1
			if Feeds[i] then 
				Feeds[i]['EventFile'] = Filepath
			end
		end
	elseif (Command == 'Update') and (Feeds[f]['Type'] == 'GoogleCalendar') and Feeds[f]['EventFile'] then
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