;---------------------------------------------------------------------
; MEASURES

[MeasureWeatherDay3Average]
Measure=Calc
Formula=ROUND(([@ForecastDay3NightTemperature:]+[@ForecastDay3DayTemperature:])/2)
DynamicVariables=1

[MeasureBar]
Measure=Calc
Formula=(MeasureWeatherDay3Average - [@ForecastDay3NightTemperature:]) / ([@ForecastDay3DayTemperature:] - [@ForecastDay3NightTemperature:])
DynamicVariables=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleWeather#Variant#Icon
MeasureName=@ForecastDay3DayIcon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherDay3Average
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Label]
Meter=STRING
MeasureName=@ForecastDay3DayConditions
MeterStyle=Style#Variant#Label
Text=Tomorrow
