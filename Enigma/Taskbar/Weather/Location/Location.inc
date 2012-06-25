;---------------------------------------------------------------------
; MEASURES

@include=#@#Measures\YahooWeather.inc
CurrentCode=#WeatherCode#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=Image
MeterStyle=Style#Variant#Icon | StyleLocationIcon

[Location]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherCity

[State]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureWeatherLatitude
MeasureName2=MeasureWeatherLongitude
Text=%1, %2