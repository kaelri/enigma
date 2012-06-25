;---------------------------------------------------------------------
; MEASURES

[MeasureTime]
Measure=Time

[MeasureText]
Measure=Time
Format="%#I.%M"

[MeasureLabel]
Measure=Time
Format="%p"

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Clock]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureText

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureLabel

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleClockIcon
ToolTipText=[MeasureText] [MeasureLabel]
DynamicVariables=1

[Seconds]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockSeconds
MeasureName=MeasureTime

[Hours]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockHours
MeasureName=MeasureTime

[Minutes]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockMinutes
MeasureName=MeasureTime