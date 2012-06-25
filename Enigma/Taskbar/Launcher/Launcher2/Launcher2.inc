;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
ImageName=#App2Icon#
LeftMouseUpAction=["#App2Path#"][!Redraw]
ToolTipText=#App2Path#

[App]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#App2#"
LeftMouseUpAction=["#App2Path#"][!Redraw]
ToolTipText=#App2Path#

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="#App2Label#"