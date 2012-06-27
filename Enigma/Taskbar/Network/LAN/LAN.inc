;---------------------------------------------------------------------
; MEASURES

[MeasureLAN]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[LAN]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureLAN

[Label LAN]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="LAN"