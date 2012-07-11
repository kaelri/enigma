function Initialize()
	LastW = nil
	MeterText = SKIN:GetMeter('Text')
	MeterLabel = SKIN:GetMeter('Label')
	MinW = SELF:GetNumberOption('MinWidth', 0)
	MaxW = SELF:GetNumberOption('MaxWidth', SKIN:GetVariable('WORKAREAWIDTH'))
	Variant = SKIN:GetVariable('Variant')
end

function Update()
	if Variant ~= 'IconOnly' then
		TextW = MeterText:GetW()
		LabelW = MeterLabel:GetW()
		if Variant == 'IconRight' then
			W = MaxW
		elseif Variant == 'Mini' or Variant == 'Tiny' then
			W = TextW + LabelW
		else
			W = math.max(TextW, LabelW)
		end
		W = math.min(math.max(W, MinW), MaxW)
	else
		W = MinW
	end

	if W ~= LastW then
		SKIN:Bang('!SetVariable', 'TaskbarSkinWidth', W)
		if Variant == 'Mini' or Variant == 'Tiny' then
			SKIN:Bang('!MoveMeter', 5 + LabelW, MeterLabel:GetY(), 'Text')
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
		LastW = W
	end
end