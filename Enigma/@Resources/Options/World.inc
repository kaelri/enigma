[Variables]
PanelHeight=395
ArrowY=168

;---------------------------------------------------------------------
; MEASURES

[MeasureWriteUnit]
Measure=CALC
Formula=#UnitType#
IfEqualValue=1
IfEqualAction=[!WriteKeyValue Variables Unit c "#Settings#"][!DisableMeasure MeasureWriteUnit]
IfAboveValue=1
IfAboveAction=[!WriteKeyValue Variables Unit f "#Settings#"][!DisableMeasure MeasureWriteUnit]

[MeasureUnitTypeSubstitute]
Measure=CALC
Formula=#UnitType#
Substitute="1":"Celsius","2":"Fahrenheit"

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
TooltipTitle="1st Remote Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for another city or area of your choosing. You can find worldwide codes in exactly the same way as your local weather code.

[World1DSTOffsetName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="DST Offset"

[World1DSTOffsetText]
Meter=STRING
MeterStyle=StyleText
Text="#World1DSTOffset#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 3"
TooltipTitle="1st Daylight Savings Time Offset (hours)"
TooltipText=Yahoo's time zone information is inaccurate for some locations, especially during Daylight Savings time. If this is happening with one of your World locations, set the DST Offset option to correct it. For example, if the displayed time is one hour behind, you would set the offset to '+1'. If it is two hours ahead, you would set '-2.'

[World2WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="2nd World"

[World2WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World2WeatherCode#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 4"
TooltipTitle="2nd Remote Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for another city or area of your choosing. You can find worldwide codes in exactly the same way as your local weather code.

[World2DSTOffsetName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="DST Offset"

[World2DSTOffsetText]
Meter=STRING
MeterStyle=StyleText
Text="#World2DSTOffset#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 5"
TooltipTitle="2nd Daylight Savings Time Offset (hours)"
TooltipText=Yahoo's time zone information is inaccurate for some locations, especially during Daylight Savings time. If this is happening with one of your World locations, set the DST Offset option to correct it. For example, if the displayed time is one hour behind, you would set the offset to '+1'. If it is two hours ahead, you would set '-2.'

[World3WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="3rd World"

[World3WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World3WeatherCode#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 6"
TooltipTitle="3rd Remote Yahoo! Weather Code"
TooltipText=Click to type or paste the Yahoo! Weather location code for another city or area of your choosing. You can find worldwide codes in exactly the same way as your local weather code.

[World3DSTOffsetName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="DST Offset"

[World3DSTOffsetText]
Meter=STRING
MeterStyle=StyleText
Text="#World3DSTOffset#"
LeftMouseUpAction=!CommandMeasure "MeasureInputWorld" "ExecuteBatch 7"
TooltipTitle="3rd Daylight Savings Time Offset (hours)"
TooltipText=Yahoo's time zone information is inaccurate for some locations, especially during Daylight Savings time. If this is happening with one of your World locations, set the DST Offset option to correct it. For example, if the displayed time is one hour behind, you would set the offset to '+1'. If it is two hours ahead, you would set '-2.'

;-----------------------

[UnitName]
Meter=STRING
MeterStyle=StyleName
Text="Units"

[UnitText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureUnitTypeSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables UnitType (3-#UnitType#) "#Settings#"][!Refresh *]
TooltipTitle="Temperature Units (Celsius/Fahrenheit)"
TooltipText=Click to toggle whether Enigma Weather and Enigma World display temperature, speed and pressure units in Imperial (Fahrenheit) or metric (Celcius).

;-----------------------

[RestoreDefaultWorld]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables WeatherCode "#DefaultWeatherCode#" "#Settings#"][!WriteKeyValue Variables Unit "#DefaultUnit#" "#Settings#"][!WriteKeyValue Variables World1WeatherCode "#DefaultWorld1WeatherCode#" "#Settings#"][!WriteKeyValue Variables World1DSTOffset "#DefaultWorld1DSTOffset#" "#Settings#"][!WriteKeyValue Variables World2WeatherCode "#DefaultWorld2WeatherCode#" "#Settings#"][!WriteKeyValue Variables World2DSTOffset "#DefaultWorld2DSTOffset#" "#Settings#"][!WriteKeyValue Variables World3WeatherCode "#DefaultWorld3WeatherCode#" "#Settings#"][!WriteKeyValue Variables World3DSTOffset "#DefaultWorld3DSTOffset#" "#Settings#"][!Refresh *]
TooltipText=Click here to reset all World settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.