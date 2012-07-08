[Variables]
SelectedDefault=

;---------------------------------------------------------------------
; METERS

[DefaultCurtain]
Meter=Image
SolidColor=0,0,0,230
X=36
Y=34
W=(#PanelWidth#-37)
H=(#PanelHeight#-67)
Group=Default
Hidden=1

[DefaultText]
Meter=String
Text=Restore the default setting for#CRLF##SelectedDefault#?
X=(36+(#PanelWidth#-36)/2)
Y=120
FontColor=255,255,255
FontSize=10
FontFace=Trebuchet MS
StringAlign=CENTER
StringStyle=BOLD
AntiAlias=1
DynamicVariables=1
Hidden=1
Group=Default

[DefaultYes]
Meter=String
Text=Yes
X=-25r
Y=50r
FontColor=128,192,255,217
FontSize=12
FontFace=Trebuchet MS
StringAlign=RIGHT
StringStyle=BOLD
AntiAlias=1
SolidColor=0,0,0,2
DynamicVariables=1
Hidden=1
Group=Default
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Default('#SelectedDefault#', 1)"

[DefaultNo]
Meter=String
MeterStyle=DefaultYes
Text=No
X=50r
Y=r
StringAlign=LEFT
Hidden=1
Group=Default
LeftMouseUpAction=[!HideMeterGroup Default][!Update]

[DefaultDescription]
Meter=String
Text=Clicking "yes" will replace your current setting with the Enigma default. This cannot be undone.
X=(36+(#PanelWidth#-36)/2)
Y=50r
W=320
H=100
ClipString=1
FontColor=160,160,160
FontSize=10
FontFace=Trebuchet MS
StringAlign=CENTER
AntiAlias=1
Hidden=1
Group=Default