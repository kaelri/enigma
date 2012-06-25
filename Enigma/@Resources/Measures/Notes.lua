function Initialize()
	sVariablePrefix = SELF:GetOption('VariablePrefix','')
	sContentDivider = SELF:GetOption('ContentDivider','')
	sFinishAction = SELF:GetOption('FinishAction')
	tNotes = {}
	for a in string.gmatch(SELF:GetOption('NotePath',''),'[^%|]+') do
		table.insert(tNotes,SKIN:MakePathAbsolute(a))
	end
	iCurrentNote=1
	SKIN:Bang('!SetVariable','NumberOfNotes',#tNotes)
end

function Update()
	local sNotePath=assert(tNotes[iCurrentNote],'Invalid Note number '..iCurrentNote)
	SKIN:Bang('!SetVariable','CurrentNote',iCurrentNote)
	
	-----------------------------------------------------------------------
	-- DETERMINE CONTENT
	
	local sNoteDir,sNoteName,sNoteExt = string.match(sNotePath, '(.-)([^\\]-)%.([^%.]+)$')
	
	local sRawFile=io.input(sNotePath)
	local sRaw=io.read('*all')
	io.close(sRawFile)
	
	local sNoteContent=string.gsub(sRaw,sContentDivider..'.*','')
	
	--sNoteContent = (sContentDivider~='' and string.match(sRaw,sContentDivider)) and string.match(sRaw,'(.-)'..sContentDivider) or sRaw
		
	for k,v in pairs({ -- OUTPUT
		Path=sNotePath,
		Name=sNoteName,
		Content=string.gsub(sNoteContent,'- ','· '),
	}) do SKIN:Bang('!SetVariable',sVariablePrefix..k,v) end	
	
	if sFinishAction ~= '' then -- FINISH ACTION
		SKIN:Bang(sFinishAction)
	end
	
	return 'Success!'	
end

function SwitchToPrevious()
	iCurrentNote = iCurrentNote==1 and #tNotes or iCurrentNote-1
	Update()
end

function SwitchToNext()
	iCurrentNote = iCurrentNote % #tNotes + 1
	Update()
end

function NoteError(sErrorPath, sErrorName, sErrorContent)
	SKIN:Bang('!SetVariable',sVariablePrefix..'Path',sErrorPath)
	SKIN:Bang('!SetVariable',sVariablePrefix..'Name',sErrorName)
	SKIN:Bang('!SetVariable',sVariablePrefix..'Content',sErrorContent)
end