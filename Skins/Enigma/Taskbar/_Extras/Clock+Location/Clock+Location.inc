;---------------------------------------------------------------------
; MEASURES

[MeasureClock]
Measure=Time
Format="%#I.%M %p"
Substitute="PM":"pm","AM":"am"

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureClock

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureWeatherCity