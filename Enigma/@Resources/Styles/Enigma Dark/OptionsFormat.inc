[Variables]
PanelHeight=395
ArrowY=288

;---------------------------------------------------------------------
; MEASURES

[MeasureWriteColorImage]
Measure=CALC
Formula=#ColorImageType#
IfEqualValue=1
IfEqualAction=[!WriteKeyValue Variables ColorImage W "#StyleSettings#"][!DisableMeasure MeasureWriteColorImage]
IfAboveValue=1
IfAboveAction=[!WriteKeyValue Variables ColorImage B "#StyleSettings#"][!DisableMeasure MeasureWriteColorImage]

[MeasureColorImageTypeSubstitute]
Measure=CALC
Formula=#ColorImageType#
Substitute="1":"W","2":"B"

[MeasureHideBordersTopSubstitute]
Measure=CALC
Formula=#HideBordersTop#
Substitute="0":"Yes","1":"No"

[MeasureHideBordersBottomSubstitute]
Measure=CALC
Formula=#HideBordersBottom#
Substitute="0":"Yes","1":"No"

;---------------------------------------------------------------------
; METERS

;-----------------------
; INDICATOR ARROW

[Arrow]
Meter=IMAGE
MeterStyle=StyleMenuArrow
Y=#ArrowY#

;-----------------------
; FORMAT

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=F  O  R  M  A  T

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set font, color and options for your stylesheet.
H=24

;-----------------------

[StylesheetName]
Meter=STRING
MeterStyle=StyleName
Text="Stylesheet"

[StylesheetText]
Meter=STRING
MeterStyle=StyleText
Text="#Stylesheet#"
StringStyle=BOLD
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 1"
TooltipTitle="Stylesheet Name (Enigma Light/Enigma Dark/[Other])"
TooltipText=Click to type the name of the Enigma Stylesheet that you would like to use. This will affect the images and color scheme used throughout Enigma.#CRLF##CRLF#Enigma comes with two stylesheets: 'Enigma Dark' and 'Enigma Light'. If you have downloaded additional stylesheets, place them in Skins\Enigma\Resources\Styles.

;-----------------------

[PrimaryColorName]
Meter=STRING
MeterStyle=StyleName
Text="Colors"

[PrimaryColorBackground]
Meter=IMAGE
MeterStyle=StyleColorBackground | StyleColorBackgroundFirst

[PrimaryColor]
Meter=IMAGE
MeterStyle=StyleColor
SolidColor=#Color1#
LeftMouseUpAction=["#RainRGB#" "VarName=Color1" "FileName=#StyleSettings#" "RefreshConfig=Enigma\Resources"]
TooltipTitle="Primary Color"
TooltipText=Click to choose the primary text color for #Stylesheet#'s skins. This is the color in which most actual content will be shown. Labels will be a more translucent version of the same color.

[LinkColorBackground]
Meter=IMAGE
MeterStyle=StyleColorBackground

[LinkColor]
Meter=IMAGE
MeterStyle=StyleColor
SolidColor=#ColorLink#
LeftMouseUpAction=["#RainRGB#" "VarName=ColorLink" "FileName=#StyleSettings#" "RefreshConfig=Enigma\Resources"]
TooltipTitle="Link Color"
TooltipText=Click to choose #Stylesheet#'s link color. This is the color that will appear on some clickable text and buttons.

[BorderColorBackground]
Meter=IMAGE
MeterStyle=StyleColorBackground | StyleColorBackground

[BorderColor]
Meter=IMAGE
MeterStyle=StyleColor
SolidColor=#ColorBorder#
LeftMouseUpAction=["#RainRGB#" "VarName=ColorBorder" "FileName=#StyleSettings#" "RefreshConfig=Enigma\Resources"]
TooltipTitle="Border Color"
TooltipText=Click to choose #Stylesheet#'s border color. This is the color of borders, outlines and separators.

[PanelColorBackground]
Meter=IMAGE
MeterStyle=StyleColorBackground | StyleColorBackgroundNewRow

[PanelColor]
Meter=IMAGE
MeterStyle=StyleColor
SolidColor=#ColorPanel#
LeftMouseUpAction=["#RainRGB#" "VarName=ColorPanel" "FileName=#StyleSettings#" "RefreshConfig=Enigma\Resources"]
TooltipTitle="Menu Panel Color"
TooltipText=Click to choose #Stylesheet#'s panel color. This is the color of control panel menus, such as the one to the left.

[FilterColorBackground]
Meter=IMAGE
MeterStyle=StyleColorBackground

[FilterColor]
Meter=IMAGE
MeterStyle=StyleColor
SolidColor=#ColorFilter#
LeftMouseUpAction=["#RainRGB#" "VarName=ColorFilter" "FileName=#StyleSettings#" "RefreshConfig=Enigma\Resources"]
TooltipTitle="Filter Color"
TooltipText=Click to choose #Stylesheet#'s filter color. This color is used to soften the texture of the Taskbar skin.

[TransparentColorBackground]
Meter=IMAGE
MeterStyle=StyleColorBackground

[TransparentColor]
Meter=IMAGE
MeterStyle=StyleColor
SolidColor=#ColorTransparent#
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 2"
TooltipTitle="Transparent Background Color"
TooltipText=Click to type the color of #Stylesheet#'s transparent backgrounds. This color must be written numerically. The default color is "0,0,0,2" - black and almost completely transparent - and should only be changed when debugging skin sizes and positions.

