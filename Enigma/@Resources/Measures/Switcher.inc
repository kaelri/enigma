[Variables]
Reset=1
Pause=(1-#SkinMouseOver#)
SwitcherInterval=30
SwitcherAction=
SwitcherDisabled=0

[Switcher]
Measure=CALC
Formula=((Switcher+1-#Pause#) % (#SwitcherInterval#+2)) * #Reset#
IfBelowValue=1
IfBelowAction=!SetVariable Reset 1
IfAboveValue=#SwitcherInterval#
IfAboveAction=#SwitcherAction#
DynamicVariables=1
Disabled=#SwitcherDisabled#