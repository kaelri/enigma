;---------------------------------------------------------------------
; MEASURES

[MeasureDriveFree]
Measure=FreeDiskSpace
Drive=#Drive#:
IgnoreRemovable=0

[MeasureDriveUsed]
Measure=FreeDiskSpace
Drive=#Drive#:
IgnoreRemovable=0
InvertMeasure=1

[MeasureDriveTotal]
Measure=FreeDiskSpace
Drive=#Drive#
IgnoreRemovable=0
Total=1

[MeasureDriveType]
Measure=FreeDiskSpace
Drive=#Drive#:
IgnoreRemovable=0
Type=1
IfAboveValue=2
IfAboveAction=!SetOption "Text" "Text" "%1"
IfBelowValue=2
IfBelowAction=!SetOption "Text" "Text" "Removed"

; [MeasureDriveName]
; Measure=FreeDiskSpace
; Drive=#Drive#:
; IgnoreRemovable=0
; Label=1
; UpdateDivider=-1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleHDDIcon
LeftMouseUpAction=["#Drive#:\"]
ToolTipTitle=Explore #Drive#:\

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar | StyleHDD#Variant#Bar
MeasureName=MeasureDriveUsed

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureDriveFree
AutoScale=1
NumOfDecimals=0
LeftMouseUpAction=["#Drive#:\"]
ToolTipTitle=Explore #Drive#:\

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
; MeasureName=MeasureDriveName
Text=#Drive#