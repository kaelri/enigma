;---------------------------------------------------------------------
; MEASURES

[MeasureNetOut]
Measure=NetOut
MaxValue=#NetworkMaxUpload#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[TextUpload]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureNetOut
Text="%1"
AutoScale=1
NumOfDecimals=0

[LabelUpload]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="O"