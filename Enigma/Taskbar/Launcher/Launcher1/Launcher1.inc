;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
ImageName=#App1Icon#
LeftMouseUpAction=["#App1Path#"][!Redraw]
ToolTipText=#App1Path#

[App]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#App1#"
LeftMouseUpAction=["#App1Path#"][!Redraw]
ToolTipText=#App1Path#

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="#App1Label#"