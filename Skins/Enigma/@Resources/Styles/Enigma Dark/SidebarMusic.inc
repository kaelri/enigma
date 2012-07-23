;--------------------------------------------------------------------------------------------
; SIDEBAR MUSIC

;----------------------------------------------
; NORMAL

[StyleMusicNormalBackground]
H=76

[StyleMusicNormalBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-120)
H=1
Hidden=#HideBordersTop#

[StyleMusicNormalHeader]
X=(#SidebarWidth#-10)
Y=1
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=RIGHT
StringStyle=NORMAL
Text="N o w   P l a y i n g"
AntiAlias=1
Hidden=#HideBordersTop#

[StyleMusicNormalIconBack]
Hidden=1
W=0
H=0

[StyleMusicNormalIcon]
Hidden=1
W=0
H=0
ToolTipWidth=#SidebarWidth#

[StyleMusicNormalCurtain]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleMusicNormalText]
X=14
Y=16r
H=15
W=(#SidebarWidth#-28)
ClipString=1
FontFace=#Font#
FontSize=#Size3#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1

[StyleMusicNormalTextFirst]
FontColor=#Color1#
Y=16

[StyleMusicNormalTextSecond]
FontColor=#Color2#

[StyleMusicNormalTextThird]
FontColor=#Color3#
W=(#SidebarWidth#-60)
Group=EnigmaMouseout

[StyleMusicNormalTime]
X=(#SidebarWidth#-14)
Y=r
StringAlign=RIGHT
StringStyle=BOLD
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size4#
AntiAlias=1

[StyleMusicNormalButton]
X=16r
Y=49
W=10
H=10
AntiAlias=1
Hidden=1
Group=EnigmaMouseover

[StyleMusicNormalButtonPrevious]
ImageName=#@#Images\Music\MusicPrevious.#ColorImage#.png
X=14

[StyleMusicNormalButtonPlayPause0]
ImageName=#@#Images\Music\MusicPlay.#ColorImage#.png

[StyleMusicNormalButtonPlayPause1]
ImageName=#@#Images\Music\MusicPause.#ColorImage#.png

[StyleMusicNormalButtonPlayPause2]
ImageName=#@#Images\Music\MusicPlay.#ColorImage#.png

[StyleMusicNormalButtonNext]
ImageName=#@#Images\Music\MusicNext.#ColorImage#.png

[StyleMusicNormalButtonRepeat0]
ImageName=#@#Images\Music\MusicRepeat.#ColorImage#.png
ImageAlpha=128

[StyleMusicNormalButtonRepeat1]
ImageName=#@#Images\Music\MusicRepeat.#ColorImage#.png

[StyleMusicNormalButtonShuffle0]
ImageName=#@#Images\Music\MusicShuffle.#ColorImage#.png
ImageAlpha=128

[StyleMusicNormalButtonShuffle1]
ImageName=#@#Images\Music\MusicShuffle.#ColorImage#.png

[StyleMusicNormalProgress]
X=(10+(4*#HideBordersBottom#))
Y=71
W=(#SidebarWidth#-20-(4*#HideBordersBottom#))
H=1
BarColor=#ColorBorder2#
SolidColor=#ColorBorder4#
BarOrientation=HORIZONTAL

;----------------------------------------------
; ART

[StyleMusicArtBackground]
H=80

[StyleMusicArtBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-120)
H=1
Hidden=#HideBordersTop#

[StyleMusicArtHeader]
X=(#SidebarWidth#-10)
Y=1
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size3#
StringAlign=RIGHT
StringStyle=NORMAL
Text="N o w   P l a y i n g"
AntiAlias=1
Hidden=#HideBordersTop#

[StyleMusicArtIconBack]
ImageName=#@#Images\MusicAlbum.#ColorImage#.png
X=14
Y=16
W=45
H=45
AntiAlias=1

[StyleMusicArtIcon]
X=15
Y=17
H=43
W=43
AntiAlias=1
ToolTipWidth=#SidebarWidth#

[StyleMusicArtCurtain]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleMusicArtText]
X=64
Y=16r
W=(#SidebarWidth#-78)
H=15
ClipString=1
FontFace=#Font#
FontSize=#Size3#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1

[StyleMusicArtTextFirst]
FontColor=#Color1#
Y=16

[StyleMusicArtTextSecond]
FontColor=#Color2#

[StyleMusicArtTextThird]
FontColor=#Color3#
Group=EnigmaMouseout

[StyleMusicArtTime]
X=(#SidebarWidth#-14)
Y=48
StringAlign=RIGHT
StringStyle=BOLD
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size4#
AntiAlias=1
Hidden=1
Group=EnigmaMouseover

[StyleMusicArtButton]
X=16r
Y=49
W=10
H=10
AntiAlias=1
Hidden=1
Group=EnigmaMouseover

[StyleMusicArtButtonPrevious]
ImageName=#@#Images\Music\MusicPrevious.#ColorImage#.png
X=64

[StyleMusicArtButtonPlayPause0]
ImageName=#@#Images\Music\MusicPlay.#ColorImage#.png

[StyleMusicArtButtonPlayPause1]
ImageName=#@#Images\Music\MusicPause.#ColorImage#.png

[StyleMusicArtButtonPlayPause2]
ImageName=#@#Images\Music\MusicPlay.#ColorImage#.png

[StyleMusicArtButtonNext]
ImageName=#@#Images\Music\MusicNext.#ColorImage#.png

[StyleMusicArtButtonRepeat0]
ImageName=#@#Images\Music\MusicRepeat.#ColorImage#.png
ImageAlpha=128

[StyleMusicArtButtonRepeat1]
ImageName=#@#Images\Music\MusicRepeat.#ColorImage#.png

[StyleMusicArtButtonShuffle0]
ImageName=#@#Images\Music\MusicShuffle.#ColorImage#.png
ImageAlpha=128

[StyleMusicArtButtonShuffle1]
ImageName=#@#Images\Music\MusicShuffle.#ColorImage#.png

[StyleMusicArtProgress]
X=(10+(4*#HideBordersBottom#))
Y=71
W=(#SidebarWidth#-20-(4*#HideBordersBottom#))
H=1
BarColor=#ColorBorder2#
SolidColor=#ColorBorder4#
BarOrientation=HORIZONTAL

;----------------------------------------------
; FULL

[StyleMusicFullBackground]
H=(#SidebarWidth#-2)

[StyleMusicFullBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersTop#

[StyleMusicFullHeader]
X=0
Y=0
W=0
H=0
Hidden=1

[StyleMusicFullIconBack]
ImageName=#@#Images\MusicAlbumFull.#ColorImage#.png
X=12
Y=10
W=(#SidebarWidth#-24)
H=(#SidebarWidth#-24)
AntiAlias=1

[StyleMusicFullIcon]
X=1r
Y=1r
W=(#SidebarWidth#-26)
H=(#SidebarWidth#-26)
AntiAlias=1

[StyleMusicFullCurtain]
SolidColor=#ColorFilter3#
X=r
Y=r
W=(#SidebarWidth#-26)
H=(#SidebarWidth#-26)
Hidden=1
Group=EnigmaMouseover

[StyleMusicFullText]
X=14
Y=5R
W=(#SidebarWidth#-78)
H=15
ClipString=1
FontFace=#Font#
FontSize=#Size1#
StringAlign=LEFT
StringStyle=NORMAL
AntiAlias=1
Hidden=1
Group=EnigmaMouseover

[StyleMusicFullTextFirst]
FontColor=#Color1#
Y=14

[StyleMusicFullTextSecond]
FontColor=#Color2#

[StyleMusicFullTextThird]
FontColor=#Color3#

[StyleMusicFullTime]
X=(#SidebarWidth#-14)
Y=(#SidebarWidth#-35-(#HideBordersBottom#*15))
StringAlign=RIGHT
StringStyle=BOLD
FontColor=#Color1#
FontFace=#Font#
FontSize=#Size1#
AntiAlias=1
Hidden=1
Group=EnigmaMouseover

[StyleMusicFullButton]
X=6R
Y=(#SidebarWidth#-35-(#HideBordersBottom#*15))
W=15
H=15
AntiAlias=1
Hidden=1
Group=EnigmaMouseover
ToolTipWidth=#SidebarWidth#

[StyleMusicFullButtonPrevious]
ImageName=#@#Images\Music\MusicPrevious.#ColorImage#.png
X=19

[StyleMusicFullButtonPlayPause0]
ImageName=#@#Images\Music\MusicPlay.#ColorImage#.png

[StyleMusicFullButtonPlayPause1]
ImageName=#@#Images\Music\MusicPause.#ColorImage#.png

[StyleMusicFullButtonPlayPause2]
ImageName=#@#Images\Music\MusicPlay.#ColorImage#.png

[StyleMusicFullButtonNext]
ImageName=#@#Images\Music\MusicNext.#ColorImage#.png

[StyleMusicFullButtonRepeat0]
ImageName=#@#Images\Music\MusicRepeat.#ColorImage#.png
ImageAlpha=128

[StyleMusicFullButtonRepeat1]
ImageName=#@#Images\Music\MusicRepeat.#ColorImage#.png

[StyleMusicFullButtonShuffle0]
ImageName=#@#Images\Music\MusicShuffle.#ColorImage#.png
ImageAlpha=128

[StyleMusicFullButtonShuffle1]
ImageName=#@#Images\Music\MusicShuffle.#ColorImage#.png

[StyleMusicFullProgress]
X=(12+(4*#HideBordersBottom#))
Y=(#SidebarWidth#-7-(#HideBordersBottom#*15))
W=(#SidebarWidth#-24-(8*#HideBordersBottom#))
H=1
BarColor=#ColorBorder2#
SolidColor=#ColorBorder4#
BarOrientation=HORIZONTAL
Hidden=#HideBordersBottom#
Group=EnigmaMouseover