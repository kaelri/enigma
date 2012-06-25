[Variables]
PanelHeight=395
ArrowY=328

;---------------------------------------------------------------------
; MEASURES

[MeasureWallpaper]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop
RegValue=Wallpaper
UpdateDivider=30

;---------------------------------------------------------------------
; METERS

;-----------------------
; INDICATOR ARROW

[Arrow]
Meter=IMAGE
MeterStyle=StyleMenuArrow
Y=#ArrowY#

;-----------------------
; LAYOUT

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=L  A  Y  O  U  T

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set Taskbar and Sidebar options for your stylesheet.
H=24

;-----------------------

[SidebarWidthName]
Meter=STRING
MeterStyle=StyleName
Text="Sidebar Width"

[SidebarWidthText]
Meter=STRING
MeterStyle=StyleText
Text="#SidebarWidth#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 1"
TooltipTitle="Sidebar Width (px)"
TooltipText=Click to type the width of the Sidebar skins. Your other skins will automatically adjust their widths to the sidebars'.

[SidebarAlphaName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Transparency"

[SidebarAlphaText]
Meter=STRING
MeterStyle=StyleText
Text="#SidebarAlpha#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 2"
TooltipTitle="Sidebar Transparency (0-255)"
TooltipText=Click to adjust the transparency of the Sidebar's background image. (You can also change the transparency of the skin itself, but this will also reduce the visibility of the blur effect.)

[SidebarSpacingName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Spacing"

[SidebarSpacingText]
Meter=STRING
MeterStyle=StyleText
Text="#SidebarSpacing#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 3"
TooltipTitle="Sidebar Spacing (px)"
TooltipText=You can adjust the spacing left between the sidebar and the top (or bottom) of the screen. This is usually where the Taskbar skin goes, so it should be the same as the Taskbar Height. If you don't want to use the taskbar, set this to 0.

;-----------------------

[TaskbarHeightName]
Meter=STRING
MeterStyle=StyleName
Text="Taskbar Height"

[TaskbarHeightText]
Meter=STRING
MeterStyle=StyleText
Text="#TaskbarHeight#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 4"
TooltipTitle="Taskbar Height (px)"
TooltipText=Click to type the height of the Taskbar. Your other skins will automatically adjust their heights to the taskbar's.

[TaskbarAlphaName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Transparency"

[TaskbarAlphaText]
Meter=STRING
MeterStyle=StyleText
Text="#TaskbarAlpha#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 5"
TooltipTitle="Taskbar Transparency (0-255)"
TooltipText=Click to adjust the transparency of the Taskbar's background image. (You can also change the transparency of the skin itself, but this will also reduce the visibility of the blur effect.)

[TaskbarSpacingName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Spacing"

[TaskbarSpacingText]
Meter=STRING
MeterStyle=StyleText
Text="#TaskbarSpacing#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 6"
TooltipTitle="Taskbar Spacing (px)"
TooltipText=You can also adjust the spacing left between the taskbar and the left (or right) of the screen. If you want the taskbar to span the entire screen width, this should be kept at zero.

;-----------------------

[BarImageName]
Meter=STRING
MeterStyle=StyleName
Text="Backgrounds"

[BarImageBase]
Meter=IMAGE
ImageName=#@#Images\Home\ConfigLayout.W.png
X=215
Y=-9r

[BarImageBaseBackground]
Meter=IMAGE
MeasureName=MeasureWallpaper
X=23r
Y=26r
W=83
H=54

[TaskbarImage]
Meter=IMAGE
ImageAlpha=#TaskbarAlpha#
X=2r
Y=2r
H=7
W=79
TooltipWidth=300
ImageName=#TaskbarImage#
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "TaskbarImage" "#StyleSettings#" "#TaskbarImage#"]
TooltipTitle="Taskbar Background Image"
TooltipText=Click each bar to type the locations of the background images used by your Taskbar, Second Taskbar, Sidebar and Second Sidebar.

[SecondTaskbarImage]
Meter=IMAGE
ImageAlpha=#TaskbarAlpha#
X=r
Y=43r
H=7
W=79
TooltipWidth=300
ImageName=#SecondTaskbarImage#
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "SecondTaskbarImage" "#StyleSettings#" "#SecondTaskbarImage#"]
TooltipTitle="Second Taskbar Background Image"
TooltipText=Click each bar to type the locations of the background images used by your Taskbar, Second Taskbar, Sidebar and Second Sidebar.

[SidebarImage]
Meter=IMAGE
ImageAlpha=#SidebarAlpha#
X=r
Y=-35r
H=34
W=14
TooltipWidth=300
ImageName=#SidebarImage#
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "SidebarImage" "#StyleSettings#" "#SidebarImage#"]
TooltipTitle="Sidebar Background Image"
TooltipText=Click each bar to type the locations of the background images used by your Taskbar, Second Taskbar, Sidebar and Second Sidebar.

[SecondSidebarImage]
Meter=IMAGE
ImageAlpha=#SidebarAlpha#
X=65r
Y=r
H=34
W=14
TooltipWidth=300
ImageName=#SecondSidebarImage#
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "SecondSidebarImage" "#StyleSettings#" "#SecondSidebarImage#"]
TooltipTitle="Second Sidebar Background Image"
TooltipText=Click each bar to type the locations of the background images used by your Taskbar, Second Taskbar, Sidebar and Second Sidebar.

;-----------------------

[RestoreDefaultMusic]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables SidebarWidth "#DefaultSidebarWidth#" "#StyleSettings#"][!WriteKeyValue Variables SidebarAlpha "#DefaultSidebarAlpha#" "#StyleSettings#"][!WriteKeyValue Variables SidebarSpacing "#DefaultSidebarSpacing#" "#StyleSettings#"][!WriteKeyValue Variables TaskbarHeight "#DefaultTaskbarHeight#" "#StyleSettings#"][!WriteKeyValue Variables TaskbarAlpha "#DefaultTaskbarAlpha#" "#StyleSettings#"][!WriteKeyValue Variables TaskbarSpacing "#DefaultTaskbarSpacing#" "#StyleSettings#"][!WriteKeyValue Variables SidebarImage "#DefaultSidebarImage#" "#StyleSettings#"][!WriteKeyValue Variables SecondSidebarImage "#DefaultSecondSidebarImage#" "#StyleSettings#"][!WriteKeyValue Variables TaskbarImage "#DefaultTaskbarImage#" "#StyleSettings#"][!WriteKeyValue Variables SecondTaskbarImage "#DefaultSecondTaskbarImage#" "#StyleSettings#"][!Refresh *]
TooltipText=Click here to reset all #Stylesheet# Layout settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.