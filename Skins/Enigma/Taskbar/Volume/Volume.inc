;---------------------------------------------------------------------
; MEASURES

[MeasureVolume]
Measure=Plugin
Plugin=Win7AudioPlugin

[MeasurePercent]
Measure=CALC
Formula=MeasureVolume
Substitute="-1":"Muted"

[MeasureMuted]
Measure=CALC
Formula=MeasureVolume<0

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleVolumeIcon
MeasureName=MeasureMuted
LeftMouseUpAction=[!CommandMeasure "MeasureVolume" "ChangeVolume +#VolumeIncrement#"][!Refresh]
RightMouseUpAction=[!CommandMeasure "MeasureVolume" "ChangeVolume -#VolumeIncrement#"][!Refresh]
MiddleMouseUpAction=[!CommandMeasure "MeasureVolume" "ToggleMute"][!Refresh]
ToolTipTitle=Volume: [MeasurePercent]%
ToolTipText=· Left-click to increase volume.#CRLF#· Right-click to decrease volume.#CRLF#· Middle-click to mute or unmute.
DynamicVariables=1

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasurePercent
LeftMouseUpAction=[!CommandMeasure "MeasureVolume" "ChangeVolume +#VolumeIncrement#"][!Refresh]
RightMouseUpAction=[!CommandMeasure "MeasureVolume" "ChangeVolume -#VolumeIncrement#"][!Refresh]
MiddleMouseUpAction=[!CommandMeasure "MeasureVolume" "ToggleMute"][!Refresh]
ToolTipText=· Left-click to increase volume.#CRLF#· Right-click to decrease volume.#CRLF#· Middle-click to mute or unmute.

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureVolume
;Text=VOL

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureVolume