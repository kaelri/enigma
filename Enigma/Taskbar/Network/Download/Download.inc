;---------------------------------------------------------------------
; MEASURES

[MeasureNetIn]
Measure=NetIn
MaxValue=#NetworkMaxDownload#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[TextDownload]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureNetIn
Text="%1"
AutoScale=1
NumOfDecimals=0

[LabelDownload]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="I"