;---------------------------------------------------------------------
; MEASURES

[MeasureSearch]
Measure=PLUGIN
Plugin=InputText
UpdateDivider=-1
Command1=["#Search3Command#"] DefaultValue="Search #Search3#"
FocusDismiss=1
X=10
Y=10
W=(#TaskbarSkinWidth#*#SkinWidthMultiplier#-20)
H=20
FontFace=#Font#
FontSize=#Size1#
FontColor=#ColorBorder#
SolidColor=#ColorPanel#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
LeftMouseUpAction=!CommandMeasure "MeasureSearch" "ExecuteBatch 1"
ImageName=#Search3Icon#

[App]
Meter=STRING
MeterStyle=Style#Variant#Text
Text="#Search3#"
LeftMouseUpAction=!CommandMeasure "MeasureSearch" "ExecuteBatch 1"

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="SEARCH"