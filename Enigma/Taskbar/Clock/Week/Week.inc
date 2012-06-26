;---------------------------------------------------------------------
; MEASURES

[MeasureWeek]
Measure=Time
UpdateDivider=10
Format="%a"

[MeasureDate]
Measure=Time
UpdateDivider=10000
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