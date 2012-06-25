;--------------------------------------------------------------------------------------------
; TASKBAR

[Rainmeter]
Group=EnigmaTaskbar
Blur=1
MiddleMouseUpAction=!Refresh

;---------------------------------------------------------------------
; TASKBAR (1)

;----------------------------------------------
; NORMAL

[StyleTaskbarNormalBase]
ImageName=#TaskbarImage#
W=(#WORKAREAWIDTH#-#TaskbarSpacing#)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

[StyleTaskbarNormalFilter]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleTaskbarNormalPanel]
X=0
Y=0
W=0
H=0
Hidden=1

;----------------------------------------------
; TRIPTYCH

[StyleTaskbarTriptychBase]
ImageName=#TaskbarImage#
W=(#WORKAREAWIDTH#-#TaskbarSpacing#)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

[StyleTaskbarTriptychFilter]
SolidColor=#ColorFilter2#
X=r
Y=r
W=(#WORKAREAWIDTH#-#TaskbarSpacing#)
H=#TaskbarHeight#

[StyleTaskbarTriptychPanel]
ImageName=#TaskbarImage#
X=((#WORKAREAWIDTH#-#TaskbarSpacing#) / 3)
W=((#WORKAREAWIDTH#-#TaskbarSpacing#) / 3)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

;---------------------------------------------------------------------
; TASKBAR (2)

;----------------------------------------------
; NORMAL

[StyleTaskbar2NormalBase]
ImageName=#SecondTaskbarImage#
W=(#WORKAREAWIDTH#-#TaskbarSpacing#)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

[StyleTaskbar2NormalFilter]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleTaskbar2NormalPanel]
X=0
Y=0
W=0
H=0
Hidden=1

;----------------------------------------------
; TRIPTYCH

[StyleTaskbar2TriptychBase]
ImageName=#SecondTaskbarImage#
W=(#WORKAREAWIDTH#-#TaskbarSpacing#)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

[StyleTaskbar2TriptychFilter]
SolidColor=#ColorFilter2#
X=r
Y=r
W=(#WORKAREAWIDTH#-#TaskbarSpacing#)
H=#TaskbarHeight#

[StyleTaskbar2TriptychPanel]
ImageName=#SecondTaskbarImage#
X=((#WORKAREAWIDTH#-#TaskbarSpacing#) / 3)
W=((#WORKAREAWIDTH#-#TaskbarSpacing#) / 3)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#