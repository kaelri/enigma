function Initialize()
	sVariablePrefix = SELF:GetOption('VariablePrefix')
	sInput = SELF:GetOption('Input')
	sInputType = string.lower(SELF:GetOption('InputType'))
	sOutput = string.lower(SELF:GetOption('Output'))
end

function Update()
	local fCase={
		variable=function() return SKIN:GetVariable(sInput) end,
		measure=function() local msInput=SKIN:GetMeasure(sInput) return msInput:GetStringValue() end,
		default=function() return sInput end,
	}
	local f=fCase[sInputType] or fCase.default
	local text=f()
	if text~='' then
		local sDir, sName, sExt = string.match(text, '(.-)([^\\]-)%.([^%.]+)$')
		local oCase={dir=sDir,name=sName,nameext=sName..'.'..sExt,ext=sExt}
		for k,v in pairs(oCase) do SKIN:Bang('!SetVariable',sVariablePrefix..k,v) end
		return oCase[sOutput] or sName
	else
		return ''
	end
end
