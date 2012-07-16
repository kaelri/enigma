;---------------------------------------------------------------------
; MEASURES

[Variables]
@include=#@#Measures\YahooWeather.inc
CurrentCode=#WeatherCode#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=Image
MeterStyle=Style#Variant#Icon | StyleSunIcon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherSunset

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text=SET