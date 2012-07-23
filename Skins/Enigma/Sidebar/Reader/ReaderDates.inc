[Variables]
CurrentFeed=1
WebParserSubstitute="<![CDATA[":"","]]>":"","/PRE&gt;":"","PRE&gt;":"","&nbsp;":" ","'s Facebook Notifications":"","Top Stories - Google ":""
ReaderWriteEvents=0

;---------------------------------------------------------------------
; MEASURES

[MeasureActivateTabs]
Measure=Script
ScriptFile=#@#Measures\Tabs.lua
UpdateDivider=-1
Type=Reader
TotalTabs=8

[MeasureFeed1]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL1#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"

[MeasureFeed2]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL2#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab2
Disabled=1

[MeasureFeed3]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL3#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab3
Disabled=1

[MeasureFeed4]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL4#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab4
Disabled=1

[MeasureFeed5]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL5#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab5
Disabled=1

[MeasureFeed6]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL6#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab6
Disabled=1

[MeasureFeed7]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL7#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab7
Disabled=1

[MeasureFeed8]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL8#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
FinishAction=!CommandMeasure "MeasureScriptReader" "Update()"
Group=Tab8
Disabled=1

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
Disabled=1
FeedMeasureName=MeasureFeed1
MinItems=4
SubString=#WebParserSubstitute#
WriteEvents=#ReaderWriteEvents#
EventFile=#ReaderEventFile#

[MeasureActive1]
Measure=Calc
Formula=#CurrentFeed#=1
DynamicVariables=1
Group=Tab2
Disabled=1

[MeasureActive2]
Measure=Calc
Formula=#CurrentFeed#=2
DynamicVariables=1
Group=Tab2
Disabled=1

[MeasureActive3]
Measure=Calc
Formula=#CurrentFeed#=3
DynamicVariables=1
Group=Tab3
Disabled=1

[MeasureActive4]
Measure=Calc
Formula=#CurrentFeed#=4
DynamicVariables=1
Group=Tab4
Disabled=1

[MeasureActive5]
Measure=Calc
Formula=#CurrentFeed#=5
DynamicVariables=1
Group=Tab5
Disabled=1

[MeasureActive6]
Measure=Calc
Formula=#CurrentFeed#=6
DynamicVariables=1
Group=Tab6
Disabled=1

[MeasureActive7]
Measure=Calc
Formula=#CurrentFeed#=7
DynamicVariables=1
Group=Tab7
Disabled=1

[MeasureActive8]
Measure=Calc
Formula=#CurrentFeed#=8
DynamicVariables=1
Group=Tab8
Disabled=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleReaderBackground

[Border]
Meter=IMAGE
MeterStyle=StyleReaderBorder

[Icon]
Meter=IMAGE
MeterStyle=#ReaderIconStyle#
LeftMouseUpAction=["#FeedLink#"]

[Title]
Meter=STRING
MeterStyle=StyleReaderTitle
Text=#FeedTitle#
LeftMouseUpAction=["#FeedLink#"]
ToolTipText=#FeedLink#

;-----------------------
; ITEMS

[ItemWhat1]
Meter=STRING
MeterStyle=StyleReaderText | StyleReaderTextSubheading | StyleReaderTextFirst
Text=#ItemTitle1#
LeftMouseUpAction=["#ItemLink1#"]

[ItemWhen1]
Meter=STRING
MeterStyle=StyleReaderSubtext
Text=#ItemDate1#

[ItemWhat2]
Meter=STRING
MeterStyle=StyleReaderText | StyleReaderTextSubheading
Text=#ItemTitle2#
LeftMouseUpAction=["#ItemLink2#"]

[ItemWhen2]
Meter=STRING
MeterStyle=StyleReaderSubtext
Text=#ItemDate2#

[ItemWhat3]
Meter=STRING
MeterStyle=StyleReaderText | StyleReaderTextSubheading
Text=#ItemTitle3#
LeftMouseUpAction=["#ItemLink3#"]

[ItemWhen3]
Meter=STRING
MeterStyle=StyleReaderSubtext
Text=#ItemDate3#

[ItemWhat4]
Meter=STRING
MeterStyle=StyleReaderText | StyleReaderTextSubheading
Text=#ItemTitle4#
LeftMouseUpAction=["#ItemLink4#"]

[ItemWhen4]
Meter=STRING
MeterStyle=StyleReaderSubtext
Text=#ItemDate4#

;-----------------------
; BORDER & GRABBERS

[BorderBottom]
Meter=IMAGE
MeterStyle=StyleReaderBorderBottom

[Grabber1]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive1] | StyleReaderGrabberFirst
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(1)"][!SetVariable Reset 0][!Update]
Group=Tab2
Hidden=1

[Grabber2]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive2]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(2)"][!SetVariable Reset 0][!Update]
Group=Tab2
Hidden=1

[Grabber3]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive3]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(3)"][!SetVariable Reset 0][!Update]
Group=Tab3
Hidden=1

[Grabber4]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive4]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(4)"][!SetVariable Reset 0][!Update]
Group=Tab4
Hidden=1

[Grabber5]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive5]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(5)"][!SetVariable Reset 0][!Update]
Group=Tab5
Hidden=1

[Grabber6]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive6]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(6)"][!SetVariable Reset 0][!Update]
Group=Tab6
Hidden=1

[Grabber7]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive7]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(7)"][!SetVariable Reset 0][!Update]
Group=Tab7
Hidden=1

[Grabber8]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive8]
LeftMouseUpAction=[!CommandMeasure "MeasureScriptReader" "SwitchTo(8)"][!SetVariable Reset 0][!Update]
Group=Tab8
Hidden=1