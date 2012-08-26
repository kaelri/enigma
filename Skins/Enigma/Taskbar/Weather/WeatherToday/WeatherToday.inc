;---------------------------------------------------------------------
; MEASURES

[MeasureBar]
Measure=Calc
Formula=(MeasureWeatherDay2Average - MeasureWeatherDay2Low) / (MeasureWeatherDay2High - MeasureWeatherDay2Low)

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleWeather#Variant#Icon
MeasureName=MeasureWeatherDay2Icon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherDay2Average
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Label]
Meter=STRING
MeasureName=MeasureWeatherDay2Desc
MeterStyle=Style#Variant#Label
Text=Today

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar