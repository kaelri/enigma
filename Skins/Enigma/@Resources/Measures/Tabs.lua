function Initialize()
	NumberOfTabs = tonumber(SKIN:GetVariable('NumberOfTabs'))
	Type         = SELF:GetOption('Type', 'Reader')
	TotalTabs    = SELF:GetNumberOption('TotalTabs', 8)

	Functions = {
		Reader = UpdateReader,
		Notes  = UpdateNotes
		}
end

function Update()
	if NumberOfTabs > 1 then
		for i = 2, NumberOfTabs do
			SKIN:Bang('!EnableMeasureGroup', 'Tab'..i)
			SKIN:Bang('!ShowMeterGroup', 'Tab'..i)
		end

		Functions[Type]()
	end

	for i = NumberOfTabs + 1, TotalTabs do
		for j,v in ipairs{ 'X', 'Y', 'W', 'H' } do
			SKIN:Bang('!SetOptionGroup', 'Tab'..i, v, 0)
		end
	end

	SKIN:Bang('!Update')
end

function UpdateReader()
	local Measures = {}
	for i = 1, NumberOfTabs do
		table.insert(Measures, 'MeasureFeed'..i)
	end
	SKIN:Bang('!SetOption', 'MeasureScriptReader', 'MeasureName', table.concat(Measures, '|'))
	SKIN:Bang('!CommandMeasure', 'MeasureScriptReader', 'Initialize()')
end

function UpdateNotes()
	local Files = {}
	for i = 1, NumberOfTabs do
		table.insert(Files, SKIN:GetVariable('NotesFile'..i))
	end
	SKIN:Bang('!SetOption', 'MeasureNote', 'Path', table.concat(Files, '|'))
	SKIN:Bang('!CommandMeasure', 'MeasureNote', 'Initialize()')
end