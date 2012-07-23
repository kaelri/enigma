;---------------------------------------------------------------------
; MEASURES

[MeasureDay]
Measure=Time
Format=%d

[MeasureMonth]
Measure=Time
Format=%m

[MeasureYear]
Measure=Time
Format=%Y

[MeasureDaysSinceY2K]
Measure=Calc
Formula=FLOOR((MeasureYear-2000)*365.2425)+(MeasureMonth>1)*31+(MeasureMonth>2)*(28+((MeasureYear%4)=0))+(MeasureMonth>3)*31+(MeasureMonth>4)*30+(MeasureMonth>5)*31+(MeasureMonth>6)*30+(MeasureMonth>7)*31+(MeasureMonth>8)*31+(MeasureMonth>9)*30+(MeasureMonth>10)*31+(MeasureMonth>11)*30+(MeasureMonth>12)*31+MeasureDay

[MeasureMoonText]
Measure=Calc
Formula=ROUND(16*FRAC(((-29.5305888531)+SQRT((29.5305888531)**2-4*(102.19*(10**(-12)))*(20.362954-MeasureDaysSinceY2K)))/(2*(102.19*(10**(-12))))))%16
Substitute="10":"Waxing Crescent","11":"Waxing Crescent","12":"First Quarter","13":"Waxing Gibbous","14":"Waxing Gibbous","15":"Waxing Gibbous","0":"Full","1":"Waning Gibbous","2":"Waning Gibbous","3":"Waning Gibbous","4":"Last Quarter","5":"Waning Crescent","6":"Waning Crescent","7":"Waning Crescent","8":"New","9":"Waxing Crescent"

[MeasureMoonOverlay]
Measure=Calc
Formula=ROUND(16*FRAC(((-29.5305888531)+SQRT((29.5305888531)**2-4*(102.19*(10**(-12)))*(20.362954-MeasureDaysSinceY2K)))/(2*(102.19*(10**(-12))))))%16
Substitute=".00000":""

[MeasureBar]
Measure=Calc
Formula=(MeasureMoonOverlay + 1) / 16

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureMoonText

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="LUNA"

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleMoonIcon

[IconOverlay]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleMoonIconOverlay
MeasureName=MeasureMoonOverlay

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar