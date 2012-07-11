;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
ImageName=#App4Icon#
LeftMouseUpAction=["#App4Path#"][!Redraw]
ToolTipText=#App4Path#

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#App4#"
LeftMouseUpAction=["#App4Path#"][!Redraw]
ToolTipText=#App4Path#

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="#App4Label#"