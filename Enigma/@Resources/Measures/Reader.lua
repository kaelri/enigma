function Initialize()
	--GET GENERAL SETTINGS
	VariablePrefix = SELF:GetOption('VariablePrefix', '')
	MinItems = SELF:GetNumberOption('MinItems', 0)
	FinishAction = SELF:GetOption('FinishAction', '')
	SubString = SELF:GetOption('SubString', '')
	
	--DEFINE PATTERNS FOR IDENTIFYING AND PARSING FEED TYPES
	sPatternFeedType={
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
	
	--SET CURRENT FEED NUMBER
	iCurrentFeed=1
	
	--GET FEED MEASURES
	GetMeasures()
	
	--INITIALIZE GOOGLE CALENDAR MODULE
	GoogleCalendarFile('initialize')
end

function Update()
	-- COPY CURRENT FEED NUMBER TO SKIN
	SKIN:Bang('!SetVariable','CurrentFeed',iCurrentFeed)
	-- INPUT FEED
	sRaw=Substitute(Measures[iCurrentFeed]:GetStringValue(),SubString)
	-- DETERMINE FEED FORMAT AND CONTENTS
	FeedType=4
	for i=1,3 do if string.match(sRaw,sPatternFeedType[i]) then FeedType=i break end end
	-- CREATE DATABASE
	sFeedTitle,sFeedLink=string.match(sRaw,'.-<title.->(.-)</title>'..sPatternFeedLink[FeedType])
	tTitles,tLinks,tDates={},{},{}
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
	} do SKIN:Bang('!SetVariable',VariablePrefix..k,v) end
	for i=1,(MinItems>#tTitles and MinItems or #tTitles) do
		for k,v in pairs{
			ItemTitle=tTitles[i],
			ItemLink=tLinks[i] or 'No item found.',
			ItemDate=(FeedType==1 and tDates[i]~='') and os.date('%I.%M %p on %d %B %Y',GoogleCalendarTimestamp(tDates[i])) or tDates[i],
		} do SKIN:Bang('!SetVariable',VariablePrefix..k..i,v) end
	end
	
	-- RUN GOOGLE CALENDAR MODULE
	GoogleCalendarFile('write')
	
	-- FINISH ACTION   
	if FinishAction~='' then
		SKIN:Bang(FinishAction)
	end
	return 'Success!'
end

--HELPER FUNCTIONS
function GetMeasures()
	Measures={}
	for a in string.gmatch(SELF:GetOption('FeedMeasureName',''),'[^%|]+') do
		table.insert(Measures,SKIN:GetMeasure(a))
	end
end

function GoogleCalendarTimestamp(input, out)
	local year,month,day,hour,min,sec=string.match(input,  '(.+)%-(.+)%-(.+)T(.+):(.+):(.+)%.')
	return os.time{year=year, month=month, day=day, hour=hour, min=min, sec=sec, isdst=false}
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

--ERRORS
function FeedError(sErrorName,sErrorLink,sErrorDesc)
	for k,v in pairs{
		NumberOfItems='0';
		FeedTitle=sErrorName,
		FeedLink=sErrorLink,
		ItemTitle1=sErrorDesc,
		ItemLink1=sErrorLink,
		ItemDate1='',
	} do SKIN:Bang('!SetVariable',VariablePrefix..k,v) end
	for i=2,MinItems do
		SKIN:Bang('!SetVariable',VariablePrefix..'ItemTitle'..i,'')
		SKIN:Bang('!SetVariable',VariablePrefix..'ItemLink'..i,'')
		SKIN:Bang('!SetVariable',VariablePrefix..'ItemDate'..i,'')
	end
end

--SUBSTITUTES
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

--GOOGLE CALENDAR MODULE
function GoogleCalendarFile(Command)
	if SELF:GetNumberOption('WriteEvents',0) == 0 then
		return
	elseif Command == 'initialize' then
		LastUpdate={}
		EventFiles={}
		for a in string.gmatch(SELF:GetOption('EventFile',''),'[^%|]+') do
			table.insert(EventFiles,a)
		end
	elseif Command == 'write' and FeedType==1 and LastUpdate[iCurrentFeed]~=sRaw then
		--RESET LAST UPDATE IMAGE
		LastUpdate[iCurrentFeed]=sRaw
		
		--CREATE XML TABLE
		local file={}
		table.insert(file,'<EventFile Title="'..sFeedTitle..'">')
		for i=1,#tTitles do
			local ItemDate=os.date('*t',GoogleCalendarTimestamp(tDates[i]))
			table.insert(file,'<Event Month="'..ItemDate.month..'" Day="'..ItemDate.day..'" Desc="'..tTitles[i]..'"/>')
		end
		table.insert(file,'</EventFile>')
		
		--WRITE FILE
		local hFile=io.output(EventFiles[iCurrentFeed],'w')
		if io.type(hFile)=='file' then
			io.write(table.concat(file,'\n'))
			io.close(hFile)
		else
			print('Cannot open file: '..EventFiles[iCurrentFeed])
		end
	end
end