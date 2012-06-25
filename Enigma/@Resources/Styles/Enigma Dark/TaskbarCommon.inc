;--------------------------------------------------------------------------------------------
; TASKBAR

[Rainmeter]
Group=EnigmaTaskbar
MiddleMouseUpAction=!Refresh

[Variables]
SkinWidthMultiplier=1
TaskbarSkinWidth=(80*#SkinWidthMultiplier#)
; Each skin should override "SkinWidthMultiplier" with a value appropriate for that skin (1, 1.5, or 2).

;-----------------------
; NORMAL

[StyleNormalBackground]
SolidColor=#ColorTransparent#
X=0
Y=0
W=#TaskbarSkinWidth#
H=#TaskbarHeight#

[StyleNormalText]
X=(#TaskbarSkinWidth#/2)
Y=((#TaskbarHeight#-25)/2)
H=15
W=#TaskbarSkinWidth#
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
StringAlign=CENTER
StringStyle=NORMAL
AntiAlias=1
ClipString=1
ToolTipWidth=#SidebarWidth#

[StyleNormalLabel]
X=r
Y=R
H=15
W=#TaskbarSkinWidth#
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=CENTER
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleNormalIcon]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleNormalBarFirst]
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
SolidColor=#ColorTransparent#
X=0
Y=0
W=(#TaskbarSkinWidth#*1.5)
H=#TaskbarHeight#

[StyleMiniText]
X=(#TaskbarSkinWidth#/2)
Y=((#TaskbarHeight#-15)/2)
H=15
W=#TaskbarSkinWidth#
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
ToolTipWidth=#SidebarWidth#

[StyleMiniLabel]
X=r
Y=3r
H=15
W=(#TaskbarSkinWidth#/2)
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
Postfix=" |"

[StyleMiniIcon]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleMiniBarFirst]
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
SolidColor=#ColorTransparent#
X=0
Y=0
W=(#TaskbarSkinWidth#*1.5)
H=(#TaskbarHeight#/2)

[StyleTinyText]
X=(#TaskbarSkinWidth#/2)
Y=(((#TaskbarHeight#/2)-10)/2)
H=10
W=#TaskbarSkinWidth#
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size4#
StringAlign=LEFT
StringStyle=BOLD
AntiAlias=1
ClipString=1
ToolTipWidth=#SidebarWidth#

[StyleTinyLabel]
X=r
Y=r
H=10
W=(#TaskbarSkinWidth#/2)
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
Postfix=" ·"

[StyleTinyIcon]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleTinyBarFirst]
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
SolidColor=#ColorTransparent#
X=0
Y=0
W=(#TaskbarSkinWidth#+35)
H=#TaskbarHeight#

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
W=#TaskbarSkinWidth#
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
ToolTipWidth=#SidebarWidth#

[StyleIconLabel]
X=r
Y=R
H=10
W=#TaskbarSkinWidth#
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleIconBarFirst]
X=R
Y=5r

[StyleIconBar]
X=3r
Y=r
H=15
W=2
BarColor=#Color3#
;BarColor=#Color1#
;SolidColor=#Color3#
BarOrientation=VERTICAL

;-----------------------
; ICON-RIGHT

[StyleIconRightBackground]
SolidColor=#ColorTransparent#
X=0
Y=0
W=(#TaskbarSkinWidth#+35)
H=#TaskbarHeight#

[StyleIconRightIcon]
X=(#TaskbarSkinWidth#+5)
Y=((#TaskbarHeight#-25)/2)
W=25
H=25
ToolTipWidth=#SidebarWidth#

[StyleIconRightText]
X=(#TaskbarSkinWidth#)
Y=((#TaskbarHeight#-22)/2)
H=12
W=#TaskbarSkinWidth#
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
ToolTipWidth=#SidebarWidth#

[StyleIconRightLabel]
X=r
Y=R
H=10
W=#TaskbarSkinWidth#
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleIconRightBarFirst]
X=R
Y=5r

[StyleIconRightBar]
X=3r
Y=r
H=15
W=2
BarColor=#Color3#
;BarColor=#Color1#
;SolidColor=#Color3#
BarOrientation=VERTICAL

;-----------------------
; TEXTLESS

[StyleTextlessBackground]
SolidColor=#ColorTransparent#
X=0
Y=0
W=35
H=#TaskbarHeight#

[StyleTextlessIcon]
X=5
Y=((#TaskbarHeight#-25)/2)
W=25
H=25
ToolTipWidth=#SidebarWidth#

[StyleTextlessText]
W=0
H=0
Hidden=1

[StyleTextlessLabel]
W=0
H=0
Hidden=1

[StyleTextlessBarFirst]
X=R
Y=5r

[StyleTextlessBar]
X=3r
Y=r
H=15
W=2
BarColor=#Color3#
;BarColor=#Color1#
;SolidColor=#Color3#
BarOrientation=VERTICAL

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
; GCAL

[StyleGcalIcon]
ImageName=#@#Images\Gcal.#ColorImage#.png

;---------------------------------------------------------------------
; GMAIL

[StyleGmailIcon]
ImageName=#@#Images\Gmail.%1.#ColorImage#.png

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

[StyleNetworkIcon]
ImageName=#@#Images\Net.#ColorImage#.png

;---------------------------------------------------------------------
; RAIN

[StyleRainIcon]
ImageName=#@#Images\Rain.#ColorImage#.png

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
BarColor=#Color1#
SolidColor=#Color3#

[StyleHDDIconRightBar]
X=14r
Y=5r
H=15
W=4
BarColor=#Color1#
SolidColor=#Color3#

[StyleHDDTextlessBar]
X=14r
Y=5r
H=15
W=4
BarColor=#Color1#
SolidColor=#Color3#

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
BarColor=#Color1#
SolidColor=#Color3#

[StylePWRIconRightBar]
X=10r
Y=6r
H=14
W=5
BarColor=#Color1#
SolidColor=#Color3#

[StylePWRTextlessBar]
X=10r
Y=6r
H=14
W=5
BarColor=#Color1#
SolidColor=#Color3#

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
[StyleWeatherMiniIcon]
[StyleWeatherTinyIcon]

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

[StyleWeatherTextlessIcon]
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

[StyleWorldTextlessText]
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

[StyleWorldTextlessLabel]
Text=%2

;---------------------------------------------------------------------
; EXTRAS: DOCK

[StyleDockIcon0]
ImageName=#@#Images\Launcher\Launcher.#ColorImage#.png

[StyleDockIcon1]
ImageName=#@#Images\Launcher\LauncherActive.#ColorImage#.png