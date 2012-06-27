;---------------------------------------------------------------------
; MEASURES

[MeasureFeed]
Measure=Plugin
Plugin=WebParser
UpdateRate=600
Url=#GoogleCalendar1#?max-results=4&futureevents=true&singleevents=true&orderby=starttime&sortorder=a
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
Disabled=1
FeedMeasureName=MeasureFeed

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleGcalIcon

[What]
Meter=STRING
MeterStyle=Style#Variant#Text
Text=#ItemTitle1#
LeftMouseUpAction=["#ItemLink1#"]
DynamicVariables=1

[When]
Meter=STRING
MeterStyle=Style#Variant#Label
Text=#ItemDate1#
DynamicVariables=1