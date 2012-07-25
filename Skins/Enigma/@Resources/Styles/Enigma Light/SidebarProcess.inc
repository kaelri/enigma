;--------------------------------------------------------------------------------------------
; SIDEBAR PROCESS

[Variables]
Col1WidthMod=0.45
Col2Width=30

;-----------------------
; HEADER

[StyleProcessBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersTop#

[StyleProcessBackground]
H=175

[StyleProcessIcon]
ImageName=#@#Images\System.#ColorImage#.png
X=10
Y=15
W=25
H=25
DynamicVariables=1

[StyleProcessTitle]
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

;-----------------------

[StyleProcessTextFirst]
Y=42

[StyleProcessText]
X=12
Y=13r
H=10
W=((#SidebarWidth#-24-#Col2Width#)*#Col1WidthMod#)
ClipString=1
StringStyle=NORMAL
FontColor=#Color1#
FontSize=#Size4#
FontFace=#Font#
AntiAlias=1
ToolTipWidth=#SidebarWidth#
DynamicVariables=1

[StyleProcessNumber]
X=#Col2Width#R
Y=r
W=#Col2Width#
H=12
StringStyle=BOLD
StringAlign=RIGHT
FontColor=#Color1#
FontSize=#Size3#
FontFace=#Font#
AntiAlias=1
DynamicVariables=1

[StyleProcessBar]
X=5r
Y=2r
W=(#SidebarWidth#-24-#Col2Width#-((#SidebarWidth#-24-#Col2Width#)*#Col1WidthMod#)-5)
H=4
BarColor=#Color1#
SolidColor=#Color3#
SolidColor2=#Color4#
BarOrientation=HORIZONTAL

;-----------------------
; BORDER

[StyleProcessBorderBottom]
SolidColor=#ColorBorder4#
X=10
Y=25r
W=(#SidebarWidth#-26)
H=1
Hidden=#HideBordersBottom#