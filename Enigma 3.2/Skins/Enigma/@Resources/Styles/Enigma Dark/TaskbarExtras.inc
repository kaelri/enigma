;---------------------------------------------------------------------
; EXTRAS: TRAY CLOCK

[Rainmeter]
Group=EnigmaTaskbar
MiddleMouseUpAction=!Refresh

;-----------------------

[StyleTrayClockBackground]
SolidColor=#ColorTransparent#
X=0
Y=0
W=260
H=#TaskbarHeight#

[StyleTrayClockDate]
X=200
Y=((#TaskbarHeight#-10)/2)
H=10
W=200
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
Postfix=" |"

[StyleTrayClockDate2]
X=230
Y=((#TaskbarHeight#-15)/2)
H=15
W=80
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
StringAlign=CENTER
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleTrayClockDate3]
X=260
Y=((#TaskbarHeight#-10)/2)
H=15
W=(#TaskbarSkinWidth#/2)
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
;Postfix=" |"

;---------------------------------------------------------------------
; EXTRAS: TRAY SYSTEMS

[StyleTraySystemsBackground]
SolidColor=#ColorTransparent#
X=0
Y=0
W=260
H=#TaskbarHeight#

[StyleTraySystemsText]
Y=((#TaskbarHeight#-15)/2)
H=15
W=80
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleTraySystemsLabel]
X=r
Y=3r
H=15
W=40
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1
Postfix=" |"

[StyleTraySystemsCPU]
X=40

[StyleTraySystemsRAM]
X=100

[StyleTraySystemsHDD]
X=160

[StyleTraySystemsPWR]
X=230

;---------------------------------------------------------------------
; EXTRAS: DOCK

[StyleDockButton1]
ImageName=#@#Images\Launcher\Launcher.#ColorImage#.png

[StyleDockButton2]
ImageName=#@#Images\Launcher\LauncherActive.#ColorImage#.png

[StyleDockBackground]
ImageName=#@#Images\Taskbar\NootoVS Taskbar.jpg
W=615
H=#TaskbarHeight#

[StyleDockBorderFirst]
X=0
W=10

[StyleDockIconFirst]
X=15

[StyleDockIcon]
X=15r
Y=((#TaskbarHeight#-25)/2)
H=25
W=25

[StyleDockText]
X=30r
Y=((#TaskbarHeight#-10)/2)
H=10
W=70
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=LEFT
StringStyle=NORMAL
StringCase=UPPER
AntiAlias=1

[StyleDockBorder]
SolidColor=0, 0, 0, 192
X=75r
W=5
H=#TaskbarHeight#

[StyleDockBorderLast]
X=605
W=10