[Variables]
PanelHeight=425
ArrowY=88
LabelsQueue=

;---------------------------------------------------------------------
; METERS

;-----------------------
; INDICATOR ARROW

[Arrow]
Meter=IMAGE
MeterStyle=StyleMenuArrow
Y=#ArrowY#

[Grabber]
Meter=IMAGE
ImageName=#@#Images\Grabber.W.png
X=213
Y=(59+(#MusicPlayerType#*20))

;-----------------------
; MUSIC

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=M  U  S  I  C

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set the media player app that you would like to use with Enigma Music.
H=24

;-----------------------

[MusicPlayerName]
Meter=STRING
MeterStyle=StyleName
Text="Music Player"

[MusicPlayerText1]
Meter=STRING
MeterStyle=StyleText
Text="AIMP"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '1', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'AIMP')"]
TooltipTitle="AIMP"
TooltipText=Fully supported.

[MusicPlayerText2]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="foobar2000"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '2', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'foobar2000')"]
TooltipTitle="foobar2000"
TooltipText=Requires the foo_rainmeter.dll plugin.

[MusicPlayerText3]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="iTunes"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '3', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'iTunes')"]
TooltipTitle="iTunes"
TooltipText=Fully supported.

[MusicPlayerText4]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="JRiver Media"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '4', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'CAD')"]
TooltipTitle="JRiver Media Center & JRiver Media Jukebox"
TooltipText=Fully supported, using the CD Art Display interface.

[MusicPlayerText5]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Last.fm Client"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '5', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'WLM')"]
TooltipTitle="Last.fm Client"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

[MusicPlayerText6]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="MediaMonkey"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '6', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'MediaMonkey')"]
TooltipTitle="MediaMonkey"
TooltipText=Fully supported.

[MusicPlayerText7]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Media Player Classic"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '7', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'WLM')"]
TooltipTitle="Media Player Classic"
TooltipText=Partially supported, using the Windows Live Messenger interface.#CRLF##CRLF#Note that the 'Send Now Playing information to MSN Messenger' option must be enabled in the player's settings (View -> Options -> Tweaks).

[MusicPlayerText8]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="MusicBee"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '8', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'CAD')"]
TooltipTitle="MusicBee"
TooltipText=Fully supported, using the CD Art Display interface.

[MusicPlayerText9]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Open Pandora"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '9', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'WLM')"]
TooltipTitle="Open Pandora"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

[MusicPlayerText10]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Spotify"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '10', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'Spotify')"]
TooltipTitle="Spotify"
TooltipText=Partially supported. Only the Artist and Track information will display. Player controls are working.

[MusicPlayerText11]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="TTPlayer"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '11', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'WLM')"]
TooltipTitle="TTPlayer"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

[MusicPlayerText12]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Winamp"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '12', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'Winamp')"]
TooltipTitle="Winamp"
TooltipText=Fully supported.

[MusicPlayerText13]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="VLC Media Player"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '13', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'CAD')"]
TooltipTitle="VLC Media Player"
TooltipText=Fully supported, using the CD Art Display interface. Requires the 'libcad' plugin for VLC.

[MusicPlayerText14]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Windows Media Player"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '14', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'WMP')"]
TooltipTitle="Windows Media Player"
TooltipText=Fully supported.

[MusicPlayerText15]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Zune"
LeftMouseUpAction=[!CommandMeasure MeasureInputScript "Write('MusicPlayerType', '15', 'wait')"][!CommandMeasure MeasureInputScript "Write('MusicPlayer', 'WLM')"]
TooltipTitle="Windows Media Player"
TooltipText=Partially supported, using the Windows Live Messenger interface.