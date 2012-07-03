function Initialize()
	sRange = string.lower(SELF:GetOption('Range','month'))
	iStartOnMondays = SELF:GetNumberOption('StartOnMonday',0)>0
	iLeadingZeroes = SELF:GetNumberOption('LeadingZeroes',0)>0
	iEDaysColor ='StyleCalendarText'..(SELF:GetNumberOption('ExtraDays')>0 and 'Extra' or 'Invisible')
	
	Error=false
	
	iRange = {month=42,week=7}
	if not iRange[sRange] then sRange='month' end
	tCurrMonth = {31,28,31,30,31,30,31,31,30,31,30,31}
	iDayOnLastUpdate=0

	local tLabels = {'S','M','T','W','R','F','S'}
	for i=1,7 do
		SKIN:Bang('!SetOption','Day'..i..'Label','Text',tLabels[iStartOnMondays and i%7+1 or i])
	end
	hFile={month={},day={},year={},event={},title={},color={},} -- Initialize Event Matrix.
	local Files=Delim(SELF:GetOption('EventFile',''))
	if #Files>1 then
		local Folder=table.remove(Files,1) -- Remove Folder name from table.
		if not string.match(Folder,'[\\/]$') then Folder=Folder..'\\' end -- Add trailing forward slash.
		for k,v in ipairs(Files) do -- Concatenate Folder to each file.
			Files[k]=Folder..v
		end
	end
	for _,file in ipairs(Files) do -- For each event file.
		local In=io.input(SKIN:MakePathAbsolute(file),'r') -- Open file in read only.
		if not io.type(In)=='file' then -- File could not be opened.
			ErrMsg(0,'File Read Error',file)
		else -- File is open.
			local text=string.gsub(io.read('*all'),'<!%-%-.-%-%->','') -- Read in file contents and remove comments.
			io.close(In) -- Close the current file.
			if not string.match(string.lower(text),'<eventfile.->.-</eventfile>') then
				ErrMsg(0,'Invalid Event File',file)
			else
				local eFile,eSet={},{}
				local sw={ -- Define Event File tags
					set=function(x) eSet=Keys(x) end,
					['/set']=function(x) eSet={} end,
					eventfile=function(x) eFile=Keys(x) end,
					['/eventfile']=function(x) eFile={} end,
					event=function(x) local match,ev=string.match(x,'<(.+)>(.-)</') local Tmp=Keys(match,{event=ev})
						for i,v in pairs(hFile) do table.insert(hFile[i],Tmp[i] or eSet[i] or eFile[i] or '') end end,
					default=function(x,y) ErrMsg(0,'Invalid Event Tag:',y) end, -- Error
				}
				for line in string.gmatch(text,'[^\n]+') do -- For each file line.
					local tag=string.match(line,'^.-<([^%s>]+)')
					local f=sw[string.lower(tag)] or sw.default
					f(line,tag)
				end
			end
		end
	end
end

function Update()
	Date = os.date('*t')
	if Date.day ~= iDayOnLastUpdate then
		Events()
		
		iDayOnLastUpdate=Date.day
		tCurrMonth[2] = 28+(((Date.year%4==0 and Date.year%100~=0) or Date.year%400==0) and 1 or 0)
		local iStartDay = Rotate(tonumber(os.date('%w', os.time{year=Date.year, month=Date.month, day=1})))
		
		----------------------------------------------
		-- !SETOPTIONS
		
		local case={
			week=function(z) return Date.day+((z-1)-Rotate(Date.wday-1)) end,
			month=function(z) return z-iStartDay end,
		}
		for a = 1, iRange[sRange]  do
			local styles,tTip,color={'StyleCalendarText'},'',''
			if a%7==1 then table.insert(styles,'StyleCalendar'..(a==1 and 'TextFirst' or 'NewWeek')) end
			b=case[sRange](a)
			if b<1 then
				b=b+tCurrMonth[Date.month==1 and 12 or Date.month-1 ]
				table.insert(styles,iEDaysColor)
			elseif b>tCurrMonth[Date.month] then
				b=b-tCurrMonth[Date.month]
				table.insert(styles,iEDaysColor)
			elseif Hol[b] then
				table.insert(styles,'StyleCalendarEvent')
				tTip=table.concat(Hol[b]['text'],'\n')
				color=Hol[b]['color']
			end
			for k,v in pairs{
				MeterStyle=table.concat(styles,'|'),
				Text=iLeadingZeroes and string.format('%02d',b) or b,
				ToolTipText=tTip,
				FontColor=color
			} do SKIN:Bang('!SetOption','Day'..a,k,v) end
		end
		if sRange == 'month' then
			SKIN:Bang('!SetVariable','ThisWeek',math.ceil((Date.day+iStartDay)/7))
		end
		SKIN:Bang('!SetVariable','Week',Rotate(Date.wday-1))
		SKIN:Bang('!SetOption','Indicator2','Text',Date.day)
	end
	return Error and 'Error!' or 'Success!'
