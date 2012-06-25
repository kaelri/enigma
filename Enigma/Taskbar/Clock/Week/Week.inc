;---------------------------------------------------------------------
; MEASURES

[MeasureWeek]
Measure=Time
Format="%a"

[MeasureDate]
Measure=Time
Format="%#d"

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Week]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeek

[Date]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureDate