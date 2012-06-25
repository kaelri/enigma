;--------------------------------------------------------------------------------------------
; SIDEBAR GALLERY

[Rainmeter]
Group=EnigmaSidebar
MiddleMouseUpAction=!Refresh

;-----------------------

[StyleGalleryBackground]
SolidColor=#ColorTransparent#
W=#SidebarWidth#
H=(((#SidebarWidth#-24)*(#GalleryRatio#))+20)

[StyleGalleryBorder]
SolidColor=#ColorBorder4#
X=10
Y=5
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersTop#

[StyleGalleryPhotoBackground]
SolidColor=#ColorFilter3#
X=12
Y=10
W=(#SidebarWidth#-24)
H=((#SidebarWidth#-24)*(#GalleryRatio#))

[StyleGalleryPhoto]
X=1r
Y=1r
W=(#SidebarWidth#-26)
H=((#SidebarWidth#-26)*(#GalleryRatio#))
MouseOverAction=[!ShowMeterGroup Mouseover][!Update]
MouseLeaveAction=[!HideMeterGroup Mouseover][!Update]

[StyleGalleryCurtain]
Group=Mouseover
SolidColor=#ColorFilter3#
X=r
Y=r
W=(#SidebarWidth#-26)
H=((#SidebarWidth#-26)*(#GalleryRatio#))
Hidden=1

[StyleGalleryCaption]
Group=Mouseover
X=(#SIDEBARWIDTH#/2)
Y=2r
W=(#SidebarWidth#-30)
H=((#SidebarWidth#-30)*(#GalleryRatio#)-30)
FontFace=#Font#
FontColor=#Color1#
FontSize=#Size1#
StringAlign=CENTER
StringEffect=SHADOW
AntiAlias=1
ClipString=1
ToolTipWidth=#SidebarWidth#
Hidden=1

[StyleGalleryButton]
Group=Mouseover
Y=((#SidebarWidth#-24)*(#GalleryRatio#)-25)
FontFace=Webdings
FontColor=#Color1#
FontSize=20
StringAlign=CENTER
StringEffect=SHADOW
SolidColor=#ColorTransparent#
ToolTipWidth=#SidebarWidth#
Hidden=1

[StyleGalleryButtonOpen]
X=(#SIDEBARWIDTH#/4)
Text=1

[StyleGalleryButtonNext]
X=((#SIDEBARWIDTH#/4)*2)
Text=8

[StyleGalleryButtonChangeRatio]
X=((#SIDEBARWIDTH#/4)*3)
Text=2

[StyleGalleryBorderBottom]
SolidColor=#ColorBorder4#
X=10
Y=(((#SidebarWidth#-24)*(#GalleryRatio#))+15)
W=(#SidebarWidth#-20)
H=1
Hidden=#HideBordersBottom#