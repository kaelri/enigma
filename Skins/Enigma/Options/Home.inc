[Variables]
PanelHeight=395
LabelsQueue=

;---------------------------------------------------------------------
; MEASURES

[MeasureFeedTitle]
Measure=Plugin
Plugin=WebParser
Url=http://enigma.kaelri.com/update/version.xml
RegExp=(?siU)<item>.*<title.*>(.*)</title>.*<version.*>(.*)</version>.*<link.*>(.*)</link>
UpdateRate=3600
StringIndex=1
FinishAction=[!EnableMeasure MeasureVersionCheck]

[MeasureFeedVersion]
Measure=Plugin
Plugin=WebParser
Url=[MeasureFeedTitle]
StringIndex=2

[MeasureFeedLink]
Measure=Plugin
Plugin=WebParser
Url=[MeasureFeedTitle]
StringIndex=3

[MeasurePreviewThumbnail]
Measure=Plugin
Plugin=WebParser
Url=http://enigma.kaelri.com/update/preview-150px.png
Download=1
UpdateRate=3600

[MeasureVersionCheck]
Measure=Calc
Formula=MeasureFeedVersion - #EnigmaVersionAbsolute#
IfAboveValue=0
IfAboveAction=[!SetOption UpdateText MeterStyle "StyleText | StyleUpdateTextYes"][!SetOption UpdateCaption MeterStyle "StyleNotes | StyleUpdateNotesYes"][!ShowMeter UpdatePreview][!Redraw]
IfEqualValue=0
IfEqualAction=[!SetOption UpdateText MeterStyle "StyleText | StyleUpdateTextNo"][!SetOption UpdateCaption MeterStyle "StyleNotes | StyleUpdateNotesNo"][!HideMeter UpdatePreview][!Redraw]
IfBelowValue=0
IfBelowAction=[!SetOption UpdateText MeterStyle "StyleText | StyleUpdateTextNo"][!SetOption UpdateCaption MeterStyle "StyleNotes | StyleUpdateNotesAlpha"][!HideMeter UpdatePreview][!Redraw]
Disabled=1

;---------------------------------------------------------------------
; METERS

[AboutName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text="A  B  O  U  T"

[VersionName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirstSub
Text="Version"

[VersionText]
Meter=STRING
MeterStyle=StyleText
Text="#EnigmaVersion#"
FontColor=255,255,255,217

[DateName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirstSub
Text="Date"

[DateText]
Meter=STRING
MeterStyle=StyleText
Text="#EnigmaDate#"
FontColor=255,255,255,217

[RevName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirstSub
Text="Platform"

[RevText]
Meter=STRING
MeterStyle=StyleText
Text="Rainmeter #EnigmaRev#"
FontColor=#ColorLink#
LeftMouseUpAction=["http://rainmeter.net"]
ToolTipText="Visit Rainmeter.net."

[LicenseName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirstSub
Text="License"

[LicenseText]
Meter=STRING
MeterStyle=StyleText
Text="Creative Commons BY-NC-SA 3.0"
FontColor=#ColorLink#
LeftMouseUpAction=["http://enigma.kaelri.com/index.php?p=legal"]
ToolTipText="View license and credits."

[AuthorName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirstSub
Text="Author"

[AuthorText]
Meter=STRING
MeterStyle=StyleText
Text="Kaelri"
FontColor=#ColorLink#
LeftMouseUpAction=["http://kaelri.com"]
ToolTipText="View author's website."

;----------------------------------------------
; UPDATE

[UpdateName]
Meter=STRING
MeterStyle=StyleName
Text="Update"

;-----------------------

[UpdateText]
Meter=STRING
MeterStyle=StyleText | StyleUpdateTextConnecting

[UpdateCaption]
Meter=STRING
MeterStyle=StyleNotes | StyleUpdateNotesConnecting
H=100

[UpdatePreview]
Meter=Image
MeasureName=MeasurePreviewThumbnail
X=r
Y=15r
LeftMouseUpAction=["[MeasureFeedLink]"]
ToolTipText=[MeasureFeedLink]
DynamicVariables=1
Hidden=1

;-----------------------

[StyleUpdateTextConnecting]
Text="Connecting to GitHub..."
LeftMouseUpAction=["https://github.com/Kaelri/Enigma"]

[StyleUpdateNotesConnecting]
Text=If this message does not disappear, Enigma may be unable to check for updates. Check your network and firewall settings, or click above to go to GitHub.

;-----------------------

[StyleUpdateTextYes]
DynamicVariables=1
Text=[MeasureFeedTitle]
LeftMouseUpAction=["[MeasureFeedLink]"]
ToolTipText=[MeasureFeedLink]

[StyleUpdateNotesYes]
DynamicVariables=1
Text=An update is available!

;-----------------------

[StyleUpdateTextNo]
FontColor=255,255,255,128
DynamicVariables=1
Text=None.
LeftMouseUpAction=["[MeasureFeedLink]"]
ToolTipText=[MeasureFeedLink]

[StyleUpdateNotesNo]
Text=Your version of Enigma is up to date.

;-----------------------

[StyleUpdateNotesAlpha]
Text=Your version of Enigma is ahead of the latest release. Thanks for being an alpha tester!

;----------------------------------------------

[ReadmeName]
Meter=STRING
MeterStyle=StyleName
Text="Readme"
Y=90r

[ReadmeText]
Meter=STRING
MeterStyle=StyleText
Text="View"
LeftMouseUpAction=["#ROOTCONFIGPATH#About.txt"]
ToolTipText="#ROOTCONFIGPATH#About.txt"

[ReadmeCaption]
Meter=STRING
MeterStyle=StyleNotes
H=15
Text="Contact, credits and changelog."

;-----------------------

[WebsiteName]
Meter=STRING
MeterStyle=StyleName
Text="Website"

[WebsiteText]
Meter=STRING
MeterStyle=StyleText
Text="enigma.kaelri.com"
LeftMouseUpAction=["http://enigma.kaelri.com/index.php?p=downloads"]

[WebsiteCaption]
Meter=STRING
MeterStyle=StyleNotes
H=15
Text="Downloads, FAQ and support links."