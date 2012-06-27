;---------------------------------------------------------------------
; MEASURES

[MeasureSSID]
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=SSID
WifiIntfID=0
WifiListStyle=0

[MeasureQuality]
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=QUALITY
WifiIntfID=0
WifiListStyle=0

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleNetworkIcon

[WiFi]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureQuality
Percentual=1
AutoScale=1

[SSID]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureSSID