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

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureNetOut
Text="%1"
AutoScale=1
NumOfDecimals=0

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="O"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureNetOut