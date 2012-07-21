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

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureNetIn
Text="%1"
AutoScale=1
NumOfDecimals=0

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="I"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureNetIn