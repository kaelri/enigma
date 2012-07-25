[Rainmeter]
Group=EnigmaSidebar
MiddleMouseUpAction=!Refresh
LeftMouseDoubleClickAction=!ActivateConfig #CURRENTCONFIG#
MouseOverAction=[!SetVariable SkinMouseOver 1][!HideMeterGroup EnigmaMouseout][!ShowMeterGroup EnigmaMouseover][!Redraw]
MouseLeaveAction=[!SetVariable SkinMouseOver 0][!HideMeterGroup EnigmaMouseover][!ShowMeterGroup EnigmaMouseout][!Redraw]
DynamicWindowSize=1

[Variables]
SkinMouseOver=0

[StyleSidebarBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ScaleMargins=12,12,12,12
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #SkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=#SidebarWidth#