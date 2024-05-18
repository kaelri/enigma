;---------------------------------------------------------------------
; MEASURES

[MeasureWeatherDay2Average]
Measure=Calc
Formula=ROUND(([@ForecastDay2NightTemperature:]+[@ForecastDay2DayTemperature:])/2)
DynamicVariables=1

[MeasureBar]
Measure=Calc
Formula=(MeasureWeatherDay2Average - [@ForecastDay2NightTemperature:]) / ([@ForecastDay2DayTemperature:] - {@ForecastDay2NightTemperature:])
DynamicVariables=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleWeather#Variant#Icon
MeasureName=@ForecastDay2DayIcon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureWeatherDay2Average
Postfix="°"
LeftMouseUpAction=["https://weather.com/#Language#/weather/today/l/#CurrentCode#"]

[Label]
Meter=STRING
MeasureName=@ForecastDay2DayConditions
MeterStyle=Style#Variant#Label
Text=Today

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar
