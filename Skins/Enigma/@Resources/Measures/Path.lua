function Initialize()
	sVariablePrefix = SELF:GetOption('VariablePrefix')
	sInput = SELF:GetOption('Input')
	sInputType = SELF:GetOption('InputType'):lower()
	sOutput = SELF:GetOption('Output'):lower()
end

function Update()
	local text

	if sInputType == 'variable' then
		text = SKIN:GetVariable(sInput)
	elseif sInputType == 'measure' then
		text = SKIN:GetMeasure(sInput):GetStringValue()
	else
		text = sInput
	end

	if text ~= '' then
		local sDir, sName, sExt = text:match('(.-)([^\\/]-)%.([^%.]+)$')
		local oCase = {dir = sDir, name = sName, nameext = sName .. '.' .. sExt, ext = sExt}
		for k, v in pairs(oCase) do SKIN:Bang('!SetVariable', sVariablePrefix .. k, v) end
		return oCase[sOutput] or sName
	else
		return ''
	end
end
