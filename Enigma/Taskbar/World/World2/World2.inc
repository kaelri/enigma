;---------------------------------------------------------------------
; MEASURES

@include=#@#Measures\YahooWeather.inc
CurrentCode=#World2WeatherCode#

[MeasureTimeZoneAlt]
Measure=Plugin
Plugin=Plugins\WebParser.dll
UpdateRate=3600
Url=http://xml.weather.com/weather/local/#World2WeatherCode#?cc=*
RegExp="<zone>(.*?)</zone>"
StringIndex=1

[MeasureTimeZoneMod]
Measure=CALC
Formula=(#World2DSTOffset# + MeasureTimeZoneAlt)

[MeasureTime]
Measure=Time
TimeZone=[MeasureTimeZoneMod]
DynamicVariables=1

[MeasureClock]
Measure=Time
Format="%#I.%M %p"
TimeZone=[MeasureTimeZoneMod]
Substitute="PM":"pm","AM":"am"
DynamicVariables=1
DaylightSavingTime=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Clock]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleClockIcon

[Seconds]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockSeconds
MeasureName=MeasureTime

[Hours]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockHours
MeasureName=MeasureTime

[Minutes]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockMinutes
MeasureName=MeasureTime

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text | StyleWorld#Variant#Text
MeasureName=MeasureClock
MeasureName2=MeasureWeatherCity

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label | StyleWorld#Variant#Label
MeasureName=MeasureWeatherCity
MeasureName2=MeasureClock