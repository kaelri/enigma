function Initialize()
	local file = io.input(SKIN:GetVariable('@') .. 'User\\Run.cfg')
	Execute = {}
	if io.type(file) == 'file' then
		for line in io.lines() do
			local key,command = string.match(line, '^%s-([^=]+)=(.+)')
			Execute[string.lower(string.match(key, '(.+)%s-$'))] = command
		end
		io.close(file)
	end
end

function Run()
	local command = SKIN:GetVariable('Run')
	if string.match(string.lower(command), '^search ') then
		local term = string.gsub(string.match(command, '^...... (.+)'), '%s', '%%%%20')
		local search = string.gsub(SKIN:GetVariable('Search1Command'), '%$UserInput%$', term)
		SKIN:Bang(search)
	elseif string.match(string.lower(command), '^web ') then
		local term = string.match(command, '^... (.+)')
		SKIN:Bang('http://'..(string.match(term, '%.') and term or term..'.com'))
	else
		SKIN:Bang(Execute[string.lower(command)] or command)
	end
end