;---------------------------------------------------------------------
; MEASURES

[MeasureRAM]
Measure=PhysicalMemory

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[RAM]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureRAM
Percentual=1
AutoScale=1

[Label RAM]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="RAM"