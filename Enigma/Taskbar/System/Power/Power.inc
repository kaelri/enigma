;---------------------------------------------------------------------
; MEASURES

[MeasurePower]
Measure=Plugin
Plugin=PowerPlugin
UpdateDivider=60
PowerState=PERCENT

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StylePWRIcon

[Bar]
Meter=BAR
MeterStyle=StylePWR#Variant#Bar
MeasureName=MeasurePower

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasurePower

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="PWR"