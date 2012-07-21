;---------------------------------------------------------------------
; MEASURES

[MeasureWeek]
Measure=Time
UpdateDivider=60
Format="%a"

[MeasureDate]
Measure=Time
UpdateDivider=60
Format="%#d"

[MeasureWeekInt]
Measure=Time
UpdateDivider=60
Format="%w"

[MeasureBar]
Measure=Calc
Formula=(MeasureWeekInt + 1) / 7

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

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar