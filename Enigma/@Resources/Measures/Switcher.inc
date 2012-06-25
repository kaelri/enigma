[Variables]
Reset=1
Pause=1
SwitcherInterval=30
SwitcherAction=
SwitcherDisabled=0

[Rainmeter]
MouseOverAction=!SetVariable Pause 0
MouseLeaveAction=!SetVariable Pause 1

[Switcher]
Measure=CALC
Formula=((Switcher+#Pause#) % (#SwitcherInterval#+2)) * #Reset#
IfBelowValue=1
IfBelowAction=!SetVariable Reset 1
IfAboveValue=#SwitcherInterval#
IfAboveAction=#SwitcherAction#
DynamicVariables=1
Disabled=#SwitcherDisabled#