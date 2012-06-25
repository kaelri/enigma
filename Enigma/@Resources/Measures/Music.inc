[MeasureMediaPlayer]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=#CurrentPlayer#
PlayerType=FILE

[MeasureTrack]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=TITLE

[MeasureAlbum]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=ALBUM

[MeasureArtist]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=ARTIST

[MeasureCover]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=COVER

[MeasureTimeDuration]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=DURATION

[MeasureTimePosition]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=POSITION

[MeasureTimeProgress]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=PROGRESS

[MeasureState]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=STATE