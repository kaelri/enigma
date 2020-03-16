[Variables]
SwitcherInterval=30
SwitcherAction=
SwitcherDisabled=0

[Switcher]
Measure=LOOP
EndValue=[#SwitcherInterval]
IfEqualValue=[#SwitcherInterval]
IfEqualAction=[#SwitcherAction]
Disabled=[#SwitcherDisabled]
Paused=[#SkinMouseOver]
DynamicVariables=1
