;--------------------------------------------------------------------------------------------
; SIDEBAR SYSTEM

;---------------------------------------------------------------------
; NORMAL

[StyleSystemNormalBackground]
H=52

[StyleSystemNormalBorder]
SolidColor=#ColorBorder4#
X=10
W=(#SidebarWidth#-20)
H=1

;-----------------------
; FRAME

[StyleSystemNormalBorder1]
Y=5
Hidden=#HideBordersTop#

[StyleSystemNormalVerticalBorderA]
SolidColor=#ColorBorder4#
X=37
Y=6
W=1
H=41
Hidden=#HideBordersBottom#

[StyleSystemNormalVerticalBorderB]
SolidColor=#ColorBorder4#
X=(#SidebarWidth#-37)
Y=6
W=1
H=41
Hidden=#HideBordersBottom#

[StyleSystemNormalBorder2]
Y=47
Hidden=#HideBordersBottom#

;-----------------------
; LABELS

[StyleSystemNormalLabel]
H=15
W=25
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size3#
StringStyle=NORMAL
AntiAlias=1

[StyleSystemNormalLabel1]
X=35
Y=15
StringAlign=RIGHT

[StyleSystemNormalLabel2]
X=35
Y=15r
StringAlign=RIGHT

[StyleSystemNormalLabel3]
X=(#SidebarWidth#-35)
Y=15
StringAlign=LEFT

[StyleSystemNormalLabel4]
X=(#SidebarWidth#-35)
Y=15r

;-----------------------
; TEXT

[StyleSystemNormalText]
Y=r
H=15
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringStyle=NORMAL
AntiAlias=1

[StyleSystemNormalText1]
X=9r
W=(#SidebarWidth#-[Text3:W]-88)
ClipString=1
StringAlign=LEFT
DynamicVariables=1

[StyleSystemNormalText2]
X=9r
W=(#SidebarWidth#-[Text4:W]-88)
ClipString=1
StringAlign=LEFT
DynamicVariables=1

[StyleSystemNormalText3]
X=-9r
StringAlign=RIGHT

[StyleSystemNormalText4]
X=-9r
StringAlign=RIGHT

[StyleSystemNormalTextDark]
FontColor=#Color2#

;----------------------------------------------
; GRAPH FRAME

[StyleSystemNormalBorder3]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleSystemNormalVerticalBorderC]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleSystemNormalBorder4]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleSystemNormalBorder5]
X=0
Y=0
W=0
H=0
Hidden=1

;-----------------------
; GRAPH METERS

[StyleSystemNormalGraph]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleSystemNormalGraph1]

[StyleSystemNormalGraph2]

;-----------------------
; GRAPH TEXT AND LABELS

[StyleSystemNormalGraphLabel]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleSystemNormalGraphLabel1]

[StyleSystemNormalGraphLabel2]

[StyleSystemNormalGraphText]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleSystemNormalGraphText1]

[StyleSystemNormalGraphText2]

;---------------------------------------------------------------------
; GRAPH

[StyleSystemGraphBackground]
H=152

[StyleSystemGraphBorder]
SolidColor=#ColorBorder4#
X=10
W=(#SidebarWidth#-20)
H=1

;-----------------------
; FRAME

[StyleSystemGraphBorder1]
Y=5
Hidden=#HideBordersTop#

[StyleSystemGraphVerticalBorderA]
SolidColor=#ColorBorder4#
X=37
Y=6
W=1
H=41
Hidden=#HideBordersBottom#

[StyleSystemGraphVerticalBorderB]
SolidColor=#ColorBorder4#
X=(#SidebarWidth#-37)
Y=6
W=1
H=41
Hidden=#HideBordersBottom#

[StyleSystemGraphBorder2]
Y=47
Hidden=#HideBordersBottom#

;-----------------------
; LABELS

[StyleSystemGraphLabel]
H=15
W=25
FontColor=#Color2#
FontFace=#Font#
FontSize=#Size3#
StringStyle=NORMAL
AntiAlias=1

[StyleSystemGraphLabel1]
X=35
Y=15
StringAlign=RIGHT

[StyleSystemGraphLabel2]
X=35
Y=15r
StringAlign=RIGHT

[StyleSystemGraphLabel3]
X=(#SidebarWidth#-35)
Y=15
StringAlign=LEFT

[StyleSystemGraphLabel4]
X=(#SidebarWidth#-35)
Y=15r

;-----------------------
; TEXT

[StyleSystemGraphText]
Y=r
H=15
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringStyle=NORMAL
AntiAlias=1

[StyleSystemGraphText1]
X=9r
W=(#SidebarWidth#-[Text3:W]-88)
ClipString=1
StringAlign=LEFT
DynamicVariables=1

[StyleSystemGraphText2]
X=9r
W=(#SidebarWidth#-[Text4:W]-88)
ClipString=1
StringAlign=LEFT
DynamicVariables=1

[StyleSystemGraphText3]
X=-9r
StringAlign=RIGHT

[StyleSystemGraphText4]
X=-9r
StringAlign=RIGHT

[StyleSystemGraphTextDark]
FontColor=#Color2#

;----------------------------------------------
; GRAPH FRAME

[StyleSystemGraphBorder3]
X=(10+(4*#HideBordersBottom#))
Y=89
W=(#SidebarWidth#-20-(4*#HideBordersBottom#))

[StyleSystemGraphVerticalBorderC]
SolidColor=#ColorBorder4#
X=(#SidebarWidth#/2)
Y=90
W=1
H=19

[StyleSystemGraphBorder4]
SolidColor=#ColorBorder4#
X=(10+(4*#HideBordersBottom#))
Y=109
W=(#SidebarWidth#-20-(4*#HideBordersBottom#))
H=1

[StyleSystemGraphBorder5]
Y=147
Hidden=#HideBordersBottom#

;-----------------------
; GRAPH METERS

[StyleSystemGraphGraph]
X=(10+(4*#HideBordersBottom#))
H=37
W=(#SidebarWidth#-20-(4*#HideBordersBottom#))
AntiAlias=1
AutoScale=1

[StyleSystemGraphGraph1]
Y=52
PrimaryColor=#ColorLink3#

[StyleSystemGraphGraph2]
Y=110
PrimaryColor=#Color2#
Flip=1

;-----------------------
; GRAPH TEXT AND LABELS

[StyleSystemGraphGraphLabel]
Y=94
H=10
FontFace=#Font#
FontSize=#Size4#
StringStyle=NORMAL
AntiAlias=1

[StyleSystemGraphGraphLabel1]
X=((#SidebarWidth#/2)-4)
FontColor=#ColorLink3#
StringAlign=RIGHT

[StyleSystemGraphGraphLabel2]
X=((#SidebarWidth#/2)+4)
FontColor=#Color2#
StringAlign=LEFT

[StyleSystemGraphGraphText]
Y=93
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringStyle=NORMAL
AntiAlias=1

[StyleSystemGraphGraphText1]
X=((#SidebarWidth#/2)-26)
StringAlign=RIGHT

[StyleSystemGraphGraphText2]
X=((#SidebarWidth#/2)+40)
StringAlign=LEFT