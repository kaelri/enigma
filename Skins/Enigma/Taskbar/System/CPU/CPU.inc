;---------------------------------------------------------------------
; MEASURES

[MeasureCPU]
Measure=CPU

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureCPU

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="CPU"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureCPU