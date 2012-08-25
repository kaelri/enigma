function Initialize()
	-- SET UPDATE DIVIDER
	SKIN:Bang('!SetOption', SELF:GetName(), 'UpdateDivider', -1)
	-- This script should never update on a schedule. It should only update
	-- when it gets a "Refresh" command from WebParser.

	-- GET GENERAL OPTIONS
	TimestampFormat = SELF:GetOption('TimestampFormat', '%I.%M %p on %d %B %Y')

	-- CREATE MAIN DATABASE
	Feeds = {}

	-- CREATE TYPE MATCHING PATTERNS AND FORMATTING FUNCTIONS
	DefineTypes()

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
			Error       = nil
			})
	end

	-- EVENT FILE MODULE
	Initialize_EventFile()

	-- SET STARTING FEED
	f = f or 1
end

function Update()
	Input()
	return Output()
end

-----------------------------------------------------------------------
-- INPUT

function Input(a)
	local f = a or f

	local Raw = Feeds[f].Measure:GetStringValue()

	if Raw == '' then
		Feeds[f].Error = {
			Description = 'Waiting for data from WebParser.',
			Title       = 'Loading...',
			Link        = 'http://enigma.kaelri.com/support'
			}
		return false
	elseif Raw ~= Feeds[f].Raw then
		Feeds[f].Raw = Raw

		-- DETERMINE FEED FORMAT AND CONTENTS
		local t = IdentifyType(Raw)

		if not t then
			Feeds[f].Error = {
				Description = 'Could not identify a valid feed format.',
				Title       = 'Invalid Feed Format',
				Link        = 'http://enigma.kaelri.com/support'
				}
			return false
		else
			Feeds[f].Type = t
		end

		-- MAKE SYNTAX PRETTIER
		local Type = Types[t]

		-- CREATE DATABASE
		Feeds[f].Title = string.match(Raw, '<title.->(.-)</title>') or 'Untitled'
		Feeds[f].Link  = string.match(Raw, Type.MatchLink)          or nil

		for i in ipairs(Feeds[f]) do
			table.remove(Feeds[f], i)
		end
		-- Future versions will check for existing items in the database and add only
		-- newer items. For now, we simply recreate the table from scratch each time.

		for Item in string.gmatch(Raw, Type.MatchItem) do
			local ItemTitle = string.match(Item, '<title.->(.-)</title>' ) or 'Untitled'
			local ItemLink  = string.match(Item, Type.MatchItemLink)       or nil
			local ItemDate  = string.match(Item, Type.MatchItemDate)       or nil
			local ItemDate  = Type.DateToNumber(ItemDate)
			table.insert(Feeds[f], {
				Title = ItemTitle,
				Link  = ItemLink,
				Date  = ItemDate
				})
		end

		if #Feeds[f] == 0 then
			Feeds[f].Error = {
				Description = 'No items found.',
				Title       = Feeds[f]['Title'],
				Link        = Feeds[f]['Link']
			}
			return false
		end
		
		-- EVENT FILE MODULE
		Update_EventFile()

		-- CLEAR ERRORS FROM PREVIOUS UPDATE
		Feeds[f].Error = nil
	end

	return true
end

-----------------------------------------------------------------------
-- OUTPUT

