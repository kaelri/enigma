;---------------------------------------------------------------------
; MEASURES

[MeasureCoreTemp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=#Core#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureCoreTemp
Postfix="°"

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="1"