function Initialize()
	local file = io.input(SKIN:GetVariable('@')..'User\\Run.cfg')
	Execute = {}
	if io.type(file)=='file' then
		for line in io.lines() do
			local key,command = string.match(line,'^%s-([^=]+)=(.+)')
			Execute[string.lower(string.match(key,'(.+)%s-$'))]=command
		end
		io.close(file)
	end
end

function Run()
	local command = SKIN:GetVariable('Run')
	SKIN:Bang(Execute[command] or command)
end