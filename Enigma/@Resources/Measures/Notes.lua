PROPERTIES = {
	NotePath = '';
	VariablePrefix = '';
	MultipleNotes = 0;
	ContentDivider = '';
	FinishAction = '';
}

-- When Rainmeter supports escape characters for bangs, use this function to escape quotes, brackets.
function ParseSpecialCharacters(sString)
	sString = string.gsub(sString, '\"', '')
	sString = string.gsub(sString, '- ', '· ')
	sString = string.gsub(sString, 'ï»¿', '')
	return sString
end

function Initialize()
	sNotePath = PROPERTIES.NotePath
	sVariablePrefix = PROPERTIES.VariablePrefix
	iMultipleNotes = tonumber(PROPERTIES.MultipleNotes)
	sContentDivider = PROPERTIES.ContentDivider
	sFinishAction = PROPERTIES.FinishAction
	tNotes = {}
end

function Update()

	-----------------------------------------------------------------------
	-- INPUT NOTE(S)

	if iMultipleNotes == 1 then
		iNumberOfNotes = tonumber(SKIN:GetVariable(sVariablePrefix..'NumberOfNotes'))
		for i = 1, iNumberOfNotes do
			tNotes[i] = SKIN:GetVariable(sVariablePrefix..'NotePath'..i)
		end
		iCurrentNote = tonumber(SKIN:GetVariable(sVariablePrefix..'CurrentNote'))
		sNotePath = tNotes[iCurrentNote]
	end
	
	-----------------------------------------------------------------------
	-- DETERMINE CONTENT
	
	sNoteDir, sNoteName, sNoteExt = string.match(sNotePath, "(.-)([^\\]-)%.([^%.]+)$")
	
	io.input(sNotePath)
	sRaw = io.read('*all')

	
	if sContentDivider ~= '' and string.match(sRaw, sContentDivider) then
		sNoteContent = string.match (sRaw, '(.-)'..sContentDivider)
	else
		sNoteContent = sRaw
	end
	
	sNoteContent = ParseSpecialCharacters(sNoteContent)
	
	-----------------------------------------------------------------------
	-- OUTPUT
	
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Path" "'..sNotePath..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Name" "'..sNoteName..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Content" "'..sNoteContent..'"')
	
	-----------------------------------------------------------------------
	-- FINISH ACTION
	
	if sFinishAction ~= '' then
		SKIN:Bang(sFinishAction)
	end
	
	-- io.close(sRawFile)
	
	return 'Success!'	
end

function SwitchToPrevious()
	if (iCurrentNote - 1) < 1 then
		iCurrentNote = iCurrentNote - 1 + iNumberOfNotes
	else
		iCurrentNote = iCurrentNote - 1
	end
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'CurrentNote" "'..iCurrentNote..'"')
	Update()
end

function SwitchToNext()
	if (iCurrentNote + 1) > iNumberOfNotes then
		iCurrentNote = iCurrentNote + 1 - iNumberOfNotes
	else
		iCurrentNote = iCurrentNote + 1
	end
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'CurrentNote" "'..iCurrentNote..'"')
	Update()
end

function NoteError(sErrorPath, sErrorName, sErrorContent)
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Path" "'..sErrorPath..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Name" "'..sErrorName..'"')
	SKIN:Bang('!SetVariable "'..sVariablePrefix..'Content" "'..sErrorContent..'"')
end