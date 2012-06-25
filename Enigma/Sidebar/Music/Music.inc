;---------------------------------------------------------------------
; MEASURES

[Variables]
@include4=#@#Measures\Music.inc
CurrentPlayer=#MusicPlayer#

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=StyleMusic#Variant#Background

[Border]
Meter=IMAGE
MeterStyle=StyleMusic#Variant#Border

[Header]
Meter=STRING
MeterStyle=StyleMusic#Variant#Header

;-----------------------
; ART

[IconBack]
Meter=IMAGE
MeterStyle=StyleMusic#Variant#IconBack

[Icon]
Meter=IMAGE
MeterStyle=StyleMusic#Variant#Icon
MeasureName=MeasureCover
LeftMouseUpAction=["[MeasureCover]"]
ToolTipTitle=View Full Size
ToolTipText=Click to view this track's cover art at full-size.

[Curtain]
Meter=IMAGE
MeterStyle=StyleMusic#Variant#Curtain

;-------------------------
; TEXT

[Track]
Meter=STRING
MeterStyle=StyleMusic#Variant#Text | StyleMusic#Variant#TextFirst
MeasureName=MeasureTrack

[Artist]
Meter=STRING
MeterStyle=StyleMusic#Variant#Text | StyleMusic#Variant#TextSecond
MeasureName=MeasureArtist

[Album]
Meter=STRING
MeterStyle=StyleMusic#Variant#Text | StyleMusic#Variant#TextThird
MeasureName=MeasureAlbum

[Time]
Meter=STRING
MeterStyle=StyleMusic#Variant#Time
MeasureName=MeasureTimePosition

;-------------------------
; BUTTONS

[Prev]
Meter=STRING
MeterStyle=StyleMusic#Variant#Button | StyleMusic#Variant#ButtonFirst
LeftMouseUpAction=!CommandMeasure "MeasureMediaPlayer" "Previous"
ToolTipTitle=Previous
ToolTipText=Go back to the previous track in the current playlist.

[Play]
Meter=STRING
MeterStyle=StyleMusic#Variant#Button | StyleMusic#Variant#ButtonSecond[MeasureState]
LeftMouseUpAction=!CommandMeasure "MeasureMediaPlayer" "PlayPause"
ToolTipTitle=Play/Pause
ToolTipText=Pause the playing track, or resume playing if paused.
DynamicVariables=1

[Next]
Meter=STRING
MeterStyle=StyleMusic#Variant#Button | StyleMusic#Variant#ButtonThird
LeftMouseUpAction=!CommandMeasure "MeasureMediaPlayer" "Next"
ToolTipTitle=Next
ToolTipText=Go to the next track in the current playlist.

[Progress]
Meter=BAR
MeterStyle=StyleMusic#Variant#Progress
MeasureName=MeasureTimeProgress