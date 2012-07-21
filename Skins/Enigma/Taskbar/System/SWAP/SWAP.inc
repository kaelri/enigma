;---------------------------------------------------------------------
; MEASURES

[MeasureSWAP]
Measure=SWAPMemory

[MeasureSWAPTotal]
Measure=SWAPMemory
Total=1

[MeasureBar]
Measure=Calc
Formula= MeasureSWAP / MeasureSWAPTotal

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

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar