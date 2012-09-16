;---------------------------------------------------------------------
; MEASURES

[MeasureCPU]
Measure=CPU

[MeasureRAM]
Measure=PhysicalMemory

[MeasureHD]
Measure=FreeDiskSpace
Drive=#Drive1#:
IgnoreRemovable=0
UpdateDivider=60

[MeasurePower]
Measure=Plugin
Plugin=PowerPlugin
PowerState=PERCENT

[MeasureCore1Floating]
Measure=CPU
Processor=1

[MeasureCore1Percent]
Measure=Calc
Formula=MeasureCore1Floating / 100

[MeasureCore2Floating]
Measure=CPU
Processor=2

[MeasureCore2Percent]
Measure=Calc
Formula=MeasureCore2Floating / 100

;---------------------------------------------------------------------
; METERS

;-----------------------
; FRAME

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleSystem#Variant#Background

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

[Label1]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label1
Text="CPU"

[Text1]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text1
MeasureName=MeasureCPU
Text="%1%"

[Label2]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label2
Text="RAM"

[Text2]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text2
MeasureName=MeasureRAM
Text="%1%"
Percentual=1
AutoScale=1

[Label3]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label3
Text="HDD"

[Text3]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text3
MeasureName=MeasureHD
Text="%1B"
AutoScale=1
NumOfDecimals=0

[Label4]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label4
Text="PWR"

[Text4]
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
MeasureName=MeasureCore1#SystemGraphType#
Autoscale=1

[Core2Graph]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph2
MeasureName=MeasureCore2#SystemGraphType#
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
MeasureName=MeasureCore1Floating
Postfix="%"

[Core2Label]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel2
Text="2"
; Postfix=" ·"

[Core2Number]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText2
MeasureName=MeasureCore2Floating
Postfix="%"