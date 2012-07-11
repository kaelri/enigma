;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
ImageName=#App5Icon#
LeftMouseUpAction=["#App5Path#"][!Redraw]
ToolTipText=#App5Path#

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#App5#"
LeftMouseUpAction=["#App5Path#"][!Redraw]
ToolTipText=#App5Path#

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="#App5Label#"