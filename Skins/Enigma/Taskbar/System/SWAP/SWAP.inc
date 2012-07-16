;---------------------------------------------------------------------
; MEASURES

[MeasureSWAP]
Measure=SWAPMemory

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureSWAP
Percentual=1
AutoScale=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="SWAP"