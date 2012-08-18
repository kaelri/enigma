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
UpdateDivider=-1
MeasureName=MeasureFeed
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
Text=#ItemTitle1#
LeftMouseUpAction=["#ItemLink1#"]
DynamicVariables=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text=#ItemDate1#
DynamicVariables=1