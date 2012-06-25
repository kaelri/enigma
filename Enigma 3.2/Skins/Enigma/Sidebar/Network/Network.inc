;---------------------------------------------------------------------
; MEASURES

[MeasureNetIn]
Measure=NetIn

[MeasureNetOut]
Measure=NetOut

[MeasureSSID]
Measure=Plugin
Plugin=Plugins\WifiStatus.dll
WifiInfoType=SSID
WifiIntfID=0
WifiListStyle=0

[MeasureWiFi]
Measure=Plugin
Plugin=Plugins\WifiStatus.dll
WifiInfoType=QUALITY
WifiIntfID=0
WifiListStyle=0

[MeasureLAN]
Measure=Plugin
Plugin=Plugins\SysInfo.dll
SysInfoType=IP_ADDRESS
SysInfoData=1

[MeasureWAN]
Measure=Plugin
Plugin=Plugins\WebParser.dll
UpdateRate=21600
Url=http://checkip.dyndns.org
RegExp="(?siU)Address: (.*)</body>"
StringIndex=1

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

[LabelSSID]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label1
Text="SSID"

[SSID]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text1
MeasureName=MeasureSSID

[LabelWiFi]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label2
Text="WiFi"

[WiFi]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text2
MeasureName=MeasureWiFi

[LabelLAN]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label3
Text="LAN"

[LAN]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text3 | StyleSystem#Variant#TextDark
MeasureName=MeasureLAN

[LabelWAN]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label4
Text="WAN"

[WAN]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text4 | StyleSystem#Variant#TextDark
MeasureName=MeasureWAN
;Text="12.345.678.90"
;Uncomment this text when taking screenshots to protect your IP.

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

[NetOut]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph1
MeasureName=MeasureNetOut

[NetIn]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph2
MeasureName=MeasureNetIn

;-----------------------
; LOWER TEXT

[NetOutLabel]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel1
; Prefix="· "
Text="UP"

[NetOutNumber]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText1
MeasureName=MeasureNetOut
AutoScale=1
NumOfDecimals=0

[NetInLabel]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel2
Text="DOWN"
; Postfix=" ·"

[NetInNumber]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText2
MeasureName=MeasureNetIn
AutoScale=1
NumOfDecimals=0