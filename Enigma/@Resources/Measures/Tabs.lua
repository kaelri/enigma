function Initialize()
	NumberOfTabs = tonumber(SKIN:GetVariable('NumberOfTabs'))
	Type = SELF:GetOption('Type', 'Reader')
	TotalTabs = SELF:GetNumberOption('TotalTabs', 8)
end

function Update()
	if NumberOfTabs > 1 then
		for i = 2, NumberOfTabs do
			SKIN:Bang('!EnableMeasureGroup', 'Tab'..i)
			SKIN:Bang('!ShowMeterGroup', 'Tab'..i)
		end

		if Type == 'Reader' then
			UpdateReader()
		elseif Type == 'Notes' then
			UpdateNotes()
		end

		SKIN:Bang('!Update')
	end

	if TotalTabs > NumberOfTabs then
		for i = NumberOfTabs + 1, TotalTabs do
			SKIN:Bang('!SetOptionGroup', 'Tab'..i, 'W', 0)
			SKIN:Bang('!SetOptionGroup', 'Tab'..i, 'H', 0)
		end
	end
end

function UpdateReader()
	local Measures = {'MeasureFeed1'}
	for i = 2, NumberOfTabs do
		table.insert(Measures, 'MeasureFeed'..i)
	end
	SKIN:Bang('!SetOption', 'MeasureScriptReader', 'FeedMeasureName', table.concat(Measures, '|'))
	SKIN:Bang('!CommandMeasure', 'MeasureScriptReader', 'GetMeasures()')
end

function UpdateNotes()
	local Files = { SKIN:GetVariable('NotesFile1') }
	for i = 2, NumberOfTabs do
		table.insert(Files, SKIN:GetVariable('NotesFile'..i))
	end
	SKIN:Bang('!SetOption', 'MeasureNote', 'NotePath', table.concat(Files, '|'))
	SKIN:Bang('!CommandMeasure', 'MeasureNote', 'GetFiles()')
end