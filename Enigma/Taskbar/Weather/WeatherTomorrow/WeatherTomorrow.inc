;---------------------------------------------------------------------
; MEASURES

[Variables]
@include=#@#Measures\YahooWeather.inc
CurrentCode=#WeatherCode#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleWeather#Variant#Icon
MeasureName=MeasureWeatherDay3Icon

[Temp]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherDay3Average
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Desc]
Meter=STRING
MeasureName=MeasureWeatherDay3Desc
MeterStyle=Style#Variant#Label
Text=Tomorrow