;---------------------------------------------------------------------
; MEASURES

[MeasureBar]
Measure=Calc
Formula=(MeasureWeatherDay3Average - MeasureWeatherDay3Low) / (MeasureWeatherDay3High - MeasureWeatherDay3Low)

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleWeather#Variant#Icon
MeasureName=MeasureWeatherDay3Icon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherDay3Average
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Label]
Meter=STRING
MeasureName=MeasureWeatherDay3Desc
MeterStyle=Style#Variant#Label
Text=Tomorrow