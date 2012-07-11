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

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeek

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureDate