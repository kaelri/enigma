;--------------------------------------------------------------------------------------------
; TASKBAR

[Rainmeter]
Group=EnigmaTaskbar
Blur=1
MiddleMouseUpAction=!Refresh
LeftMouseDoubleClickAction=!ActivateConfig #CURRENTCONFIG#

;---------------------------------------------------------------------
; TASKBAR (1)

;----------------------------------------------
; NORMAL

[StyleTaskbarNormalBase]
ImageName=#TaskbarImage#
W=(#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#)
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
W=(#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

[StyleTaskbarTriptychFilter]
SolidColor=#ColorFilter2#
X=r
Y=r
W=(#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#)
H=#TaskbarHeight#

[StyleTaskbarTriptychPanel]
ImageName=#TaskbarImage#
X=((#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#) / 3)
W=((#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#) / 3)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

;---------------------------------------------------------------------
; TASKBAR (2)

;----------------------------------------------
; NORMAL

[StyleTaskbar2NormalBase]
ImageName=#SecondTaskbarImage#

[StyleTaskbar2NormalFilter]

[StyleTaskbar2NormalPanel]

;----------------------------------------------
; TRIPTYCH

[StyleTaskbar2TriptychBase]
ImageName=#SecondTaskbarImage#

[StyleTaskbar2TriptychFilter]

[StyleTaskbar2TriptychPanel]
ImageName=#SecondTaskbarImage#