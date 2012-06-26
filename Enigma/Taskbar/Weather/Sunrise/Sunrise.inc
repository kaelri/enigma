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

[Sunrise]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherSunrise

[Sunset]
Meter=STRING
MeterStyle=Style#Variant#Label
Text=RISE