;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=Style#Variant#Background

[IconBackground]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleMusicIconBack

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleMusicIcon
MeasureName=MeasureCover
LeftMouseUpAction=!CommandMeasure "MeasureMediaPlayer" "PlayPause"

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureTrack
LeftMouseUpAction=!CommandMeasure "MeasureMediaPlayer" "PlayPause"

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureArtist
Text="%1"

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureTimeProgress