;---------------------------------------------------------------------
; MEASURES

[MeasureWAN]
Measure=Plugin
Plugin=Plugins\WebParser.dll
UpdateRate=21600
Url=http://checkip.dyndns.org
RegExp="(?siU)Address: (.*)</body>"
StringIndex=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[WAN]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWAN

[Label WAN]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="WAN"