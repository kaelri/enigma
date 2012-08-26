;---------------------------------------------------------------------
; MEASURES

[MeasureTimeZone]
Measure=Plugin
Plugin=WebParser
UpdateRate=3600
Url=http://ws.geonames.org/timezone?lat=#CurrentCodeLat#&lng=#CurrentCodeLon#
RegExp=<gmtOffset>(.*)</gmtOffset>
StringIndex=1

[MeasureTime]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1

[MeasureTimeSeconds]
Measure=Time
TimeZone=[MeasureTimeZone]
Format="%#S"
DynamicVariables=1

[MeasureClock]
Measure=Time
Format="%#I.%M %p"
TimeZone=[MeasureTimeZone]
Substitute="PM":"pm","AM":"am"
DynamicVariables=1

[MeasureBar]
Measure=Calc
Formula=MeasureTimeSeconds / 60

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
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

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar