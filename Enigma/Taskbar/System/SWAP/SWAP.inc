;---------------------------------------------------------------------
; MEASURES

[MeasureSWAP]
Measure=SWAPMemory

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[SWAP]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureSWAP
Percentual=1
AutoScale=1

[Label SWAP]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="SWAP"