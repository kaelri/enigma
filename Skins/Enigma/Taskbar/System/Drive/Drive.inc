;---------------------------------------------------------------------
; MEASURES

[MeasureDrive]
Measure=FreeDiskSpace
Drive=#Drive#:
IfAboveValue=0
IfAboveAction=!SetOption "Text" "Text" "%1"
IfEqualValue=0
IfEqualAction=!SetOption "Text" "Text" "Removed"

[MeasureDriveInverse]
Measure=FreeDiskSpace
Drive=#Drive#:
InvertMeasure=1

[MeasureDriveName]
Measure=FreeDiskSpace
Drive=#Drive#:
Label=1
UpdateDivider=-1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleHDDIcon
LeftMouseUpAction=["#Drive#:\"]
ToolTipText=Click to browse #Drive#:\.

[Bar]
Meter=BAR
MeterStyle=StyleHDD#Variant#Bar
MeasureName=MeasureDriveInverse

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureDrive
AutoScale=1
NumOfDecimals=0
LeftMouseUpAction=["#Drive#:\"]
ToolTipText=Click to browse #Drive#:\.

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
; MeasureName=MeasureDriveName
Text=#Drive#