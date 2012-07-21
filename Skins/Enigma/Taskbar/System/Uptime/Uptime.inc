;---------------------------------------------------------------------
; MEASURES

[MeasureUptime]
Measure=UPTIME
UpdateDivider=10
Format="%4!i!d %3!i!h %2!i!m"

[MeasureUptimeMinutes]
Measure=UPTIME
UpdateDivider=10
Format="%2"

[MeasureBar]
Measure=Calc
Formula=MeasureUptimeMinutes / 60

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureUptime
Postfix="m"

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="UP"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar