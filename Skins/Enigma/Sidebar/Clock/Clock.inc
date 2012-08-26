;---------------------------------------------------------------------
; MEASURES

[MeasureTime]
Measure=Time

[MeasureWeek]
Measure=Time
Format="%A"

[MeasureDate]
Measure=Time
Format="%#d %B, %Y"

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleClock#Variant#Background

;-----------------------
; CLOCK

[Clock]
Meter=IMAGE
MeterStyle=StyleClockFace | StyleClock#Variant#Face

[Seconds]
Meter=ROUNDLINE
MeasureName=MeasureTime
MeterStyle=StyleClockSeconds | StyleClock#Variant#Seconds

[Hours]
Meter=ROUNDLINE
MeasureName=MeasureTime
MeterStyle=StyleClockHours | StyleClock#Variant#Hours

[Minutes]
Meter=ROUNDLINE
MeasureName=MeasureTime
MeterStyle=StyleClockMinutes | StyleClock#Variant#Minutes

;-------------------------
; WEEK, DATE & LOCATION

[Week]
Meter=STRING
MeasureName=MeasureWeek
MeterStyle=StyleClockWeek | StyleClock#Variant#Week

[Date]
Meter=STRING
MeasureName=MeasureDate
MeterStyle=StyleClockDate | StyleClock#Variant#Date

[Location]
Meter=STRING
MeasureName=MeasureWeatherCity
MeterStyle=StyleClockLocation | StyleClock#Variant#Location