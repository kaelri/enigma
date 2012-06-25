;---------------------------------------------------------------------
; MEASURES

[MeasureCPU]
Measure=CPU

[MeasureRAM]
Measure=PhysicalMemory

[MeasureHD]
Measure=FreeDiskSpace
Drive=#Drive1#:
UpdateDivider=60

[MeasurePower]
Measure=Plugin
Plugin=Plugins\PowerPlugin.dll
PowerState=PERCENT

[MeasureCore1]
Measure=CPU
Processor=1

[MeasureCore2]
Measure=CPU
Processor=2

;---------------------------------------------------------------------
; METERS

;-----------------------
; FRAME

[Background]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Background

[Border1]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border1

[VerticalBorderA]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#VerticalBorderA

[VerticalBorderB]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#VerticalBorderB

[Border2]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border2

;-----------------------
; LABELS & TEXT

[LabelCPU]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label1
Text="CPU"

[CPU]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text1
MeasureName=MeasureCPU
Text="%1%"

[LabelRAM]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label2
Text="RAM"

[RAM]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text2
MeasureName=MeasureRAM
Text="%1%"
Percentual=1
AutoScale=1

[LabelHD]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label3
Text="HDD"

[HD]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text3
MeasureName=MeasureHD
Text="%1B"
AutoScale=1
NumOfDecimals=0

[LabelPower]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label4
Text="PWR"

[Power]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text4
MeasureName=MeasurePower
Text="%1%"

;-----------------------

;-----------------------
; GRAPH FRAME

[Border3]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border3

[VerticalBorderC]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#VerticalBorderC

[Border4]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border4

[Border5]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border5

;-----------------------
; HISTOGRAMS

[Core1Graph]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph1
MeasureName=MeasureCore1
Autoscale=1

[Core2Graph]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph2
MeasureName=MeasureCore2
Autoscale=1

;-----------------------
; LOWER TEXT

[Core1Label]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel1
; Prefix="· "
Text="1"

[Core1Number]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText1
MeasureName=MeasureCore1
Postfix="%"

[Core2Label]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel2
Text="2"
; Postfix=" ·"

[Core2Number]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText2
MeasureName=MeasureCore2
Postfix="%"