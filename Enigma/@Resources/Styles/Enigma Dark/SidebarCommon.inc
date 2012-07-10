[Rainmeter]
Group=EnigmaSidebar
MiddleMouseUpAction=!Refresh
MouseOverAction=[!SetVariable SkinMouseOver 1][!UpdateMeasureGroup Mouseover]
MouseLeaveAction=[!SetVariable SkinMouseOver 0][!UpdateMeasureGroup Mouseover]

[Variables]
SkinMouseOver=0