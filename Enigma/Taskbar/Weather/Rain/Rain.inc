;---------------------------------------------------------------------
; MEASURES

[MeasureRain]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=http://www.weather.com/weather/today/#WeatherCode#
RegExp=(?siU)Chance of Rain:<br><strong>(.*)%</strong>
StringIndex=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleRainIcon

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureRain
Postfix="%"
AutoScale=1
NumOfDecimals=0

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="RAIN"