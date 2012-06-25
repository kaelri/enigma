PROPERTIES = {
	FeedMeasureName = '';
	MultipleFeeds = 0;
	VariablePrefix = '';
	MinItems = 0;
	SpecialFormat = '';
	FinishAction = '';
}

-- When Rainmeter supports escape characters for bangs, use this function to escape quotes.
function ParseSpecialCharacters(sString)
	sString = string.gsub(sString, '&nbsp;', ' ')
	sString = string.gsub(sString, '\"', '')
	return sString
end

function Initialize()
	sFeedMeasureName = PROPERTIES.FeedMeasureName
	iMultipleFeeds = tonumber(PROPERTIES.MultipleFeeds)
	sVariablePrefix = PROPERTIES.VariablePrefix
	iMinItems = tonumber(PROPERTIES.MinItems)
	sFinishAction = PROPERTIES.FinishAction
	sSpecialFormat = PROPERTIES.SpecialFormat
	tFeeds = {}
	tTitles = {}
	tLinks = {}
	tDates = {}
end

function Update()

	-----------------------------------------------------------------------
	-- INPUT FEED(S)
	
	if iMultipleFeeds == 1 then
		iNumberOfFeeds = tonumber(SKIN:GetVariable(sVariablePrefix..'NumberOfFeeds'))
		for i = 1, iNumberOfFeeds do
			tFeeds[i] = SKIN:GetVariable(sVariablePrefix..'FeedMeasureName'..i)
		end
		iCurrentFeed = tonumber(SKIN:GetVariable(sVariablePrefix..'CurrentFeed'))
		msRaw = SKIN:GetMeasure(tFeeds[iCurrentFeed])
	else
		msRaw = SKIN:GetMeasure(sFeedMeasureName)
	end
	sRaw = msRaw:GetStringValue()
	
	-----------------------------------------------------------------------
	-- DETERMINE FEED FORMAT AND CONTENTS
	
	sPatternFeedTitle = '.-<title.->(.-)</title>'
	sPatternItemTitle = '.-<title.->(.-)</title>'
	if string.match(sRaw, 'xmlns:gCal') then
		sRawCounted, iNumberOfItems = string.gsub(sRaw, '<entry', "")
		sPatternFeedLink = '.-<link.-rel=.-alternate.-href=\'(.-)\''
		sPatternItem = '<entry.-</entry>'
		sPatternItemLink = '.-<link.-href=\'(.-)\''
		sPatternItemDate = '.-When: (.-)<'
	elseif string.match(sRaw, '<subtitle>rememberthemilk.com</subtitle>') then
		sRawCounted, iNumberOfItems = string.gsub(sRaw, '<entry', "")
		sPatternFeedLink = '.-<link.-rel=.-alternate.-href="(.-)"'
		sPatternItem = '<entry.-</entry>'
		sPatternItemLink = '.-<link.-href="(.-)"'
		sPatternItemDate = '<span class="rtm_due_value">(.-)</span>'
	elseif string.match(sRaw, '<rss.-version=".-".->') then
		sRawCounted, iNumberOfItems = string.gsub(sRaw, '<item', "")
		sPatternFeedLink = '.-<link.->(.-)</link>'
		sPatternItem = '<item.-</item>'
		sPatternItemLink = '.-<link.->(.-)</link>'
		sPatternItemDesc = '.-<description.->(.-)</description>'
		sPatternItemDate = '.-<pubDate.->(.-)</pubDate>'
	else
		sRawCounted, iNumberOfItems = string.gsub(sRaw, '<entry', "")
		sPatternFeedLink = '.-<link.-href="(.-)"'
		sPatternItem = '<entry.-</entry>'
		sPatternItemLink = '.-<link.-href="(.-)"'
		sPatternItemDesc = '.-<summary.->(.-)</summary>'
		sPatternItemDate = '.-<updated.->(.-)</updated>'
	end
	
	-----------------------------------------------------------------------
	-- ERRORS
	
	sFeedTitle, sFeedLink = string.match(sRaw, sPatternFeedTitle..sPatternFeedLink)
	if not sFeedTitle then
		FeedError('Error', '', 'Connection or matching error.')
		return 'Error: matching.'
	end
	sFeedTitle = ParseSpecialCharacters(sFeedTitle)
	sFeedLink = ParseSpecialCharacters(sFeedLink)
	
	if iNumberOfItems == 0 then
		SKIN:Bang('!SetVariable "'..sVariablePrefix..'NumberOfItems" "0"')
		SKIN:Bang('!SetVariable "'..sVariablePrefix..'FeedTitle" "'..sFeedTitle..'"')
		SKIN:Bang('!SetVariable "'..sVariablePrefix..'FeedLink" "'..sFeedLink..'"')
		FeedError(sFeedTitle, '', 'Empty.')
		return 'Error: empty feed.'
	end
	
	-----------------------------------------------------------------------
	-- CREATE DATABASE
	
	iInit = 0
	for i = 1, iNumberOfItems do
		iItemStart, iItemEnd = string.find(sRaw, sPatternItem, iInit)
		sItem = string.sub(sRaw, iItemStart, iItemEnd)
		tTitles[i] = string.match(sItem, sPatternItemTitle)
		tTitles[i] = ParseSpecialCharacters(tTitles[i])
		tLinks[i] = string.match(sItem, sPatternItemLink)
		tLinks[i] = ParseSpecialCharacters(tLinks[i])
		if string.match(sItem, sPatternItemDate) then
			tDates[i] = string.match(sItem, sPatternItemDate)
			tDates[i] = ParseSpecialCharacters(tDates[i])
		else
			tDates[i] = ''
		end
		iInit = iItemEnd + 1
	end
	
	-----------------------------------------------------------------------
	-- OUTPUT
	
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'NumberOfItems" "'..iNumberOfItems..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'FeedTitle" "'..sFeedTitle..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'FeedLink" "'..sFeedLink..'"')

	for i = 1, iNumberOfItems do
		SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemTitle'..i..'" "'..tTitles[i]..'"')
		SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemLink'..i..'" "'..tLinks[i]..'"')
		SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemDate'..i..'" "'..tDates[i]..'"')
	end

	if  iMinItems > iNumberOfItems then
		iFirstMissingItem = iNumberOfItems + 1
		for i = iFirstMissingItem, iMinItems do
			SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemTitle'..i..'" ""')
			SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemLink'..i..'" ""')
			SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemDate'..i..'" ""')
		end
	end

	-----------------------------------------------------------------------
	-- FINISH ACTION
	
	if sFinishAction ~= '' then
		SKIN:Bang(sFinishAction)
	end
	
	return 'Success!'
end

---------------------------------------------------------------------
-- SWITCHERS

function SwitchToNext()
	iCurrentFeed = iCurrentFeed % iNumberOfFeeds + 1
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'CurrentFeed" "'..iCurrentFeed..'"')
	Update()
end

function SwitchToPrevious()
	iCurrentFeed = iCurrentFeed - 1 + (iCurrentFeed == 1 and iNumberOfFeeds or 0)
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'CurrentFeed" "'..iCurrentFeed..'"')
	Update()
end

function SwitchToFeed(a)
	SKIN:Bang('!SetVariable CurrentFeed '..a)
	SNum=0
	Update()
end

function FeedError(sErrorName, sErrorLink, sErrorDesc)
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'FeedTitle" "'..sErrorName..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'FeedLink" "'..sErrorLink..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemTitle1" "'..sErrorDesc..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemLink1" ""')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemDate1" ""')
	if  iMinItems > 1 then
		for i = 2, iMinItems do
			SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemTitle'..i..'" ""')
			SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemLink'..i..'" ""')
			SKIN:Bang('!SetVariable "'..sVariablePrefix..'ItemDate'..i..'" ""')
		end
	end
end