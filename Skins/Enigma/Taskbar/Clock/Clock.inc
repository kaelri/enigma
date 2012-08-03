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

[MeasureSeconds]
Measure=Time
Format="%#S"

[MeasureBar]
Measure=Calc
Formula=MeasureSeconds / 60

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

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

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureText

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureLabel

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar