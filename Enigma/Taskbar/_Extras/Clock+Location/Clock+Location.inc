;---------------------------------------------------------------------
; MEASURES

@include=#@#Measures\YahooWeather.inc
CurrentCode=#WeatherCode#

[MeasureClock]
Measure=Time
Format="%#I.%M %p"
Substitute="PM":"pm","AM":"am"

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Clock]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureClock

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureWeatherCity