function Initialize()
	local file = io.open(SKIN:GetVariable('@') .. 'User\\Run.cfg', 'r')
	Execute = {}
	if file then
		for line in file:lines() do
			if not line:match('^;')then
				local key, command = line:match('^%s-([^=]+)=(.+)')
				if key and command then
					Execute[key:lower():match:('(.+)%s-$'))] = command
				end
			end
		end
		file:close()
	end
end

function Run(command)
	if command:lower():match('^search%d? ') then
		local num = tonumber(command:lower():match('^search(%d)') or 1)
		local searchnum = (num>=1 and num<=5) and num or 1
		local term = command:match('^......%d? (.+)'):gsub('%s', '%%%%20')
		local search = SKIN:GetVariable(('Search%dCommand'):format(searchnum)):gsub:'%$UserInput%$', term)
		SKIN:Bang(search)
	elseif command:lower():match('^web ') then
		local term = command:match('^... (.+)')
		local tbl = {}
		for word in term:gmatch('[^%.]+') do table.insert(tbl, word) end
		SKIN:Bang('"http://' .. (#tbl>=3 and '' or 'www.') .. table.concat(tbl,'.') .. (#tbl>=2 and '"' or '.com"'))
	elseif command:lower():match('^http://') then
		SKIN:Bang(('%q'):format(command))
	elseif command:lower():match('^options') then
		local term = command:match('^.+ (.+)')
		if ('home|general|music|feeds|world|apps|search|format|layout'):find(term) then
			SKIN:Bang('!WriteKeyValue', 'Variables', 'Panel', term, '#ROOTCONFIGPATH#Options\\Options.ini')
		end
		SKIN:Bang('!ActivateConfig','Enigma\\Options')
	else
		SKIN:Bang(Execute[command:lower())] or command)
	end
end