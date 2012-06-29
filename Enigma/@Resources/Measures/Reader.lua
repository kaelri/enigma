function Initialize()
	Set={
		vPrefix=SELF:GetOption('VariablePrefix',''),
		mItems=SELF:GetNumberOption('MinItems',0),
		Finish=SELF:GetOption('FinishAction',''),
		Sub=SELF:GetOption('Sub'),
		}
	Matches={
		'xmlns:gCal',
		'<subtitle>rememberthemilk.com</subtitle>',
		'<rss.-version=".-".->',
		}
	sPatternFeedLink={
		'.-<link.-rel=.-alternate.-href=\'(.-)\'',
		'.-<link.-rel=.-alternate.-href="(.-)"',
		'.-<link.->(.-)</link>',
		'.-<link.-href="(.-)"',
		}
	sPatternItem={
		'<entry.-</entry>',
		'<entry.-</entry>',
		'<item.-</item>',
		'<entry.-</entry>',
		}
	sPatternItemLink={
		'.-<link.-href=\'(.-)\'',
		'.-<link.-href="(.-)"',
		'.-<link.->(.-)</link>',
		'.-<link.-href="(.-)"',
		}
	sPatternItemDate={
		'.-startTime=\'(.-)\'',
		'<span class="rtm_due_value">(.-)</span>',
		'.-<pubDate.->(.-)</pubDate>',
		'.-<updated.->(.-)</updated>',
		}
	iCurrentFeed=1
	Measures={}
	for a in string.gmatch(SELF:GetOption('FeedMeasureName',''),'[^%|]+') do
		table.insert(Measures,SKIN:GetMeasure(a))
	end
	SKIN:Bang('!SetVariable','NumberOfFeeds',#Measures)
end

function Update()
	SKIN:Bang('!SetVariable','CurrentFeed',iCurrentFeed)
	tTitles,tLinks,tDates={},{},{}
	-- INPUT FEED
	sRaw=Substitute(Measures[iCurrentFeed]:GetStringValue(),Set.Sub)
	-- DETERMINE FEED FORMAT AND CONTENTS
	FeedType=4
	for i=1,3 do if string.match(sRaw,Matches[i]) then FeedType=i break end end
	-- CREATE DATABASE
	sFeedTitle,sFeedLink=string.match(sRaw,'.-<title.->(.-)</title>'..sPatternFeedLink[FeedType])
	for sItem in string.gmatch(sRaw,sPatternItem[FeedType]) do
		table.insert(tTitles,string.match(sItem,'.-<title.->(.-)</title>'))
		table.insert(tLinks,string.match(sItem,sPatternItemLink[FeedType]))
		table.insert(tDates,string.match(sItem,sPatternItemDate[FeedType]) or '')
	end
	-- ERRORS
	if not sFeedTitle then
		FeedError('Matching Error','','No valid feed was found.')
		return 'Error: matching.'
	elseif #tTitles==0 then
		FeedError(sFeedTitle,sFeedLink,'Empty.')
		return 'Error: empty feed.'
	end
	-- OUTPUT
	for k,v in pairs{
		NumberOfItems=#tTitles,
		FeedTitle=sFeedTitle,
		FeedLink=sFeedLink,
	} do SKIN:Bang('!SetVariable',Set.vPrefix..k,v) end
	for i=1,(Set.mItems>#tTitles and Set.mItems or #tTitles) do
		for k,v in pairs{
			ItemTitle=tTitles[i],
			ItemLink=tLinks[i] or 'No item found.',
			ItemDate=FeedType==1 and TimeStamp(string.match(tDates[i], '(.+)%-(.+)%-(.+)T(.+):(.+):(.+)%.(.+)Z')) or tDates[i],
		} do SKIN:Bang('!SetVariable',Set.vPrefix..k..i,v) end
	end
	-- FINISH ACTION   
	if Set.Finish~='' then SKIN:Bang(Set.Finish) end
	return 'Success!'
end

function TimeStamp(year, month, day, hour, min, sec, zone)
	return os.date('%I.%M %p on %d %B %Y', os.time{year=year, month=month, day=day, hour=hour, min=min, sec=sec, isdst=false})
end

-- SWITCHERS
function SwitchToNext()
	iCurrentFeed=iCurrentFeed%#Measures+1
	Update()
end

function SwitchToPrevious()
	iCurrentFeed=iCurrentFeed==1 and #Measures or iCurrentFeed-1
	Update()
end

function SwitchTo(a)
	iCurrentFeed=tonumber(a)
	Update()
end

function FeedError(sErrorName,sErrorLink,sErrorDesc)
	for k,v in pairs{
		NumberOfItems='0';
		FeedTitle=sErrorName,
		FeedLink=sErrorLink,
		ItemTitle1=sErrorDesc,
		ItemLink1=sErrorLink,
		ItemDate1='',
	} do SKIN:Bang('!SetVariable',Set.vPrefix..k,v) end
	for i=2,Set.mItems do
		SKIN:Bang('!SetVariable',Set.vPrefix..'ItemTitle'..i,'')
		SKIN:Bang('!SetVariable',Set.vPrefix..'ItemLink'..i,'')
		SKIN:Bang('!SetVariable',Set.vPrefix..'ItemDate'..i,'')
	end
end

function Substitute(Val,Sub)
	if Sub and Sub~='' then
		Val=tostring(Val)
		Sub='"'..string.gsub(Sub,'%[','%%%[')..'"'
		local Strip=function(a) return string.match(a or '','^[\'"](.*)[\'"]$') or '' end
		for a in string.gmatch(Sub,'[^,]+') do
			local l,r=string.match(a,'(.+):(.+)')
			Val=string.gsub(Val,Strip(l),Strip(r))
		end
	end
	return Val
end