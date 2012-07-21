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
Text="1"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar