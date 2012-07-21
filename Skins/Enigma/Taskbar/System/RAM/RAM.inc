;---------------------------------------------------------------------
; MEASURES

[MeasureRAM]
Measure=PhysicalMemory

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureRAM
Percentual=1
AutoScale=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="RAM"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureRAM