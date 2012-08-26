[Variables]
PanelHeight=440
ArrowY=328
LabelsQueue=SidebarSpacingFixed|TaskbarSpacingFixed|TaskbarHideTriptych

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
MeterStyle=StyleText | StyleInput
Text="#SidebarWidth#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 1"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SidebarWidth')"
TooltipTitle="Sidebar Width (px)"
TooltipText=Click to type the width of the Sidebar skins. Your other skins will automatically adjust their widths to the sidebars'.

[SidebarAlphaName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Transparency"

[SidebarAlphaText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#SidebarAlpha#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 2"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SidebarAlpha')"
TooltipTitle="Sidebar Transparency (0-255)"
TooltipText=Click to adjust the transparency of the Sidebar's background image. (You can also change the transparency of the skin itself, but this will also reduce the visibility of the blur effect.)

[SidebarSpacingFixedName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Spacing"

[SidebarSpacingFixedText]
Meter=STRING
MeterStyle=StyleText
Text="#SidebarSpacingFixedLabel#"
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('SidebarSpacingFixed')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SidebarSpacingFixed')"
TooltipTitle="Sidebar Spacing (Y/N)"
TooltipText=Click to toggle whether the Sidebar reserves space on the desktop for the Taskbar.

;-----------------------

[TaskbarHeightName]
Meter=STRING
MeterStyle=StyleName
Text="Taskbar Height"

[TaskbarHeightText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#TaskbarHeight#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 3"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarHeight')"
TooltipTitle="Taskbar Height (px)"
TooltipText=Click to type the height of the Taskbar. Your other skins will automatically adjust their heights to the taskbar's.

[TaskbarAlphaName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Transparency"

[TaskbarAlphaText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#TaskbarAlpha#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 4"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarAlpha')"
TooltipTitle="Taskbar Transparency (0-255)"
TooltipText=Click to adjust the transparency of the Taskbar's background image. (You can also change the transparency of the skin itself, but this will also reduce the visibility of the blur effect.)

[TaskbarSpacingFixedName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Spacing"

[TaskbarSpacingFixedText]
Meter=STRING
MeterStyle=StyleText
Text="#TaskbarSpacingFixedLabel#"
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('TaskbarSpacingFixed')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarSpacingFixed')"
TooltipTitle="Taskbar Spacing (Y/N)"
TooltipText=Click to toggle whether the Taskbar reserves space on the desktop for the Sidebar.

[TaskbarMaxSkinWidthName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Maximum Text Width"

[TaskbarMaxSkinWidthText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#TaskbarMaxSkinWidth#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 5"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarMaxSkinWidth')"
TooltipTitle="Maximum Text Width for Taskbar Skins (px)"
TooltipText=Taskbar skins automatically resize to fit the displayed text. Text longer than the maximum will be clipped.

[TaskbarMinSkinWidthName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Minimum Text Width"

[TaskbarMinSkinWidthText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#TaskbarMinSkinWidth#"
LeftMouseUpAction=!CommandMeasure "MeasureInputLayout" "ExecuteBatch 6"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarMinSkinWidth')"
TooltipTitle="Minimum Text Width for Taskbar Skins (px)"
TooltipText=Taskbar skins automatically resize to fit the displayed text. If the text is shorter than the minimum, the skin background will expand to fill the remaining space.

[TaskbarHideTriptychName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Triptych"

[TaskbarHideTriptychText]
Meter=STRING
MeterStyle=StyleText
Text="#TaskbarHideTriptychLabel#"
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('TaskbarHideTriptych')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarHideTriptych')"
TooltipTitle="Show Taskbar Triptych? (Y/N)"
TooltipText=Divides the Taskbar and Second Taskbar skins into thirds. This may or may not look very good depending on the taskbar image you've selected.

;-----------------------

[BarImageName]
Meter=STRING
MeterStyle=StyleName
Text="Textures"

[BarImageBase]
Meter=IMAGE
ImageName=#@#Images\Home\ConfigLayout.png
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
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TaskbarImage')"
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
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SecondTaskbarImage')"
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
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SidebarImage')"
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
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SecondSidebarImage')"
TooltipTitle="Second Sidebar Background Image"
TooltipText=Click each bar to type the locations of the background images used by your Taskbar, Second Taskbar, Sidebar and Second Sidebar.

;-----------------------

[RestoreDefault]
Meter=STRING
MeterStyle=StyleText | StyleRestoreDefault