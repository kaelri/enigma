function Initialize()
	NumberOfFeeds = tonumber(SKIN:GetVariable('NumberOfFeeds'))
end

function Update()
	if NumberOfFeeds > 1 then
		local Measures = {'MeasureFeed1'}
		for i = 2, NumberOfFeeds do
			SKIN:Bang('!EnableMeasureGroup', 'Tab'..i)
			SKIN:Bang('!ShowMeterGroup', 'Tab'..i)
			table.insert(Measures, 'MeasureFeed'..i)
		end
		SKIN:Bang('!SetOption', 'MeasureScriptReader', 'FeedMeasureName', table.concat(Measures, '|'))
		SKIN:Bang('!CommandMeasure', 'MeasureScriptReader', 'GetMeasures()')
		SKIN:Bang('!Update')
	end
end