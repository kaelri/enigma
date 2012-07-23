;---------------------------------------------------------------------
; MEASURES

[MeasureBinCount]
Measure=Plugin
Plugin=RecycleManager
RecycleType=COUNT
UpdateDivider=10

; [MeasureBinSize]
; Measure=Plugin
; Plugin=RecycleManager
; RecycleType=SIZE
; UpdateDivider=10

[MeasureFull]
Measure=Calc
Formula=MeasureBinCount>0

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleRecyclerIcon
MeasureName=MeasureFull
LeftMouseUpAction=[!CommandMeasure "MeasureBinCount" "OpenBin"][!Refresh]
RightMouseUpAction=[!CommandMeasure "MeasureBinCount" "EmptyBin"][!Refresh]
ToolTipTitle=Open Recycle Bin
TooltipText=Right-click to empty the bin.

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureBinCount
Text="%1 ITEMS"
LeftMouseUpAction=[!CommandMeasure "MeasureBinCount" "OpenBin"][!Refresh]
RightMouseUpAction=[!CommandMeasure "MeasureBinCount" "EmptyBin"][!Refresh]
ToolTipTitle=Open Recycle Bin
TooltipText=Right-click to empty the bin.

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
; MeasureName=MeasureBinSize
; AutoScale=1
; NumOfDecimals=0
Text="BIN"