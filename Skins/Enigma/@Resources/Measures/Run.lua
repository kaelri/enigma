function Initialize()
	local file = io.input(SKIN:GetVariable('@') .. 'User\\Run.cfg')
	Execute = {}
	if io.type(file) == 'file' then
		for line in io.lines() do
			if not string.match(line,'^;')then
				local key,command = string.match(line, '^%s-([^=]+)=(.+)')
				if key and command then
					Execute[string.lower(string.match(key, '(.+)%s-$'))] = command
				end
			end
		end
		io.close(file)
	end
end

function Run()
	local command = SKIN:GetVariable('Run')
	if string.match(string.lower(command), '^search%d? ') then
		local num = tonumber(string.match(string.lower(command), '^search(%d)') or 1)
		local searchnum = (num>=1 and num<=5) and num or 1
		local term = string.gsub(string.match(command, '^......%d? (.+)'), '%s', '%%%%20')
		local search = string.gsub(SKIN:GetVariable('Search'..searchnum..'Command'), '%$UserInput%$', term)
		SKIN:Bang(search)
	elseif string.match(string.lower(command), '^web ') then
		local term = string.match(command, '^... (.+)')
		local tbl = {}
		for word in string.gmatch(term, '[^%.]+') do table.insert(tbl, word) end
		SKIN:Bang('"http://'..(#tbl>=3 and '' or 'www.')..table.concat(tbl,'.')..(#tbl>=2 and '"' or '.com"'))
	elseif string.match(string.lower(command), '^http://') then
		SKIN:Bang('"'..command..'"')
	elseif string.match(string.lower(command), '^options') then
		local term = string.match(command, '^.+ (.+)')
		local options = {home='',general='',music='',feeds='',world='',apps='',search='',format='',layout='',}
		if options[term or ''] then
			SKIN:Bang('!WriteKeyValue','Variables','Panel',term,'#ROOTCONFIGPATH#Options\\Options.ini')
		end
		SKIN:Bang('!ActivateConfig','Enigma\\Options')
	else
		SKIN:Bang(Execute[string.lower(command)] or command)
	end
end