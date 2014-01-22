function Initialize()
	local file = io.open(SKIN:GetVariable('@') .. 'User\\Run.cfg', 'r')
	Execute = {}
	if file then
		for line in file:lines() do
			local key, command = line:match('^%s-([^=]+)=(.+)')
			if line:match('^%s-[^;]') and key and command then
				Execute[key:lower():match('(.+)%s-$')] = command
			end
		end
		file:close()
	end
end

function Run(command)
	lcommand = command:lower()
	if lcommand:match('^search%d? .+') then
		local num, term = command:match('^......(%d?) (.+)')
		num = tonumber(num ~= '' and num or 1)
		local searchnum = ('Search%dCommand'):format((num >= 1 and num <= 5) and num or 1)
		local search = SKIN:GetVariable(searchnum):gsub('%$UserInput%$', (term:gsub('%s', '%%%%20')))
		SKIN:Bang(search)
	elseif lcommand:match('^web .+') then
		local tbl, term = {}, command:match('^... (.+)')
		for word in term:gmatch('[^%.]+') do table.insert(tbl, word) end
		SKIN:Bang('"http://' .. (#tbl >= 3 and '' or 'www.') .. table.concat(tbl, '.') .. (#tbl >= 2 and '"' or '.com"'))
	elseif lcommand:match('^https?://.+') then
		SKIN:Bang(('%q'):format(command))
	elseif lcommand:match('^options') then
		local term = lcommand:match('^.+ (.+)') or 'none'
		if ('home|general|music|feeds|world|apps|search|format|layout'):find(term:gsub('|', '')) then
			SKIN:Bang('!WriteKeyValue', 'Variables', 'Panel', term, '#ROOTCONFIGPATH#Options\\Options.ini')
		end
		SKIN:Bang('!ActivateConfig', 'Enigma\\Options')
	else
		SKIN:Bang(Execute[lcommand] or command)
	end
end