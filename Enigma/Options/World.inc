[Variables]
PanelHeight=395
ArrowY=168
LabelsQueue=Unit

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
LeftMouseUpAction=[!WriteKeyValue Variables WriteVariable WeatherCode "#ROOTCONFIGPATH#Options\WeatherCodeFinder\WeatherCodeFinder.ini"][!ActivateConfig "Enigma\Options\WeatherCodeFinder" "WeatherCodeFinder.ini"][!Zpos 1 "Enigma\Options\WeatherCodeFinder"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('WeatherCode')"
TooltipTitle="Local Yahoo! Weather Code"
TooltipText=Click to find the Yahoo! Weather location code for your local area.

;-----------------------

[World1WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="1st World"

[World1WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World1WeatherCode#"
LeftMouseUpAction=[!WriteKeyValue Variables WriteVariable World1WeatherCode "#ROOTCONFIGPATH#Options\WeatherCodeFinder\WeatherCodeFinder.ini"][!ActivateConfig "Enigma\Options\WeatherCodeFinder" "WeatherCodeFinder.ini"][!Zpos 1 "Enigma\Options\WeatherCodeFinder"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('World1WeatherCode')"
TooltipTitle="1st Remote Yahoo! Weather Code"
TooltipText=Click to find the Yahoo! Weather location code for another city or area of your choosing.

[World2WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="2nd World"

[World2WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World2WeatherCode#"
LeftMouseUpAction=[!WriteKeyValue Variables WriteVariable World2WeatherCode "#ROOTCONFIGPATH#Options\WeatherCodeFinder\WeatherCodeFinder.ini"][!ActivateConfig "Enigma\Options\WeatherCodeFinder" "WeatherCodeFinder.ini"][!Zpos 1 "Enigma\Options\WeatherCodeFinder"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('World2WeatherCode')"
TooltipTitle="2nd Remote Yahoo! Weather Code"
TooltipText=Click to find the Yahoo! Weather location code for another city or area of your choosing.

[World3WeatherCodeName]
Meter=STRING
MeterStyle=StyleName
Text="3rd World"

[World3WeatherCodeText]
Meter=STRING
MeterStyle=StyleText
Text="#World3WeatherCode#"
LeftMouseUpAction=[!WriteKeyValue Variables WriteVariable World3WeatherCode "#ROOTCONFIGPATH#Options\WeatherCodeFinder\WeatherCodeFinder.ini"][!ActivateConfig "Enigma\Options\WeatherCodeFinder" "WeatherCodeFinder.ini"][!Zpos 1 "Enigma\Options\WeatherCodeFinder"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('World3WeatherCode')"
TooltipTitle="3rd Remote Yahoo! Weather Code"
TooltipText=Click to find the Yahoo! Weather location code for another city or area of your choosing.

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