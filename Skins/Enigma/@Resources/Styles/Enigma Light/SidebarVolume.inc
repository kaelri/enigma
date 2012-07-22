;--------------------------------------------------------------------------------------------
; SIDEBAR GALLERY

[StyleVolumeBackground]
H=49

[StyleVolumeBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersTop#

[StyleVolumeIcon]
ImageName=#@#Images\Volume.%1.#ColorImage#.png
X=12
Y=12
W=25
H=25

[StyleVolumeFull]
SolidColor=#Color2#
SolidColor2=#Color1#
X=47
Y=22
W=(([MeasurePercent]/100)*(#SidebarWidth#-59))
H=4
DynamicVariables=1

[StyleVolumeEmpty]
SolidColor=#Color3#
SolidColor2=#Color4#
X=R
Y=r
W=(((100-[MeasurePercent])/100)*(#SidebarWidth#-59))
H=4
DynamicVariables=1

[StyleVolumeLabel]
Group=EnigmaMouseover
X=47
Y=3R
FontFace=#Font#
FontColor=#Color2#
FontSize=#Size4#
StringStyle=Bold
AntiAlias=1

[StyleVolumeText]
Group=EnigmaMouseover
X=R
Y=r
FontFace=#Font#
FontColor=#Color1#
FontSize=#Size4#
StringStyle=Bold
AntiAlias=1

[StyleVolumeBorderBottom]
SolidColor=#ColorBorder4#
X=10
Y=44
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersBottom#