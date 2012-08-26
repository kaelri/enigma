[Variables]
WebParserSubstitute="<![CDATA[":"","]]>":"","/PRE&gt;":"","PRE&gt;":"","&nbsp;":" ","'s Facebook Notifications":"","Top Stories - Google ":""
ReaderWriteEvents=0

;---------------------------------------------------------------------
; MEASURES

[MeasureFeed]
Measure=Plugin
Plugin=WebParser
UpdateRate=600
Url=#ReaderURL#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh()

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
MeasureName=MeasureFeed
MaxItems=1
WriteEvents=#ReaderWriteEvents#
EventFile=#ReaderEventFile#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | #ReaderIconStyle#

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
Text=#Item1Title#
LeftMouseUpAction=["#Item1Link#"]
DynamicVariables=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text=#Item1Date#
DynamicVariables=1