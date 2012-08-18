;--------------------------------------------------------------------------------------------
; TASKBAR

[Rainmeter]
Group=EnigmaTaskbar
MiddleMouseUpAction=!Refresh
LeftMouseDoubleClickAction=!ActivateConfig #CURRENTCONFIG#
MouseOverAction=[!SetVariable SkinMouseOver 1][!HideMeterGroup EnigmaMouseout][!ShowMeterGroup EnigmaMouseover][!Redraw]
MouseLeaveAction=[!SetVariable SkinMouseOver 0][!HideMeterGroup EnigmaMouseover][!ShowMeterGroup EnigmaMouseout][!Redraw]
DynamicWindowSize=1

[Variables]
Variant=Normal
TaskbarSkinWidth=60
NumOfBars=0
SkinMouseOver=0

[MeasureTaskbarSkinWidth]
Measure=Script
ScriptFile=#@#Styles\#Stylesheet#\TaskbarSkinWidth.lua
Variant=#Variant#
MinWidth=#TaskbarMinSkinWidth#
MaxWidth=#TaskbarMaxSkinWidth#

;-----------------------
; NORMAL

[StyleNormalBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
ScaleMargins=12,12,12,12
X=0
Y=0
W=(#TaskbarSkinWidth#+10)
H=#TaskbarHeight#
DynamicVariables=1

[StyleNormalText]
X=(#TaskbarSkinWidth#/2+5)
Y=((#TaskbarHeight#-25)/2)
H=15
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
StringAlign=CENTER
StringStyle=NORMAL
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleNormalLabel]
X=r
Y=R
H=15
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=CENTER
StringStyle=NORMAL
AntiAlias=1
DynamicVariables=1

[StyleNormalIcon]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleNormalBar]
X=0
Y=0
W=0
H=0
Hidden=1

;-----------------------
; MINI

[StyleMiniBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
ScaleMargins=12,12,12,12
X=0
Y=0
W=(#TaskbarSkinWidth#+10)
H=#TaskbarHeight#
DynamicVariables=1

[StyleMiniText]
X=(5+[Label:W])
Y=((#TaskbarHeight#-15)/2)
H=15
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
StringStyle=NORMAL
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleMiniLabel]
X=5
Y=3r
H=15
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringStyle=NORMAL
AntiAlias=1
Postfix=" ·"
DynamicVariables=1

[StyleMiniIcon]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleMiniBar]
X=0
Y=0
W=0
H=0
Hidden=1

;-----------------------
; TINY

[StyleTinyBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
ScaleMargins=11,11,11,11
X=0
Y=0
W=(#TaskbarSkinWidth#+10)
H=(#TaskbarHeight#/2)
DynamicVariables=1

[StyleTinyText]
X=(5+[Label:W])
Y=(((#TaskbarHeight#/2)-10)/2)
H=10
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size4#
StringStyle=BOLD
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleTinyLabel]
X=5
Y=r
H=10
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringStyle=NORMAL
AntiAlias=1
Postfix=" ·"
DynamicVariables=1

[StyleTinyIcon]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleTinyBar]
X=0
Y=0
W=0
H=0
Hidden=1

;-----------------------
; ICON

[StyleIconBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
ScaleMargins=12,12,12,12
X=0
Y=0
W=(#TaskbarSkinWidth#+40)
H=#TaskbarHeight#
DynamicVariables=1

[StyleIconIcon]
X=5
Y=((#TaskbarHeight#-25)/2)
W=25
H=25
ToolTipWidth=#SidebarWidth#

[StyleIconText]
X=35
Y=((#TaskbarHeight#-22)/2)
H=12
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleIconLabel]
X=r
Y=R
H=10
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
DynamicVariables=1

[StyleIconBar]
X=0
Y=0
W=0
H=0
Hidden=1

;-----------------------
; ICON-RIGHT

[StyleIconRightBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
ScaleMargins=12,12,12,12
X=0
Y=0
W=(#TaskbarSkinWidth#+40)
H=#TaskbarHeight#
DynamicVariables=1

[StyleIconRightIcon]
X=(#TaskbarSkinWidth#+10)
Y=((#TaskbarHeight#-25)/2)
W=25
H=25
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleIconRightText]
X=(#TaskbarSkinWidth#+5)
Y=((#TaskbarHeight#-22)/2)
H=12
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleIconRightLabel]
X=r
Y=R
H=10
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
DynamicVariables=1

[StyleIconRightBar]
X=0
Y=0
W=0
H=0
Hidden=1

;-----------------------
; ICON-ONLY

[StyleIconOnlyBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
ScaleMargins=12,12,12,12
X=0
Y=0
W=35
H=#TaskbarHeight#

[StyleIconOnlyIcon]
X=5
Y=((#TaskbarHeight#-25)/2)
W=25
H=25
ToolTipWidth=#SidebarWidth#

[StyleIconOnlyText]
W=0
H=0
Hidden=1

[StyleIconOnlyLabel]
W=0
H=0
Hidden=1

[StyleIconOnlyBar]
W=0
H=0
Hidden=1

;---------------------------------------------------------------------
; CLOCK & WORLD

[StyleClockIcon]
ImageName=#TaskbarClockFace#
W=27
H=27

[StyleClockHands]
X=r
Y=r
W=27
H=27
StartAngle=4.7123889
RotationAngle=6.2831853
LineStart=0
AntiAlias=1
Solid=0

[StyleClockSeconds]
LineWidth=1
LineLength=10
LineColor=#ColorLink2#
ValueReminder=60

[StyleClockHours]
LineWidth=2
LineLength=6
LineColor=#Color1#
ValueReminder=43200

[StyleClockMinutes]
LineWidth=2
LineLength=9
LineColor=#Color1#
ValueReminder=3600

;---------------------------------------------------------------------
; LAUNCHER

[StyleLauncherNormalTextClosed]
[StyleLauncherNormalTextRunning]
Prefix=•
[StyleLauncherMiniTextClosed]
[StyleLauncherMiniTextRunning]
Prefix=•
[StyleLauncherTinyTextClosed]
[StyleLauncherTinyTextRunning]
Prefix=•
[StyleLauncherIconTextClosed]
[StyleLauncherIconTextRunning]
[StyleLauncherIconRightTextClosed]
[StyleLauncherIconRightTextRunning]
[StyleLauncherIconOnlyTextClosed]
[StyleLauncherIconOnlyTextRunning]

[StyleLauncherNormalIconClosed]
[StyleLauncherNormalIconRunning]
[StyleLauncherMiniIconClosed]
[StyleLauncherMiniIconRunning]
[StyleLauncherTinyIconClosed]
[StyleLauncherTinyIconRunning]
[StyleLauncherIconIconClosed]
ImageAlpha=128
[StyleLauncherIconIconRunning]
[StyleLauncherIconRightIconClosed]
ImageAlpha=128
[StyleLauncherIconRightIconRunning]
[StyleLauncherIconOnlyIconClosed]
ImageAlpha=128
[StyleLauncherIconOnlyIconRunning]

;---------------------------------------------------------------------
; LOCATION

[StyleLocationIcon]
ImageName=#@#Images\Location.#ColorImage#.png

;---------------------------------------------------------------------
; MOON

[StyleMoonIcon]
ImageName=#@#Images\Moon\Moon.png
H=24
W=24

[StyleMoonIconOverlay]
ImageName=#@#Images\Moon\%1.png

;---------------------------------------------------------------------
; MUSIC

[StyleMusicIconBack]
ImageName=#@#Images\MusicAlbum.#ColorImage#.png

[StyleMusicIcon]
X=1r
Y=1r
W=23
H=23

;---------------------------------------------------------------------
; NETWORK

[StyleNetworkBackground]
W=(34+#NumOfBars#*3)

[StyleNetworkIcon]
ImageName=#@#Images\Net.#ColorImage#.png

[StyleNetworkBarFirst]
X=R
Y=5r

[StyleNetworkBar]
X=3r
Y=r
H=15
W=2
BarColor=#Color3#
;BarColor=#Color1#
;SolidColor=#Color3#
BarOrientation=VERTICAL

;---------------------------------------------------------------------
; RAIN

[StyleRainIcon]
ImageName=#@#Images\Rain.#ColorImage#.png

;---------------------------------------------------------------------
; READER

[StyleReaderIcon]
ImageName=#@#Images\Reader.#ColorImage#.png

[StyleGcalIcon]
ImageName=#@#Images\Gcal.#ColorImage#.png

[StyleGmailIcon]
ImageName=#@#Images\Gmail.%1.#ColorImage#.png

[StyleFacebookIcon]
ImageName=#@#Images\Facebook.#ColorImage#.png

[StyleRTMIcon]
ImageName=#@#Images\RememberTheMilk.#ColorImage#.png

;---------------------------------------------------------------------
; RECYCLER

[StyleRecyclerIcon]
ImageName=#@#Images\Recycler.%1.#ColorImage#.png

;---------------------------------------------------------------------
; SUN

[StyleSunIcon]
ImageName=#@#Images\Sun.#ColorImage#.png

;---------------------------------------------------------------------
; SYSTEM

[StyleSystemIcon]
ImageName=#@#Images\System.#ColorImage#.png
W=28
H=28

;---------------------------------------------------------------------
; SYSTEM\DRIVE

[StyleHDDIcon]
ImageName=#@#Images\HDD.#ColorImage#.png
W=33
H=33

[StyleHDDNormalBar]
[StyleHDDMiniBar]
[StyleHDDTinyBar]

[StyleHDDIconBar]
X=14r
Y=5r
H=15
W=4
Hidden=0
BarColor=#Color1#
SolidColor=#Color3#
BarOrientation=VERTICAL

[StyleHDDIconRightBar]
X=14r
Y=5r
H=15
W=4
Hidden=0
BarColor=#Color1#
SolidColor=#Color3#
BarOrientation=VERTICAL

[StyleHDDIconOnlyBar]
X=14r
Y=5r
H=15
W=4
Hidden=0
BarColor=#Color1#
SolidColor=#Color3#
BarOrientation=VERTICAL

;---------------------------------------------------------------------
; SYSTEM\PWR

[StylePWRIcon]
ImageName=#@#Images\PWR.#ColorImage#.png

[StylePWRNormalBar]
[StylePWRMiniBar]
[StylePWRTinyBar]

[StylePWRIconBar]
X=10r
Y=6r
H=14
W=5
Hidden=0
BarColor=#Color1#
SolidColor=#Color3#
BarOrientation=VERTICAL

[StylePWRIconRightBar]
X=10r
Y=6r
H=14
W=5
Hidden=0
BarColor=#Color1#
SolidColor=#Color3#
BarOrientation=VERTICAL

[StylePWRIconOnlyBar]
X=10r
Y=6r
H=14
W=5
Hidden=0
BarColor=#Color1#
SolidColor=#Color3#
BarOrientation=VERTICAL

;---------------------------------------------------------------------
; TOGGLE

[StyleToggleIcon]
ImageName=#@#Images\Sidebar.#ColorImage#.png

;---------------------------------------------------------------------
; VOLUME

[StyleVolumeIcon]
ImageName=#@#Images\Volume.%1.#ColorImage#.png

;---------------------------------------------------------------------
; WEATHER

[StyleWeatherNormalIcon]
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherMiniIcon]
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherTinyIcon]
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherIconIcon]
X=2
Y=((#TaskbarHeight#-33)/2)
W=33
H=33
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherIconRightIcon]
X=(#TaskbarSkinWidth#+7)
Y=((#TaskbarHeight#-33)/2)
W=33
H=33
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherIconOnlyIcon]
X=7
Y=((#TaskbarHeight#-33)/2)
W=33
H=33
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

;---------------------------------------------------------------------
; WORLD

[StyleWorldNormalText]
Text=%1

[StyleWorldMiniText]
Text=%1

[StyleWorldTinyText]
Text=%1

[StyleWorldIconText]
Text=%2

[StyleWorldIconRightText]
Text=%2

[StyleWorldIconOnlyText]
Text=%2

;-----------------------

[StyleWorldNormalLabel]
Text=%1

[StyleWorldMiniLabel]
Text=%1

[StyleWorldTinyLabel]
Text=%1

[StyleWorldIconLabel]
Text=%2

[StyleWorldIconRightLabel]
Text=%2

[StyleWorldIconOnlyLabel]
Text=%2

;---------------------------------------------------------------------
; EXTRAS: DOCK

[StyleDockIcon0]
ImageName=#@#Images\Launcher\Launcher.#ColorImage#.png

[StyleDockIcon1]
ImageName=#@#Images\Launcher\LauncherActive.#ColorImage#.png