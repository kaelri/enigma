[Variables]
WebParserSubstitute="<![CDATA[":"","]]>":"","/PRE&gt;":"","PRE&gt;":"","&nbsp;":" ","'s Facebook Notifications":"","Top Stories - Google ":""

;---------------------------------------------------------------------
; MEASURES

[MeasureFeed]
Measure=Plugin
Plugin=WebParser
UpdateRate=120
URL=https://#GmailUsername#:#GmailPassword#@gmail.google.com/gmail/feed/atom
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh()

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
MeasureName=MeasureFeed

[MeasureNewMail]
Measure=CALC
Formula=#NumberOfItems#>0
DynamicVariables=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleGmailIcon
MeasureName=MeasureNewMail
LeftMouseUpAction=["#FeedLink#]
DynamicVariables=1

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
Text=#NumberOfItems#
LeftMouseUpAction=["#Item1Link#"][!Redraw]
DynamicVariables=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="MAIL"