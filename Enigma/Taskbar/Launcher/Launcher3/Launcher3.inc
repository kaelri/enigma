;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
ImageName=#App3Icon#
LeftMouseUpAction=["#App3Path#"][!Redraw]
ToolTipText=#App3Path#

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#App3#"
LeftMouseUpAction=["#App3Path#"][!Redraw]
ToolTipText=#App3Path#

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="#App3Label#"