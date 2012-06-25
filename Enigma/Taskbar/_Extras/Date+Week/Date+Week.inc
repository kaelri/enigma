;---------------------------------------------------------------------
; MEASURES

[MeasureWeek]
Measure=Time
Format="%A"

[MeasureDate]
Measure=Time
Format="%#d %B, %Y"

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