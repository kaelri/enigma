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
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
Disabled=1
FeedMeasureName=MeasureFeed

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

[Number]
Meter=STRING
MeterStyle=Style#Variant#Text
Text=#NumberOfItems#
LeftMouseUpAction=["#ItemLink1#"][!Redraw]
DynamicVariables=1

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
Text="MAIL"