;---------------------------------------------------------------------
; SIDEBAR WORLD

[StyleWorldBackground]
H=102

[StyleWorldBorder]
SolidColor=#ColorBorder2#
X=50
Y=5
W=(#SidebarWidth#-60)
H=1
Hidden=#HideBordersTop#

[StyleWorldBorder2]
SolidColor=#ColorBorder2#
X=10
Y=97
W=(#SidebarWidth#-35)
H=1
Hidden=#HideBordersBottom#

[StyleWorldTexture]
ImageName=#@#Images\World.#ColorImage#.png
X=((#SidebarWidth#-102)/2)
Y=1
H=102
W=102

;-----------------------
; CLOCK

[StyleWorldClock]
ImageName=#SidebarWorldClockFace#
X=10
Y=0
W=60
H=60
OffsetX=0
OffsetY=0

[StyleWorldSeconds]
X=r
Y=r
W=60
H=60
LineWidth=1
StartAngle=4.7123889
RotationAngle=6.2831853
LineLength=21
LineStart=0
AntiAlias=1
LineColor=#ColorLink2#
Solid=0
ValueReminder=60

[StyleWorldHours]
LineWidth=2
LineLength=14
LineColor=#Color1#
ValueReminder=43200

[StyleWorldMinutes]
LineWidth=2
LineLength=20
LineColor=#Color1#
ValueReminder=3600

;-----------------------
; TEXT

[StyleWorldCity]
X=(#SidebarWidth#-13)
Y=15
W=150
H=15
StringStyle=BOLD
StringAlign=RIGHT
FontColor=#Color1#
FontSize=#Size2#
FontFace=#Font#
AntiAlias=1

[StyleWorldLatLon]
X=r
Y=15r
H=15
W=150
StringStyle=BOLD
StringAlign=RIGHT
FontColor=#Color3#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1

[StyleWorldDigital2]
X=r
Y=34r
W=150
H=15
StringStyle=BOLD
StringAlign=RIGHT
FontColor=#Color2#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1

;-------------------------
; TEXT 2 and WEATHER

[StyleWorldIcon]
X=(#SidebarWidth#-43)
Y=79
W=33
H=33
ImageName=#@#Images\Moxaweather\%1.#ColorImage#.png

[StyleWorldText]
X=8
Y=2r
H=15
W=150
StringStyle=BOLD
StringAlign=LEFT
FontColor=#Color2#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1

[StyleWorldDigital]
X=r
Y=-17r
W=150
H=15
StringStyle=BOLD
StringAlign=LEFT
FontColor=#Color2#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1
