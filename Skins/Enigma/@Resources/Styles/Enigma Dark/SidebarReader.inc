;--------------------------------------------------------------------------------------------
; SIDEBAR READER

[Variables]
FeedTitle=Loading...
ItemTitle1=
ItemTitle2=
ItemTitle3=
ItemTitle4=
ItemTitle5=
ItemTitle6=
ItemTitle7=
ItemTitle8=
ItemDate1=
ItemDate2=
ItemDate3=
ItemDate4=
ItemDate5=
ItemDate6=
ItemDate7=
ItemDate8=

;---------------------------------------------------------------------
; READER

[StyleReaderBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersTop#

[StyleReaderBackground]
H=175

[StyleReaderIcon]
ImageName=#@#Images\Reader.#ColorImage#.png
X=10
Y=15
W=25
H=25
DynamicVariables=1

[StyleReaderTitle]
X=37
Y=20
H=15
W=(#SidebarWidth#-49)
ClipString=1
StringStyle=BOLD
FontColor=#Color1#
FontSize=#Size3#
FontFace=#Font#
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleReaderText]
X=12
Y=15r
H=10
W=(#SidebarWidth#-24)
ClipString=1
StringStyle=NORMAL
FontColor=#Color1#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1
MouseOverAction=[!SetOption "#CURRENTSECTION#" "FontColor" "#ColorLink#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "FontColor" "#Color1#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[StyleReaderTextSubheading]
Y=16r
StringStyle=BOLD

[StyleReaderTextFirst]
Y=42

[StyleReaderSubtext]
X=22
Y=14r
H=10
W=(#SidebarWidth#-34)
ClipString=1
StringStyle=NORMAL
FontColor=#Color2#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

;-----------------------
; BORDER

[StyleReaderBorderBottom]
SolidColor=#ColorBorder4#
X=10
Y=25r
W=(#SidebarWidth#-26)
H=1
Hidden=#HideBordersBottom#

;-----------------------
; GRABBERS

[StyleReaderGrabber]
X=R
Y=r
H=15
W=15
DynamicVariables=1

[StyleReaderGrabberFirst]
X=(#SidebarWidth#-(#NumberOfTabs#*15)-10)
Y=-7r

[StyleReaderGrabber0]
ImageName=#@#Images\Grabber.#ColorImage#.png
ImageAlpha=128
ToolTipWidth=#SidebarWidth#
ToolTipText=Click to switch to this page.

[StyleReaderGrabber1]
ImageName=#@#Images\GrabberActive.#ColorImage#.png

;---------------------------------------------------------------------
; FACEBOOK

[StyleReaderIconFacebook]
ImageName=#@#Images\Facebook.#ColorImage#.png

;---------------------------------------------------------------------
; GCAL

[StyleReaderIconGcal]
ImageName=#@#Images\Gcal.#ColorImage#.png

;---------------------------------------------------------------------
; GMAIL

[StyleReaderIconGmail]
ImageName=#@#Images\Gmail.0.#ColorImage#.png

;---------------------------------------------------------------------
; REMEMBER THE MILK

[StyleReaderIconRTM]
ImageName=#@#Images\RememberTheMilk.#ColorImage#.png

;---------------------------------------------------------------------
; TWITTER

[StyleReaderIconTwitter]
ImageName=#@#Images\Twitter.#ColorImage#.png