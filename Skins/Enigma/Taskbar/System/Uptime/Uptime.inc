;---------------------------------------------------------------------
; MEASURES

[MeasureUptime]
Measure=UPTIME
UpdateDivider=10
Format="%4!i!d %3!i!h %2!i!m"
UpdateDivider=60

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