end

function Events() -- Parse Events table.
	Hol={} -- Initialize Event Table.
	local Test=function(c,d) return c=='' and '' or (d and d..c or nil) end
	local AddEvn=function(a,b,c)
		if Hol[a] then -- Adds new Events.
			table.insert(Hol[a]['text'],b)
			Hol[a]['color']=''
		else
			Hol[a]={text={b},color=c=='' and '' or c,}
		end
	end
	if SELF:GetNumberOption('BuiltInEvents',1)>0 then -- Add Easter and Good Friday
		local a,b,c,h,L,m=Date.year%19,math.floor(Date.year/100),Date.year%100,0,0,0
		local d,e,f,i,k=math.floor(b/4),b%4,math.floor((b+8)/25),math.floor(c/4),c%4
		h=(19*a+b-d-math.floor((b-f+1)/3)+15)%30
		L=(32+2*e+2*i-h-k)%7
		m=math.floor((a+11*h+22*L)/451)
		local EM,ED=math.floor((h+L-7*m+114)/31),(h+L-7*m+114)%31+1
		if Date.month==EM then AddEvn(ED,'Easter') end
		if Date.month==(EM-(ED-2<1 and 1 or 0)) then AddEvn((ED-2)+(ED-2<1 and tCurrMonth[EM-1] or 0),'Good Friday') end
	end
	for i=1,#hFile.month do -- For each event.
		if hFile.month[i]==Date.month or hFile.month[i]=='*' then -- If Event exists in current month or *.
			AddEvn( -- Calculate Day and add to Event Table
				SKIN:ParseFormula(Vars(hFile.day[i],hFile.event[i])) or ErrMsg(0,'Invalid Event Day',hFile.day[i],'in',hFile.event[i]),
				hFile.event[i]..(Test(hFile.year[i]) or ' ('..math.abs(Year-hFile.year[i])..')')..Test(hFile.title[i],' -'),
				hFile.color[i]
			)
		end
	end
end -- Events

function Vars(a,source) -- Makes allowance for {Variables}
	local D,W={sun=0, mon=1, tue=2, wed=3, thu=4, fri=5, sat=6},{first=0, second=1, third=2, fourth=3, last=4}
	return string.gsub(a,'%b{}',function(b)
		local strip=string.match(string.lower(b),'{(.+)}')
		local v1,v2=string.match(strip,'(.+)(...)')
		if W[v1 or 'nil'] and D[v2 or 'nil'] then -- Variable day.
			local L,wD=36+D[v2]-iStartDay,rotate(D[v2])
			return W[v1]<4 and wD+1-iStartDay+(iStartDay>wD and 7 or 0)+7*W[v1] or L-math.ceil((L-tCurrMonth[Date.month])/7)*7
		else -- Error
			return ErrMsg(0,'Invalid Variable',b,'in',source)
		end
	end)
end -- Vars

function ErrMsg(...) -- Used to display errors
	Error=true
	print('LuaCalendar: '..table.concat(arg,' ',2))
	return arg[1]
end -- ErrMsg

function Rotate(a) return iStartOnMondays and (a-1+7)%7 or a end

function Keys(a,b) -- Converts Key="Value" sets to a table
	local tbl=b or {}
	string.gsub(a,'(%a+)=(%b"")',function(c,d)
		local strip=string.match(d,'"(.+)"')
		tbl[string.lower(c)]=tonumber(strip) or strip
	end)
	return tbl
end -- Keys

function Delim(a) -- Separate String by Delimiter
	local tbl={}
	string.gsub(a,'[^%|]+', function(b) table.insert(tbl,b) end)
	return tbl
end -- Delim