function Initialize()
	-- SET UPDATE DIVIDER
	SKIN:Bang('!SetOption', SELF:GetName(), 'UpdateDivider', -1)
	-- This script never needs to update on a schedule. It should only
	-- update when it gets a "Refresh" command from WebParser.

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

	-- MODULES
	EventFile_Initialize()
	HistoryFile_Initialize()

	-- SET STARTING FEED
	f = f or 1

	-- SET USER INPUT
	UserInput = false
	-- Used to detect when an item has been marked as read.
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
	elseif (Raw ~= Feeds[f].Raw) or UserInput then
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

		-- GET NEW DATA
		Feeds[f].Title = string.match(Raw, '<title.->(.-)</title>') or 'Untitled'
		Feeds[f].Link  = string.match(Raw, Type.MatchLink)          or nil

		local Items = {}
		for Item in string.gmatch(Raw, Type.MatchItem) do
			-- CHECK EXISTENCE
			local Title = string.match(Item, '<title.->(.-)</title>' ) or 'Untitled'
			local Link  = string.match(Item, Type.MatchItemLink)       or nil
			local ID    = string.match(Item, Type.MatchItemID)         or Link or Title
			local Desc  = string.match(Item, Type.MatchItemDesc)       or nil
			local Date  = string.match(Item, Type.MatchItemDate)       or nil

			-- ADDITIONAL PROCESSING
			local Desc  = Desc and string.gsub(Desc, '<.->',       '') or nil
			local Desc  = Desc and string.gsub(Desc, '&lt;.-&gt;', '') or nil
			local Date  = Date and Type.DateToNumber(Date)             or nil

			table.insert(Items, {
				ID      = ID,
				Title   = Title,
				Link    = Link,
				Desc    = Desc,
				Date    = Date,
				Unread  = 1
				})
		end

		-- IDENTIFY DUPLICATES
		-- If any new item matches an old item, sync the "unread" value and
		-- mark the old item as a duplicate.
		for i, OldItem in ipairs(Feeds[f]) do
			for j, NewItem in ipairs(Items) do
				if NewItem.ID == OldItem.ID then
					Items[j].Unread = OldItem.Unread
					Feeds[f][i].Match = j
				end
			end
		end

		-- CLEAR DUPLICATES OR ALL HISTORY
		local KeepOldItems = SELF:GetNumberOption('KeepOldItems', 0)

		if (KeepOldItems == 1) and Type.MergeItems then
			for i = #Feeds[f], 1, -1 do
				if Feeds[f][i].Match then
					table.remove(Feeds[f], i)
				end
			end
		else
			for i = 1, #Feeds[f] do
				table.remove(Feeds[f])
			end
		end

		-- ADD NEW ITEMS
		for i = #Items, 1, -1 do
			if Items[i] then
				table.insert(Feeds[f], 1, Items[i])
			end
		end

		-- CHECK NUMBER OF ITEMS
		local MaxItems = SELF:GetNumberOption('MaxItems', nil)
		local MaxItems = (MaxItems > 0) and MaxItems or nil

		if #Feeds[f] == 0 then
			Feeds[f].Error = {
				Description = 'No items found.',
				Title       = Feeds[f]['Title'],
				Link        = Feeds[f]['Link']
			}
			return false
		elseif MaxItems and (#Feeds[f] > MaxItems) then
			for i = #Feeds[f], (MaxItems + 1), -1 do
				table.remove(Feeds[f])
			end
		end
		
		-- MODULES
		EventFile_Update(f)
		HistoryFile_Update(f)

		-- CLEAR ERRORS FROM PREVIOUS UPDATE
		Feeds[f].Error = nil

		-- RESET USER INPUT
		UserInput = false
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
	local MinItems  = SELF:GetNumberOption('MinItems', 0)
	local Timestamp = SELF:GetOption('Timestamp', '%I.%M %p on %d %B %Y')

	if Error then
		-- ERROR; QUEUE MESSAGES
		Queue['FeedTitle']   = Error.Title
		Queue['FeedLink']    = Error.Link
		Queue['Item1Title']  = Error.Description
		Queue['Item1Link']   = Error.Link
		Queue['Item1Desc']   = ''
		Queue['Item1Date']   = ''
		Queue['Item1Unread'] = 0

		for i = 2, MinItems do
			Queue['Item'..i..'Title']   = ''
			Queue['Item'..i..'Link']    = ''
			Queue['Item'..i..'Desc']    = ''
			Queue['Item'..i..'Date']    = ''
			Queue['Item'..i..'Unread']  = 0
		end
	else
		-- NO ERROR; QUEUE FEED
		Queue['FeedTitle'] = Feed.Title
		Queue['FeedLink']  = Feed.Link or ''

		for i = 1, math.max(#Feed, MinItems) do
			local Item = Feed[i] or {}			
			Queue['Item'..i..'Title']   = Item.Title   or ''
			Queue['Item'..i..'Link']    = Item.Link    or Feed.Link or ''
			Queue['Item'..i..'Desc']    = Item.Desc    or ''
			Queue['Item'..i..'Date']    = Item.Date    or ''
			Queue['Item'..i..'Date']    = Type.DateToString(Queue['Item'..i..'Date'], Timestamp)
			Queue['Item'..i..'Unread']  = Item.Unread  or ''
		end
	end

	-- SET VARIABLES
	local VariablePrefix = SELF:GetOption('VariablePrefix', '')
	for k, v in pairs(Queue) do
		SKIN:Bang('!SetVariable', VariablePrefix..k, v)
	end
	
	-- FINISH ACTION   
	local FinishAction = SELF:GetOption('FinishAction', '')
	if FinishAction ~= '' then
		SKIN:Bang(FinishAction)
	end

	return Error and Error.Description or 'Finished #'..f..' ('..Feed.MeasureName..'). Name: '..Feed.Title..'. Type: '..Feed.Type..'. Items: '..#Feed..'.'
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

function MarkRead(a, b)
	b = b and tonumber(b) or f
	Feeds[b][a].Unread = 0
	UserInput = true
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function MarkUnread(a, b)
	b = b and tonumber(b) or f
	Feeds[b][a].Unread = 1
	UserInput = true
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function ToggleUnread(a, b)
	b = b and tonumber(b) or f
	Feeds[b][a].Unread = 1 - Feeds[b][a].Unread
	UserInput = true
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

-----------------------------------------------------------------------
-- TYPES

function DefineTypes()
	Types = {
		RSS = {
			MatchLink     = '<link.->(.-)</link>',
			MatchItem     = '<item.-</item>',
			MatchItemID   = '<guid.->(.-)</guid>',
			MatchItemLink = '<link.->(.-)</link>',
			MatchItemDesc = '<description.->(.-)</description>',
			MatchItemDate = '<pubDate.->(.-)</pubDate>',
			DateToNumber  = NoChange,
			DateToString  = NoChange,
			MergeItems    = true
			},
		Atom = {
			MatchLink     = '<link.-href=["\'](.-)["\']',
			MatchItem     = '<entry.-</entry>',
			MatchItemID   = '<id.->(.-)</id>',
			MatchItemLink = '<link.-href=["\'](.-)["\']',
			MatchItemDesc = '<summary.->(.-)</summary>',
			MatchItemDate = '<updated.->(.-)</updated>',
			DateToNumber  = NoChange,
			DateToString  = NoChange,
			MergeItems    = true
			},
		GoogleCalendar = {
			MatchLink     = '<link.-rel=.-alternate.-href=["\'](.-)["\']',
			MatchItem     = '<entry.-</entry>',
			MatchItemID   = '<id.->(.-)</id>',
			MatchItemLink = '<link.-href=["\'](.-)["\']',
			MatchItemDate = 'startTime=["\'](.-)["\']',
			DateToNumber  = GoogleCalendar_DateToNumber,
			DateToString  = function(n, Format) return os.date(Format, n) end,
			MergeItems    = false
			},
		RememberTheMilk = {
			MatchLink     = '<link.-rel=.-alternate.-href=["\'](.-)["\']',
			MatchItem     = '<entry.-</entry>',
			MatchItemID   = '<id.->(.-)</id>',
			MatchItemLink = '<link.-href=["\'](.-)["\']',
			MatchItemDesc = '<summary.->(.-)</summary>',
			MatchItemDate = '<span class=["\']rtm_due_value["\']>(.-)</span>',
			DateToNumber  = NoChange,
			DateToString  = NoChange,
			MergeItems    = false
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
				-- If both kinds of tags are present, and no markers are given, then I give up
				-- because your feed is ridiculous. And if neither tag is present, then no type
				-- can be confirmed (and there would be no usable data anyway).
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
-- EVENT FILE MODULE

function EventFile_Initialize()
	local EventFiles = {}
	local AllEventFiles = SELF:GetOption('EventFile', '')
	for EventFile in string.gmatch(AllEventFiles, '[^%|]+') do
		table.insert(EventFiles, EventFile)
	end
	for i, v in ipairs(Feeds) do
		local EventFile = EventFiles[i] or SELF:GetName()..'_Feed'..i..'Events.xml'
		Feeds[i].EventFile = SKIN:MakePathAbsolute(EventFile)
	end
end

function EventFile_Update(a)
	local f = a or f

	local WriteEvents = SELF:GetNumberOption('WriteEvents', 0)
	if (WriteEvents == 1) and (Feeds[f].Type == 'GoogleCalendar') then
		-- CREATE XML TABLE
		local WriteLines = {}
		table.insert(WriteLines, '<EventFile Title="'..Feeds[f].Title..'">')
		for i, v in ipairs(Feeds[f]) do
			local ItemDate = os.date('*t', v.Date)
			table.insert(WriteLines, '<Event Month="'..ItemDate['month']..'" Day="'..ItemDate['day']..'" Desc="'..v.Title..'"/>')
		end
		table.insert(WriteLines, '</EventFile>')
		
		-- WRITE FILE
		local WriteFile = io.output(Feeds[f].EventFile, 'w')
		if WriteFile then
			local WriteContent = table.concat(WriteLines, '\r\n')
			WriteFile:write(WriteContent)
			WriteFile:close()
		else
			SKIN:Bang('!Log', SELF:GetName()..': cannot open file: '..Feeds[f].EventFile)
		end
	end
end

-----------------------------------------------------------------------
-- HISTORY FILE MODULE

function HistoryFile_Initialize()
	-- DETERMINE FILEPATH
	HistoryFile = SELF:GetOption('HistoryFile', SELF:GetName()..'History.xml')
	HistoryFile = SKIN:MakePathAbsolute(HistoryFile)

	-- CREATE HISTORY DATABASE
	History = {}

	-- CHECK IF FILE EXISTS
	local ReadFile = io.open(HistoryFile)
	if ReadFile then
		local ReadContent = ReadFile:read('*all')
		ReadFile:close()

		-- PARSE HISTORY FROM LAST SESSION
		for ReadFeedURL, ReadFeed in string.gmatch(ReadContent, '<feed URL=(%b"")>(.-)</feed>') do
			local ReadFeedURL = string.match(ReadFeedURL, '^"(.-)"$')
			History[ReadFeedURL] = {}
			for ReadItem in string.gmatch(ReadFeed, '<item(.-)/>') do
				local Keys = {}
				for k,v in string.gmatch(ReadItem, '(%w+)=(%b"")') do
					local strip = string.match(v, '^"(.-)"$"')
					Keys[k] = string.gsub(strip, '&quot;', '"')
				end
				Keys.Date = tonumber(Keys.Date) or Keys.Date
				Keys.Unread = tonumber(Keys.Unread)
				table.insert(History[ReadFeedURL], Keys)
			end
		end
	end

	-- ADD HISTORY TO MAIN DATABASE
	-- For each feed, if URLs match, add all contents from History[h] to Feeds[f].
	for f, Feed in ipairs(Feeds) do
		local h = Feed.Measure:GetOption('URL')
		Feeds[f].URL = h
		if History[h] then
			for _, Item in ipairs(History[h]) do
				table.insert(Feeds[f], Item)
			end
		end
	end
end

function HistoryFile_Update(a)
	local f = a or f

	local WriteHistory = SELF:GetNumberOption('WriteHistory', 0)
	if WriteHistory == 1 then
		-- CLEAR AND REBUILD FEED HISTORY
		local h = Feeds[f].URL
		History[h] = {}
		for i, Item in ipairs(Feeds[f]) do
			table.insert(History[h], Item)
		end

		-- GENERATE XML TABLE
		local WriteLines = {}
		for WriteURL, WriteFeed in pairs(History) do
			table.insert(WriteLines,                  '<feed URL="'..WriteURL..'">')
			for _, WriteItem in ipairs(WriteFeed) do
				local line = {}
				for k, v in pairs(WriteItem) do
					local escape = string.gsub(v, '"', '&quot;')
					local item = string.format('%s=%q', k, escape)
					table.insert(line, item)
				end
				table.insert(WriteLines, '\t<item '..table.concat(line, ' ')..'/>')
			end
			table.insert(WriteLines,                  '</feed>')
		end

		-- WRITE XML TO FILE
		local WriteFile = io.open(HistoryFile, 'w')
		if WriteFile then
			local WriteContent = table.concat(WriteLines, '\n')
			WriteFile:write(WriteContent)
			WriteFile:close()
		else
			SKIN:Bang('!Log', SELF:GetName()..': cannot open file: '..HistoryFile)
		end
	end
end

function ClearHistory()
	local DeleteFile = io.open(HistoryFile)
	if DeleteFile then
		DeleteFile:close()
		os.remove(HistoryFile)
		SKIN:Bang('!Log', SELF:GetName()..': deleted history cache at '..HistoryFile)
	end
	SKIN:Bang('!Refresh')
end