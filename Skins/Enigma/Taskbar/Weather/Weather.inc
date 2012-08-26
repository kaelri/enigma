;---------------------------------------------------------------------
; MEASURES

[MeasureBar]
Measure=Calc
Formula=(MeasureWeatherTemp - MeasureWeatherDay2Low) / (MeasureWeatherDay2High - MeasureWeatherDay2Low)

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleWeather#Variant#Icon
MeasureName=MeasureWeatherIcon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherTemp
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Label]
Meter=STRING
MeasureName=MeasureWeatherDesc
MeterStyle=Style#Variant#Label

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar