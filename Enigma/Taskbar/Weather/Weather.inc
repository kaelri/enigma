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
MeasureName=MeasureWeatherIcon

[Temp]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherTemp
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Desc]
Meter=STRING
MeasureName=MeasureWeatherDesc
MeterStyle=Style#Variant#Label