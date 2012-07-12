[Rainmeter]
Group=EnigmaSidebar
MiddleMouseUpAction=!Refresh
MouseOverAction=[!SetVariable SkinMouseOver 1][!UpdateMeasureGroup Mouseover]
MouseLeaveAction=[!SetVariable SkinMouseOver 0][!UpdateMeasureGroup Mouseover]

[Variables]
SkinMouseOver=0

[StyleSidebarBackground]
ImageName=#@#Images\SkinBackground.#ColorImage#.png
ScaleMargins=12,12,12,12
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!Update]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!Update]
W=#SidebarWidth#