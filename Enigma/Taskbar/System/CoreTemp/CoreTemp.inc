;---------------------------------------------------------------------
; MEASURES

[MeasureCoreTemp]
Measure=Plugin
Plugin=Plugins\CoreTemp.dll
CoreTempType=Temperature
CoreTempIndex=#Core#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[CoreTemp]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureCoreTemp
Postfix="°"

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="1"