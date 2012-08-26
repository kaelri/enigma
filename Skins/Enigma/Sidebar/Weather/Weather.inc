;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleWeather#Variant#Background

[Border]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Border | StyleWeather#Variant#Border1

;-----------------------
; DAY 1

[Icon]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Moxa
MeasureName=MeasureWeatherIcon

[Temp]
Meter=STRING
MeterStyle=StyleWeather#Variant#Text
MeasureName=MeasureWeatherTemp
Postfix="°"
LeftMouseUpAction=[[MeasureYahooWeather]]

[Desc]
Meter=STRING
MeasureName=MeasureWeatherDesc
MeterStyle=StyleWeather#Variant#Label

;-----------------------
; WIND

[WindSeparator]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Separator

[WindChill]
Meter=STRING
MeasureName=MeasureWeatherWindChill
MeterStyle=StyleWeather#Variant#Text | StyleWeather#Variant#TextSub
Postfix="°"

[WindChillLabel]
Meter=STRING
MeterStyle=StyleWeather#Variant#Label | StyleWeather#Variant#LabelSub
Text=Wind Chill

[WindSpeed]
Meter=STRING
MeasureName=MeasureWeatherWindSpeed
MeasureName2=MeasureWeatherUnitSpeed
MeterStyle=StyleWeather#Variant#Text | StyleWeather#Variant#TextSub
Text=%1 %2

[WindSpeedLabel]
Meter=STRING
MeterStyle=StyleWeather#Variant#Label | StyleWeather#Variant#LabelSub
Text=Speed

[WindDirection]
Meter=STRING
MeasureName=MeasureWeatherWindDirection
MeasureName2=MeasureWeatherWindDirectionCardinal
MeterStyle=StyleWeather#Variant#Text | StyleWeather#Variant#TextSub
Text=%1° (%2)

[WindDirectionLabel]
Meter=STRING
MeterStyle=StyleWeather#Variant#Label | StyleWeather#Variant#LabelSub
Text=Direction

;-----------------------
; ATMOSPHERE

[AtmoSeparator]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Separator

[AtmoHumidity]
Meter=STRING
MeasureName=MeasureWeatherAtmoHumidity
MeterStyle=StyleWeather#Variant#Text | StyleWeather#Variant#TextSub
Postfix="%"

[AtmoHumidityLabel]
Meter=STRING
MeterStyle=StyleWeather#Variant#Label | StyleWeather#Variant#LabelSub
Text=Humidity

[AtmoPressure]
Meter=STRING
MeasureName=MeasureWeatherAtmoPressure
MeasureName2=MeasureWeatherUnitPressure
MeterStyle=StyleWeather#Variant#Text | StyleWeather#Variant#TextSub
Text=%1 %2

[AtmoPressureLabel]
Meter=STRING
MeterStyle=StyleWeather#Variant#Label | StyleWeather#Variant#LabelSub
Text=Pressure

[AtmoVisibility]
Meter=STRING
MeasureName=MeasureWeatherAtmoVisibility
MeterStyle=StyleWeather#Variant#Text | StyleWeather#Variant#TextSub
Postfix="%"

[AtmoVisibilityLabel]
Meter=STRING
MeterStyle=StyleWeather#Variant#Label | StyleWeather#Variant#LabelSub
Text=Visibility

;-----------------------
; DAY 2

[Day2Separator]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Border | StyleWeather#Variant#Border2

[Icon2]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Moxa
MeasureName=MeasureWeatherDay2Icon

[Temp2]
Meter=STRING
MeterStyle=StyleWeather#Variant#Text
MeasureName=MeasureWeatherDay2Average
Postfix="°"
LeftMouseUpAction=[[MeasureWeatherRSS]]

[Date2]
Meter=STRING
MeasureName=MeasureWeatherDay2Date
MeterStyle=StyleWeather#Variant#Label

;-----------------------
; DAY 3

[Day3Separator]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Border | StyleWeather#Variant#Border3

[Icon3]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Moxa
MeasureName=MeasureWeatherDay3Icon

[Temp3]
Meter=STRING
MeterStyle=StyleWeather#Variant#Text
MeasureName=MeasureWeatherDay3Average
Postfix="°"
LeftMouseUpAction=[[MeasureWeatherRSS]]

[Date3]
Meter=STRING
MeasureName=MeasureWeatherDay3Date
MeterStyle=StyleWeather#Variant#Label

;-----------------------

[BorderBottom]
Meter=IMAGE
MeterStyle=StyleWeather#Variant#Border | StyleWeather#Variant#Border4