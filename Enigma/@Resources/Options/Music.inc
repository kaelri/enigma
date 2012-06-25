[Variables]
PanelHeight=410
ArrowY=88

;---------------------------------------------------------------------
; MEASURES

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
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer AIMP "#Settings#"][!WriteKeyValue Variables MusicPlayerType 1 "#Settings#"][!Refresh *]
TooltipTitle="AIMP"
TooltipText=Fully supported.

[MusicPlayerText2]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="foobar2000"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer foobar2000 "#Settings#"][!WriteKeyValue Variables MusicPlayerType 2 "#Settings#"][!Refresh *]
TooltipTitle="foobar2000"
TooltipText=Requires the foo_rainmeter.dll plugin.

[MusicPlayerText3]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="iTunes"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer iTunes "#Settings#"][!WriteKeyValue Variables MusicPlayerType 3 "#Settings#"][!Refresh *]
TooltipTitle="iTunes"
TooltipText=Fully supported.

[MusicPlayerText4]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Last.fm Client"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer WLM "#Settings#"][!WriteKeyValue Variables MusicPlayerType 4 "#Settings#"][!Refresh *]
TooltipTitle="Last.fm Client"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

[MusicPlayerText5]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="MediaMonkey"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer MediaMonkey "#Settings#"][!WriteKeyValue Variables MusicPlayerType 5 "#Settings#"][!Refresh *]
TooltipTitle="MediaMonkey"
TooltipText=Fully supported.

[MusicPlayerText6]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Media Player Classic"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer WLM "#Settings#"][!WriteKeyValue Variables MusicPlayerType 6 "#Settings#"][!Refresh *]
TooltipTitle="Media Player Classic"
TooltipText=Partially supported, using the Windows Live Messenger interface.#CRLF##CRLF#Note that the 'Send Now Playing information to MSN Messenger' option must be enabled in the player's settings (View -> Options -> Tweaks).

[MusicPlayerText7]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="MusicBee"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer CAD "#Settings#"][!WriteKeyValue Variables MusicPlayerType 7 "#Settings#"][!Refresh *]
TooltipTitle="MusicBee"
TooltipText=Fully supported, using the CD Art Display interface.

[MusicPlayerText8]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Open Pandora"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer WLM "#Settings#"][!WriteKeyValue Variables MusicPlayerType 8 "#Settings#"][!Refresh *]
TooltipTitle="Open Pandora"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

[MusicPlayerText9]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Spotify"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer Spotify "#Settings#"][!WriteKeyValue Variables MusicPlayerType 9 "#Settings#"][!Refresh *]
TooltipTitle="Spotify"
TooltipText=Partially supported. Only the Artist and Track information will display. Player controls are working.

[MusicPlayerText10]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="TTPlayer"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer WLM "#Settings#"][!WriteKeyValue Variables MusicPlayerType 10 "#Settings#"][!Refresh *]
TooltipTitle="TTPlayer"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

[MusicPlayerText11]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Winamp"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer Winamp "#Settings#"][!WriteKeyValue Variables MusicPlayerType 11 "#Settings#"][!Refresh *]
TooltipTitle="Winamp"
TooltipText=Fully supported.

[MusicPlayerText12]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="VLC Media Player"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer CAD "#Settings#"][!WriteKeyValue Variables MusicPlayerType 12 "#Settings#"][!Refresh *]
TooltipTitle="VLC Media Player"
TooltipText=Fully supported, using the CD Art Display interface. Requires the 'libcad' plugin for VLC.

[MusicPlayerText13]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Windows Media Player"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer WMP "#Settings#"][!WriteKeyValue Variables MusicPlayerType 13 "#Settings#"][!Refresh *]
TooltipTitle="Windows Media Player"
TooltipText=Fully supported.

[MusicPlayerText14]
Meter=STRING
MeterStyle=StyleText | StyleTextSub
Text="Zune"
LeftMouseUpAction=[!WriteKeyValue Variables MusicPlayer WLM "#Settings#"][!WriteKeyValue Variables MusicPlayerType 14 "#Settings#"][!Refresh *]
TooltipTitle="Windows Media Player"
TooltipText=Partially supported, using the Windows Live Messenger interface. 

;-----------------------

[RestoreDefaultMusic]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables MusicPlayerType "#DefaultMusicPlayerType#" "#Settings#"][!WriteKeyValue Variables MusicPlayer "#DefaultMusicPlayer#" "#Settings#"][!Refresh *]
TooltipText=Click here to reset all Music settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.