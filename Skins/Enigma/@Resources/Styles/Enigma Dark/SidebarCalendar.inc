;--------------------------------------------------------------------------------------------
; SIDEBAR CALENDAR

[Variables]
FirstX=38
FirstY=38
SpacingX=(([#SidebarWidth]-[#FirstX]-19)/6)
SpacingY=20

;-----------------------

[StyleCalendarBorder]
SolidColor=[#ColorBorder4]
X=10
Y=5
W=([#SidebarWidth]-20)
H=1
Hidden=[#HideBordersTop]

[StyleCalendarLabel]
X=[#SpacingX]r
Y=26
W=16
H=16
FontColor=[#Color1]
FontFace=[#Font]
FontSize=[#Size3]
StringAlign=CenterCenter
StringStyle=NORMAL
AntiAlias=1
SolidColor=255, 255, 255, 25

[StyleCalendarLabelCurrent]
SolidColor=255, 255, 255, 50

[StyleCalendarLabelFirst]
X=([#FirstX]-8)

[StyleCalendarText]
X=[#SpacingX]r
Y=r
W=18
H=13
FontColor=[#Color1]
FontFace=[#Font]
FontSize=[#Size3]
StringAlign=RIGHT
StringStyle=NORMAL
AntiAlias=1
DynamicVariables=1

[StyleCalendarTextFirst]
X=[#FirstX]
Y=[#FirstY]

[StyleCalendarTextExtra]
FontColor=[#Color3]

[StyleCalendarTextInvisible]
FontColor=[#ColorTransparent]

[StyleCalendarIndicatorText]
StringStyle=BOLD

[StyleCalendarEvent]
Prefix=�

[StyleCalendarIndicatorBox]
SolidColor=[#ColorLink3]
H=12
W=2
DynamicVariables=1

;---------------------------------------------------------------------
; MONTH

[StyleCalendarMonthBackground]
H=170

[StyleCalendarNewWeek]
X=[#FirstX]
Y=[#SpacingY]r

[StyleCalendarMonthBorderBottom]
SolidColor=[#ColorBorder4]
X=10
Y=165
W=([#SidebarWidth]-20)
H=1
Hidden=[#HideBordersBottom]

;---------------------------------------------------------------------
; WEEK

[StyleCalendarWeekBackground]
H=63

[StyleCalendarWeekBorderBottom]
SolidColor=[#ColorBorder4]
X=10
Y=58
W=([#SidebarWidth]-20)
H=1
Hidden=[#HideBordersBottom]