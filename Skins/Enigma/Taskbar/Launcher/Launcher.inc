;---------------------------------------------------------------------
; MEASURES

[MeasureProcess]
Measure=Plugin
Plugin=Process
ProcessName=#AppPathHandle#
Substitute="-1":"Closed","1":"Running"

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleLauncher#Variant#Icon[MeasureProcess]
ImageName=#AppIcon#
LeftMouseUpAction=["#AppPath#"][!Update]
ToolTipText=#AppPath#
DynamicVariables=1

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text | StyleLauncher#Variant#Text[MeasureProcess]
Text="#App#"
LeftMouseUpAction=["#AppPath#"][!Update]
ToolTipText=#AppPath#
DynamicVariables=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="#AppLabel#"