function Initialize()
	-- GET NOTE PATHS
	Notes = {}
	local AllPaths = SELF:GetOption('Path')
	for Path in AllPaths:gmatch('[^%|]+') do
		local Path = SKIN:MakePathAbsolute(Path)
		table.insert(Notes, {
			Path = Path,
			Name = Path:match('.-([^\\]-)%.[^%.]+$'),
			})
	end

	-- SET STARTING NOTE
	n = n or 1
end

function Update()
	-- BUILD QUEUE
	local Queue = {
		CurrentNote = n,
		Name = Notes[n].Name,
		Path = Notes[n].Path,
	}
	
	-- READ FILE	
	local File = io.open(Notes[n].Path, 'r')
	if File then
		-- STRIP CONTENT DIVIDER & FORMAT LISTS
		local Divider = SELF:GetOption('ContentDivider', '')
		Queue.Content = File:read('*all'):gsub(Divider .. '.*', ''):gsub('- ', '· ')
		File:close()
	else
		Queue.Content = 'Could not open file: ' .. Notes[n].Path
	end
	
	-- OUTPUT
	local VariablePrefix = SELF:GetOption('VariablePrefix')
	for k, v in pairs(Queue) do
		SKIN:Bang('!SetVariable', VariablePrefix .. k, v)
	end
	
	-- FINISH ACTION   
	local FinishAction = SELF:GetOption('FinishAction', '')
	if FinishAction ~= '' then
		SKIN:Bang(FinishAction)
	end
	
	return string.format('Finished #%d (%s).', n, Notes[n].Path)
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