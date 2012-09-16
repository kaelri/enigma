[Variables]
CurrentFeed=1
WebParserSubstitute="<![CDATA[":"","]]>":"","/PRE&gt;":"","PRE&gt;":"","&nbsp;":" ","'s Facebook Notifications":"","Top Stories - Google ":""

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
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(1)

[MeasureFeed2]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL2#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(2)
Group=Tab2
Disabled=1

[MeasureFeed3]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL3#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(3)
Group=Tab3
Disabled=1

[MeasureFeed4]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL4#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(4)
Group=Tab4
Disabled=1

[MeasureFeed5]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL5#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(5)
Group=Tab5
Disabled=1

[MeasureFeed6]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL6#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(6)
Group=Tab6
Disabled=1

[MeasureFeed7]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL7#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(7)
Group=Tab7
Disabled=1

[MeasureFeed8]
Measure=Plugin
Plugin=WebParser
UpdateRate=#ReaderUpdateRate#
URL=#ReaderURL8#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh(8)
Group=Tab8
Disabled=1

;-----------------------

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
MeasureName=MeasureFeed1
MinItems=4
WriteEvents=#ReaderWriteEvents#
EventFile=#ReaderEventFile#
FinishAction=[!UpdateMeasureGroup "FeedData"][!UpdateMeterGroup "FeedData"][!Redraw][!SetVariable Reset 0]

;-----------------------

[MeasureActive1]
Measure=Calc
Formula=#CurrentFeed#=1
DynamicVariables=1
Group=FeedData | Tab2
Disabled=1

[MeasureActive2]
Measure=Calc
Formula=#CurrentFeed#=2
DynamicVariables=1
Group=FeedData | Tab2
Disabled=1

[MeasureActive3]
Measure=Calc
Formula=#CurrentFeed#=3
DynamicVariables=1
Group=FeedData | Tab3
Disabled=1

[MeasureActive4]
Measure=Calc
Formula=#CurrentFeed#=4
DynamicVariables=1
Group=FeedData | Tab4
Disabled=1

[MeasureActive5]
Measure=Calc
Formula=#CurrentFeed#=5
DynamicVariables=1
Group=FeedData | Tab5
Disabled=1

[MeasureActive6]
Measure=Calc
Formula=#CurrentFeed#=6
DynamicVariables=1
Group=FeedData | Tab6
Disabled=1

[MeasureActive7]
Measure=Calc
Formula=#CurrentFeed#=7
DynamicVariables=1
Group=FeedData | Tab7
Disabled=1

[MeasureActive8]
Measure=Calc
Formula=#CurrentFeed#=8
DynamicVariables=1
Group=FeedData | Tab8
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
Group=FeedData
MeterStyle=#ReaderIconStyle#
LeftMouseUpAction=["#FeedLink#"]

[Title]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderTitle
Text=#FeedTitle#
LeftMouseUpAction=["#FeedLink#"]
ToolTipText=#FeedLink#

;-----------------------
; ITEMS

[ItemWhat1]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderText | StyleReaderTextSubheading | StyleReaderTextFirst
Text=#Item1Title#
LeftMouseUpAction=["#Item1Link#"]

[ItemWhen1]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderSubtext
Text=#Item1Date#

[ItemWhat2]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderText | StyleReaderTextSubheading
Text=#Item2Title#
LeftMouseUpAction=["#Item2Link#"]

[ItemWhen2]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderSubtext
Text=#Item2Date#

[ItemWhat3]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderText | StyleReaderTextSubheading
Text=#Item3Title#
LeftMouseUpAction=["#Item3Link#"]

[ItemWhen3]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderSubtext
Text=#Item3Date#

[ItemWhat4]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderText | StyleReaderTextSubheading
Text=#Item4Title#
LeftMouseUpAction=["#Item4Link#"]

[ItemWhen4]
Meter=STRING
Group=FeedData
MeterStyle=StyleReaderSubtext
Text=#Item4Date#

;-----------------------
; BORDER & GRABBERS

[BorderBottom]
Meter=IMAGE
MeterStyle=StyleReaderBorderBottom

[Grabber1]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive1] | StyleReaderGrabberFirst
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(1)"
Group=FeedData | Tab2
Hidden=1

[Grabber2]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive2]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(2)"
Group=FeedData | Tab2
Hidden=1

[Grabber3]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive3]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(3)"
Group=FeedData | Tab3
Hidden=1

[Grabber4]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive4]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(4)"
Group=FeedData | Tab4
Hidden=1

[Grabber5]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive5]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(5)"
Group=FeedData | Tab5
Hidden=1

[Grabber6]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive6]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(6)"
Group=FeedData | Tab6
Hidden=1

[Grabber7]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive7]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(7)"
Group=FeedData | Tab7
Hidden=1

[Grabber8]
Meter=IMAGE
MeterStyle=StyleReaderGrabber | StyleReaderGrabber[MeasureActive8]
LeftMouseUpAction=!CommandMeasure "MeasureScriptReader" "Show(8)"
Group=FeedData | Tab8
Hidden=1