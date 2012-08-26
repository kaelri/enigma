function Initialize()
	-- GET NOTE PATHS
	Notes = {}
	local AllPaths = SELF:GetOption('Path', '')
	for Path in AllPaths:gmatch('[^%|]+') do
		local Path = SKIN:MakePathAbsolute(Path)
		local Dir, Name, Ext = Path:match('(.-)([^\\]-)%.([^%.]+)$')
		table.insert(Notes, {
			Path = Path,
			Name = Name
			})
	end

	-- SET STARTING NOTE
	n = n or 1
end

function Update()
	local Queue = {}

	-- BUILD QUEUE
	Queue['CurrentNote'] = n
	Queue['Name']        = Notes[n].Name
	Queue['Path']        = Notes[n].Path
	
	-- READ FILE	
	local File    = io.input(Notes[n].Path)
	local Content = nil
	if File then
		Content = File:read('*all')
		File:close()
	else
		Content = 'Could not open file: '..Notes[n].Path
	end
	
	-- STRIP CONTENT DIVIDER & FORMAT LISTS
	local Divider    = SELF:GetOption('ContentDivider','')
	local Content    = Content:gsub(Divider..'.*', '')
	local Content    = Content:gsub('- ', '· ')
	Queue['Content'] = Content
		
	-- OUTPUT
	local VariablePrefix = SELF:GetOption('VariablePrefix', '')
	for k, v in pairs(Queue) do
		SKIN:Bang('!SetVariable', VariablePrefix..k, v)
	end
	
	-- FINISH ACTION   
	local FinishAction = SELF:GetOption('FinishAction', '')
	if FinishAction ~= '' then
		SKIN:Bang(FinishAction)
	end
	
	return 'Finished #'..n..' ('..Notes[n].Path..').'
end

-----------------------------------------------------------------------
-- EXTERNAL COMMANDS

function Show(a)
	n = tonumber(a)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function ShowPrevious()
	n = (n == 1) and #Notes or (n - 1)
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end

function ShowNext()
	n = (n % #Notes) + 1
	SKIN:Bang('!UpdateMeasure', SELF:GetName())
end