function Initialize()
	LastTextW = nil
	LastLabelW = nil
	MeterText = SKIN:GetMeter('Text')
	MeterLabel = SKIN:GetMeter('Label')
	MinW = SELF:GetNumberOption('MinWidth', 0)
	MaxW = SELF:GetNumberOption('MaxWidth', SKIN:GetVariable('WORKAREAWIDTH'))
	Variant = SKIN:GetVariable('Variant')
end

function Update()
	if Variant == 'IconOnly' then return end

	TextW = MeterText:GetW()
	LabelW = MeterLabel:GetW()

	--DETECT CHANGE
	if (TextW ~= LastTextW) or (LabelW ~= LastLabelW) then
		LastTextW = TextW
		LastLabelW = LabelW

		--CALCULATE WIDTH
		if Variant == 'IconRight' then
			W = MaxW
		elseif Variant == 'Mini' or Variant == 'Tiny' then
			W = TextW + LabelW
		else
			W = math.max(TextW, LabelW)
		end
		W = math.min(math.max(W, MinW), MaxW)

		--UPDATE VARIABLE
		SKIN:Bang('!SetVariable', 'TaskbarSkinWidth', W)

		--CLIP STRINGS
		if Variant == 'Mini' or Variant == 'Tiny' then
			if TextW > MaxW - LabelW then
				SKIN:Bang('!SetOption', 'Text', 'ClipString', 1)
				SKIN:Bang('!SetOption', 'Text', 'W', MaxW - LabelW)
			end
		else
			if TextW > MaxW then
				SKIN:Bang('!SetOption', 'Text', 'ClipString', 1)
				SKIN:Bang('!SetOption', 'Text', 'W', MaxW)
			end
			if LabelW > MaxW then
				SKIN:Bang('!SetOption', 'Label', 'ClipString', 1)
				SKIN:Bang('!SetOption', 'Label', 'W', MaxW)
			end
		end
	end
end