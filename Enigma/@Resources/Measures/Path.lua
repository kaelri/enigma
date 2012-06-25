PROPERTIES = {
	Input = '';
	InputType = '';
	Output = '';
	VariablePrefix = '';
}

function Parse(sInput, sInputType, sVariablePrefix)
	if sInputType == 'Variable' then
		sPath = SKIN:GetVariable(sInput)
	elseif sInputType == 'Measure' then
		msInput = SKIN:GetMeasure(sInput)
		sPath = msInput:GetStringValue()
	else
		sPath = sInput
	end
	sDir, sName, sExt = string.match(sPath, "(.-)([^\\]-)%.([^%.]+)$")
	sNameExt = sName..'.'..sExt
	
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Dir" "'..sDir..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Name" "'..sName..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'NameExt" "'..sNameExt..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Ext" "'..sExt..'"')
end

function Initialize()
	sScriptVariablePrefix = PROPERTIES.VariablePrefix
	sScriptInput = PROPERTIES.Input
	sScriptInputType = PROPERTIES.InputType
	sOutput = PROPERTIES.Output
end

function Update()
	Parse(sScriptInput, sScriptInputType, sScriptVariablePrefix)
	
	if sOutput == 'Dir' then
		return sDir
	elseif sOutput == 'NameExt' then
		return sNameExt
	elseif sOutput == 'Ext' then
		return sExt
	else
		return sName
	end
end