;-----------------------

[ColorImageName]
Meter=STRING
MeterStyle=StyleName
Text="Images"

[ColorImageIcon]
Meter=IMAGE
MeterStyle=StyleImage | StyleImageNoTint
MeasureName=MeasureColorImageTypeSubstitute
ImageName=#@#Images\Home\Config.%1.png
LeftMouseUpAction=[!WriteKeyValue Variables ColorImageType (3-#ColorImageType#) "#StyleSettings#"][!Refresh *]
TooltipTitle="Image Color (W/B)"
TooltipText=Click to type the color of #Stylesheet#'s images. For Enigma Dark, this should be "W" (white) for optimal contrast. For Enigma Light, use "B" (black). This setting may be irrelevant depending on your chosen stylesheet.

;-----------------------

[FontName]
Meter=STRING
MeterStyle=StyleName
Text="Font"

[FontText]
Meter=STRING
MeterStyle=StyleText
Text="#Font#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 3"
TooltipTitle="Font Name"
TooltipText=Click to type the name of the font used throughout #Stylesheet#. If you aren't sure which name to use, or whether your font is compatible with Rainmeter, you should use Jeff Morley's RainFont utility.

[Size1Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="1st Size"

[Size1Text]
Meter=STRING
MeterStyle=StyleText
Text="#Size1#"
FontSize=#Size1#
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 4"
TooltipTitle="1st Font Size"
TooltipText=You may change the font sizes used in #Stylesheet#. Be aware, however, that most skins are not infinitely flexible, and dramatic changes may break the layout of your skins.

[Size2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd Size"

[Size2Text]
Meter=STRING
MeterStyle=StyleText
Text="#Size2#"
FontSize=#Size2#
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 5"
TooltipTitle="2nd Font Size"
TooltipText=You may change the font sizes used in #Stylesheet#. Be aware, however, that most skins are not infinitely flexible, and dramatic changes may break the layout of your skins.

[Size3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd Size"

[Size3Text]
Meter=STRING
MeterStyle=StyleText
Text="#Size3#"
FontSize=#Size3#
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 6"
TooltipTitle="3rd Font Size"
TooltipText=You may change the font sizes used in #Stylesheet#. Be aware, however, that most skins are not infinitely flexible, and dramatic changes may break the layout of your skins.

[Size4Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="4th Size"

[Size4Text]
Meter=STRING
MeterStyle=StyleText
Text="#Size4#"
FontSize=#Size4#
LeftMouseUpAction=!CommandMeasure "MeasureInputFormat" "ExecuteBatch 7"
TooltipTitle="4th Font Size"
TooltipText=You may change the font sizes used in #Stylesheet#. Be aware, however, that most skins are not infinitely flexible, and dramatic changes may break the layout of your skins.

;-----------------------

[SidebarBordersTopName]
Meter=STRING
MeterStyle=StyleName
Text="Sidebar Borders"

[SidebarBordersTopText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureHideBordersTopSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables HideBordersTop (1-#HideBordersTop#) "#StyleSettings#"][!Refresh *]
TooltipTitle="Show Sidebar Borders (Y/N)"
TooltipText=Click to toggle whether Enigma Sidebar skins display a separator at the top and/or bottom of each skin.

[SidebarBordersBottomName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Bottom Borders"

[SidebarBordersBottomText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureHideBordersBottomSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables HideBordersBottom (1-#HideBordersBottom#) "#StyleSettings#"][!Refresh *]
TooltipTitle="Show Bottom Borders (Y/N)"
TooltipText=Click to toggle whether Enigma Sidebar skins display a separator at the top and/or bottom of each skin.

;-----------------------

[RestoreDefaultMusic]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables Color1 "#DefaultColor1#" "#StyleSettings#"][!WriteKeyValue Variables ColorLink "#DefaultColorLink#" "#StyleSettings#"][!WriteKeyValue Variables ColorBorder "#DefaultColorBorder#" "#StyleSettings#"][!WriteKeyValue Variables ColorPanel "#DefaultColorPanel#" "#StyleSettings#"][!WriteKeyValue Variables ColorFilter "#DefaultColorFilter#" "#StyleSettings#"][!WriteKeyValue Variables ColorTransparent "#DefaultColorTransparent#" "#StyleSettings#"][!WriteKeyValue Variables ColorImage "#DefaultColorImage#" "#StyleSettings#"][!WriteKeyValue Variables Size1 "#DefaultSize1#" "#StyleSettings#"][!WriteKeyValue Variables Size4 "#DefaultSize4#" "#StyleSettings#"][!WriteKeyValue Variables Size3 "#DefaultSize3#" "#StyleSettings#"][!WriteKeyValue Variables Size2 "#DefaultSize2#" "#StyleSettings#"][!WriteKeyValue Variables Font "#DefaultFont#" "#StyleSettings#"][!WriteKeyValue Variables HideBordersTop "#DefaultHideBordersTop#" "#StyleSettings#"][!WriteKeyValue Variables HideBordersBottom "#DefaultHideBordersBottom#" "#StyleSettings#"][!Refresh *]
TooltipText=Click here to reset all #Stylesheet# Format settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.