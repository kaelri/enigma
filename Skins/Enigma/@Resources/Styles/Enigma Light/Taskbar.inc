;--------------------------------------------------------------------------------------------
; TASKBAR

[Rainmeter]
Group=EnigmaTaskbar
Blur=1
MiddleMouseUpAction=!Refresh

;---------------------------------------------------------------------
; TASKBAR (1)

[StyleTaskbarBase]
ImageName=#TaskbarImage#
W=(#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#

[StyleTaskbarFilter]
SolidColor=#ColorFilter2#
X=r
Y=r
W=(#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#)
H=#TaskbarHeight#
Hidden=#TaskbarHideTriptych#

[StyleTaskbarPanel]
ImageName=#TaskbarImage#
X=((#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#) / 3)
W=((#WORKAREAWIDTH# - #TaskbarSpacingFixed# * #SidebarWidth#) / 3)
H=#TaskbarHeight#
ImageAlpha=#TaskbarAlpha#
Hidden=#TaskbarHideTriptych#

;---------------------------------------------------------------------
; TASKBAR (2)

[StyleTaskbar2Base]
ImageName=#SecondTaskbarImage#

[StyleTaskbar2Filter]

[StyleTaskbar2Panel]
ImageName=#SecondTaskbarImage#