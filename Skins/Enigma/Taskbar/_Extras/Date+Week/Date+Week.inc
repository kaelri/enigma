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

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeek

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureDate