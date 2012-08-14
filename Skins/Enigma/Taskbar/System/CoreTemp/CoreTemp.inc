;---------------------------------------------------------------------
; MEASURES

[MeasureCoreTemp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=#Core#

[MeasureCoreTempMax]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=TjMax
CoreTempIndex=#Core#

[MeasureLabel]
Measure=Calc
Formula=#Core#+1
UpdateDivider=-1

[MeasureBar]
Measure=Calc
Formula=MeasureCoreTemp / MeasureCoreTempMax


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
MeasureName=MeasureLabel

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar