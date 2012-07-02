;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
LeftMouseUpAction=!CommandMeasure "MeasureSearch" "ExecuteBatch 1"
ImageName=#Search1Icon#

[App]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#Search1#"
LeftMouseUpAction=!CommandMeasure "MeasureSearch" "ExecuteBatch 1"

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="SEARCH"