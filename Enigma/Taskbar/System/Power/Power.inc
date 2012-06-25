;---------------------------------------------------------------------
; MEASURES

[MeasurePower]
Measure=Plugin
Plugin=Plugins\PowerPlugin.dll
PowerState=PERCENT

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[PWR]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasurePower

[Label PWR]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="PWR"

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StylePWRIcon

[Bar PWR]
Meter=BAR
MeterStyle=Style#Variant#Bar | StylePWR#Variant#Bar
MeasureName=MeasurePower