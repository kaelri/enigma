[Variables]
PanelHeight=395
ArrowY=168
LabelsQueue=Unit

;---------------------------------------------------------------------
; MEASURES

[MeasureWorld1Lat]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=http://weather.yahooapis.com/forecastrss?w=#World1WeatherCode#&u=#Unit#
RegExp=(?siU).*lat>(.*)<.*long>(.*)<
StringIndex=1
FinishAction=!SetOption MeasureWriteWorld1 Formula 1

[MeasureWorld1Lon]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=[MeasureWorld1Lat]
StringIndex=2

[MeasureWriteWorld1]
Measure=Calc
DynamicVariables=1
Formula=0
IfEqualValue=1
IfEqualAction=[!WriteKeyValue Variables World1Lat "[MeasureWorld1Lat]" "#EnigmaSettings#"][!WriteKeyValue Variables World1Lon "[MeasureWorld1Lon]" "#EnigmaSettings#"][!DisableMeasure]


[MeasureWorld2Lat]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=http://weather.yahooapis.com/forecastrss?w=#World2WeatherCode#&u=#Unit#
RegExp=(?siU).*lat>(.*)<.*long>(.*)<
StringIndex=1
FinishAction=!SetOption MeasureWriteWorld2 Formula 1

[MeasureWorld2Lon]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=[MeasureWorld2Lat]
StringIndex=2

[MeasureWriteWorld2]
Measure=Calc
DynamicVariables=1
Formula=0
IfEqualValue=1
IfEqualAction=[!WriteKeyValue Variables World2Lat "[MeasureWorld2Lat]" "#EnigmaSettings#"][!WriteKeyValue Variables World2Lon "[MeasureWorld2Lon]" "#EnigmaSettings#"][!DisableMeasure]


[MeasureWorld3Lat]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=http://weather.yahooapis.com/forecastrss?w=#World3WeatherCode#&u=#Unit#
RegExp=(?siU).*lat>(.*)<.*long>(.*)<
StringIndex=1
FinishAction=!SetOption MeasureWriteWorld3 Formula 1

[MeasureWorld3Lon]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=[MeasureWorld3Lat]
StringIndex=2

[MeasureWriteWorld3]
Measure=Calc
DynamicVariables=1
Formula=0
IfEqualValue=1
IfEqualAction=[!WriteKeyValue Variables World3Lat "[MeasureWorld3Lat]" "#EnigmaSettings#"][!WriteKeyValue Variables World3Lon "[MeasureWorld3Lon]" "#EnigmaSettings#"][!DisableMeasure]

;---------------------------------------------------------------------
; METERS

;-----------------------
; INDICATOR ARROW

[Arrow]
Meter=IMAGE
MeterStyle=StyleMenuArrow
Y=#ArrowY#

;-----------------------
; WORLD

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=W  O  R  L  D

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set the geographical locations displayed by Weather and World.
H=24

;-----------------------

[WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="Weather Code"

[WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#WeatherCode#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 1"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('WeatherCode')"
TooltipTitle="Local Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for your local area.#CRLF##CRLF#If you live in the United States of America, simply type your ZIP code.#CRLF##CRLF#If you live elsewhere:#CRLF#1. Open http://weather.yahoo.com in your browser.#CRLF#2. Search for your location and click to navigate to its page.#CRLF#3. Find the 'RSS' link in the upper-right corner and copy the link location.#CRLF#4. Part of the feed's URL will include 'p=', followed by an eight-character code. That is your weather code.#CRLF#5. Paste it here.#CRLF##CRLF#Yahoo! Weather's codes are identical to those used by Weather.com.

;-----------------------

[World1WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="1st World"

[World1WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World1WeatherCode#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 2"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('World1WeatherCode')"
TooltipTitle="1st Remote Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for another city or area of your choosing. You can find worldwide codes in exactly the same way as your local weather code.

[World2WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="2nd World"

[World2WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World2WeatherCode#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 4"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('World2WeatherCode')"
TooltipTitle="2nd Remote Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for another city or area of your choosing. You can find worldwide codes in exactly the same way as your local weather code.

[World3WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="3rd World"

[World3WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World3WeatherCode#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 6"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('World3WeatherCode')"
TooltipTitle="3rd Remote Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for another city or area of your choosing. You can find worldwide codes in exactly the same way as your local weather code.

;-----------------------

[UnitName]
Meter=STRING
MeterStyle=StyleName
Text="Units"

[UnitText]
Meter=STRING
MeterStyle=StyleText
Text=#UnitLabel#
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('Unit')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Unit')"
TooltipTitle="Temperature Units (Celsius/Fahrenheit)"
TooltipText=Click to toggle whether Enigma Weather and Enigma World display temperature, speed and pressure units in Imperial (Fahrenheit) or metric (Celcius).
DynamicVariables=1

;-----------------------

[RestoreDefault]
Meter=STRING
MeterStyle=StyleText | StyleRestoreDefault