function Output()
	local Queue = {}

	-- MAKE SYNTAX PRETTIER
	local Feed  = Feeds[f]
	local Type  = Types[Feed.Type]
	local Error = Feed.Error

	-- BUILD QUEUE
	Queue['CurrentFeed']   = f
	Queue['NumberOfItems'] = #Feed

	-- CHECK FOR INPUT ERRORS
	local MinItems = SELF:GetNumberOption('MinItems', 0)

	if Error then
		-- ERROR; QUEUE MESSAGES
		Queue['FeedTitle']  = Error.Title
		Queue['FeedLink']   = Error.Link
		Queue['ItemTitle1'] = Error.Description
		Queue['ItemLink1']  = Error.Link

		for i = 2, MinItems do
			Queue['ItemTitle'..i] = ''
			Queue['ItemLink'..i]  = ''
			Queue['ItemDate'..i]  = ''
		end
	else
		-- NO ERROR; QUEUE FEED
		Queue['FeedTitle'] = Feed.Title
		Queue['FeedLink']  = Feed.Link or ''

		for i = 1, math.max(#Feed, MinItems) do
			Queue['ItemTitle'..i] = Feed[i].Title or ''
			Queue['ItemLink'..i]  = Feed[i].Link  or ''
			Queue['ItemDate'..i]  = Feed[i].Date  or ''
			Queue['ItemDate'..i]  = Type.DateToString(Queue['ItemDate'..i])
		end
	end

	-- SET VARIABLES
	VariablePrefix = SELF:GetOption('VariablePrefix', '')
	for k, v in pairs(Queue) do
		SKIN:Bang('!SetVariable', VariablePrefix..k, v)
	end
	
	-- FINISH ACTION   
	local FinishAction = SELF:GetOption('FinishAction', '')
	if FinishAction ~= '' then
		SKIN:Bang(FinishAction)
	end

	return Error and Error.Description or 'Finished #'..f..' ('..Feed.MeasureName..'). Type: '..Feed.Type..'. Items: '..#Feed..'.'
end

-----------------------------------------------------------------------
-- TYPES

function DefineTypes()
	Types = {
		GoogleCalendar = {
			MatchLink     = '<link.-rel=.-alternate.-href=["\'](.-)["\']',
			MatchItem     = '<entry.-</entry>',
			MatchItemLink = '<link.-href=["\'](.-)["\']',
			MatchItemDate = 'startTime=["\'](.-)["\']',
			DateToNumber  = GoogleCalendar_DateToNumber,
			DateToString  = function(n) return os.date(TimestampFormat, n) end
			},
		RememberTheMilk = {
			MatchLink     = '<link.-rel=.-alternate.-href=["\'](.-)["\']',
			MatchItem     = '<entry.-</entry>',
			MatchItemLink = '<link.-href=["\'](.-)["\']',
			MatchItemDate = '<span class=["\']rtm_due_value["\']>(.-)</span>',
			DateToNumber  = NoChange,
			DateToString  = NoChange
			},
		RSS = {
			MatchLink     = '<link.->(.-)</link>',
			MatchItem     = '<item.-</item>',
			MatchItemLink = '<link.->(.-)</link>',
			MatchItemDate = '<pubDate.->(.-)</pubDate>',
			DateToNumber  = NoChange,
			DateToString  = NoChange
			},
		Atom = {
			MatchLink     = '<link.-href=["\'](.-)["\']',
			MatchItem     = '<entry.-</entry>',
			MatchItemLink = '<link.-href=["\'](.-)["\']',
			MatchItemDate = '<updated.->(.-)</updated>',
			DateToNumber  = NoChange,
			DateToString  = NoChange
			}
		}
end

function GoogleCalendar_DateToNumber(s)
	local year, month, day, hour, min, sec
	local MatchTime = '(.+)%-(.+)%-(.+)T(.+):(.+):(.+)%.'
	local MatchDate = '(.+)%-(.+)%-(.+)'

	if string.match(s, MatchTime) then
		year, month, day, hour, min, sec = string.match(s, MatchTime)
		return os.time{ year = year, month = month, day = day, hour = hour, min = min, sec = sec }
	elseif string.match(s, MatchDate) then
		year, month, day = string.match(s, MatchDate)
		hour, min, sec = 0, 0, 0
		return os.time{ year = year, month = month, day = day, hour = hour, min = min, sec = sec }
	else
		return os.time()
	end
end

function NoChange(a)
	return a
end

-------------------------

function IdentifyType(s)
	-- COLLAPSE CONTAINER TAGS
	for _, v in ipairs{ 'item', 'entry' } do
		s = string.gsub(s, '<'..v..'.->.+</'..v..'>', '<'..v..'></'..v..'>') -- e.g. '<entry.->.+</entry>' --> '<entry></entry>'
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
		Class = v(s)
		if Class then break end
	end

	-- DETECT SUBTYPE AND RETURN
	if Class == 'RSS' then
		return 'RSS'
	elseif Class == 'Atom' then
		if string.match(s, 'xmlns:gCal') then
			return 'GoogleCalendar'
		elseif string.match(s, '<subtitle>rememberthemilk.com</subtitle>') then
			return 'RememberTheMilk'
		else
			return 'Atom'
		end
	else
		return false
	end
end

-----------------------------------------------------------------------
-- EXTERNAL COMMANDS

function Refresh(a)
	a = a and tonumber(a) or f
	if a == f then
		SKIN:Bang('!UpdateMeasure', SELF:GetName())
	else
		Input(a)
	end
end

function Show(a)
	f = tonumber(a)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function ShowNext()
	f = (f % #Feeds) + 1
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function ShowPrevious()
	f = (f == 1) and #Feeds or (f - 1)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
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
				Feeds[i]['EventFile'] = SKIN:MakePathAbsolute(EventFile)
			end
		end
	end
end

function Update_EventFile()
	if Feeds[f]['EventFile'] and (Feeds[f]['Type'] == 'GoogleCalendar') then
		--CREATE XML TABLE
		local File = {}
		table.insert(File, '<EventFile Title="'..Feeds[f]['Title']..'">')
		for i, v in ipairs(Feeds[f]) do
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