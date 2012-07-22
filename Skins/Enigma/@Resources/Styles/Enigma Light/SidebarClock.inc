;---------------------------------------------------------------------
; SIDEBAR CLOCK

[StyleClockBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-20)
H=1

[StyleClockFace]
ImageName=#SidebarClockFace#
Y=5
OffsetX=0
OffsetY=0

[StyleClockSeconds]
X=r
Y=r
StartAngle=4.7123889
RotationAngle=6.2831853
LineStart=0
LineWidth=1
LineColor=#ColorLink2#
Solid=0
ValueReminder=60
AntiAlias=1

[StyleClockHours]
X=r
Y=r
StartAngle=4.7123889
RotationAngle=6.2831853
LineStart=0
LineWidth=2
LineColor=#Color1#
Solid=0
ValueReminder=43200
AntiAlias=1

[StyleClockMinutes]
X=r
Y=r
StartAngle=4.7123889
RotationAngle=6.2831853
LineStart=0
LineWidth=2
LineColor=#Color1#
Solid=0
ValueReminder=3600
AntiAlias=1

[StyleClockWeek]
W=150
StringStyle=BOLD
FontColor=#Color1#
FontSize=#Size2#
FontFace=#Font#
AntiAlias=1

[StyleClockDate]
W=150
StringStyle=NORMAL
FontColor=#Color2#
FontSize=#Size2#
FontFace=#Font#
AntiAlias=1

[StyleClockLocation]
W=150
StringStyle=NORMAL
FontColor=#Color2#
FontSize=#Size2#
FontFace=#Font#
AntiAlias=1

;-----------------------
; BIG RIGHT

[StyleClockBRBackground]
W=(#SidebarWidth#+52.5)
H=105

[StyleClockBRFace]
X=5
W=95
H=95

[StyleClockBRSeconds]
W=95
H=95
LineLength=34

[StyleClockBRHours]
W=95
H=95
LineLength=22

[StyleClockBRMinutes]
W=95
H=95
LineLength=32

[StyleClockBRWeek]
X=100r
Y=20r
StringAlign=LEFT

[StyleClockBRDate]
X=5r
Y=20r
StringAlign=LEFT

[StyleClockBRLocation]
X=-5r
Y=20r
StringAlign=LEFT

;-----------------------
; BIG LEFT

[StyleClockBLBackground]
W=(#SidebarWidth#+52.5)
H=105

[StyleClockBLFace]
X=(#SidebarWidth#-47.5)
W=95
H=95

[StyleClockBLSeconds]
W=95
H=95
LineLength=34

[StyleClockBLHours]
W=95
H=95
LineLength=22

[StyleClockBLMinutes]
W=95
H=95
LineLength=32

[StyleClockBLWeek]
X=-5r
Y=20r
StringAlign=RIGHT

[StyleClockBLDate]
X=-5r
Y=20r
StringAlign=RIGHT

[StyleClockBLLocation]
X=5r
Y=20r
StringAlign=RIGHT

;-----------------------
; LITTLE RIGHT

[StyleClockLRBackground]
H=70

[StyleClockLRFace]
X=5
W=60
H=60

[StyleClockLRSeconds]
W=60
H=60
LineLength=21

[StyleClockLRHours]
W=60
H=60
LineLength=14

[StyleClockLRMinutes]
W=60
H=60
LineLength=20

[StyleClockLRWeek]
X=68r
Y=5r
StringAlign=LEFT

[StyleClockLRDate]
X=5r
Y=20r
StringAlign=LEFT

[StyleClockLRLocation]
X=-5r
Y=20r
StringAlign=LEFT

;-----------------------
; LITTLE LEFT

[StyleClockLLBackground]
H=70

[StyleClockLLFace]
X=(#SidebarWidth#-70)
W=60
H=60

[StyleClockLLSeconds]
W=60
H=60
LineLength=21

[StyleClockLLHours]
W=60
H=60
LineLength=14

[StyleClockLLMinutes]
W=60
H=60
LineLength=20

[StyleClockLLWeek]
X=-8r
Y=5r
StringAlign=RIGHT

[StyleClockLLDate]
X=-5r
Y=20r
StringAlign=RIGHT

[StyleClockLLLocation]
X=5r
Y=20r
StringAlign=RIGHT