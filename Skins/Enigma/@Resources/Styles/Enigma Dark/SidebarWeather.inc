;--------------------------------------------------------------------------------------------
; SIDEBAR WEATHER

;----------------------------------------------
; NORMAL

[StyleWeatherNormalBackground]
H=136

[StyleWeatherNormalBorder]
SolidColor=#ColorBorder4#
H=1

[StyleWeatherNormalBorder1]
X=10
Y=5
W=(#SidebarWidth#-20)
Hidden=#HideBordersTop#

[StyleWeatherNormalBorder2]
X=(10+(4*#HideBordersBottom#))
Y=47
W=(#SidebarWidth#-24-(4*#HideBordersBottom#))

[StyleWeatherNormalBorder3]
X=(10+(4*#HideBordersBottom#))
Y=19R
W=(#SidebarWidth#-24-(4*#HideBordersBottom#))

[StyleWeatherNormalBorder4]
X=10
Y=19R
W=(#SidebarWidth#-20)
Hidden=#HideBordersBottom#

[StyleWeatherNormalMoxa]
X=12
Y=5R
W=33
H=33
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherNormalText]
X=60
Y=5r
H=12
W=(#SidebarWidth#-60)
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleWeatherNormalTextSub]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleWeatherNormalLabel]
;X=110
X=(#SidebarWidth#-12)
Y=r
H=12
W=(#SidebarWidth#-60)
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleWeatherNormalLabelSub]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleWeatherNormalSeparator]
X=0
Y=0
W=0
H=0
Hidden=1

;----------------------------------------------
; EXTENDED

[StyleWeatherExtendedBackground]
H=242

[StyleWeatherExtendedBorder]
SolidColor=#ColorBorder4#
H=1

[StyleWeatherExtendedBorder1]
X=10
Y=5
W=(#SidebarWidth#-20)
Hidden=#HideBordersTop#

[StyleWeatherExtendedBorder2]
X=(10+(4*#HideBordersBottom#))
Y=10R
W=(#SidebarWidth#-24-(4*#HideBordersBottom#))

[StyleWeatherExtendedBorder3]
X=(10+(4*#HideBordersBottom#))
Y=19R
W=(#SidebarWidth#-24-(4*#HideBordersBottom#))

[StyleWeatherExtendedBorder4]
X=10
Y=19R
W=(#SidebarWidth#-20)
Hidden=#HideBordersBottom#

[StyleWeatherExtendedMoxa]
X=12
Y=5R
W=33
H=33
ImageName=#@#Images\MoxaWeather\%1.#ColorImage#.png

[StyleWeatherExtendedText]
X=60
Y=5r
H=12
W=(#SidebarWidth#-60)
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleWeatherExtendedTextSub]
Y=5R

[StyleWeatherExtendedLabel]
;X=110
X=(#SidebarWidth#-12)
Y=r
H=12
W=(#SidebarWidth#-60)
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size4#
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
ClipString=1

[StyleWeatherExtendedLabelSub]

[StyleWeatherExtendedSeparator]
SolidColor=#ColorBorder4#
X=60
Y=5R
W=(#SidebarWidth#-72)
H=1