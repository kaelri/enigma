[Variables]
PanelHeight=520
ArrowY=208

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

;-----------------------
; APPS

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=A  P  P  S

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set the applications, folders or websites opened by Enigma Launcher.
H=24

;-----------------------

[App1Name]
Meter=STRING
MeterStyle=StyleName
Text="1st Launcher App"

[App1Text]
Meter=STRING
MeterStyle=StyleText
Text="#App1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 1"
TooltipTitle="1st Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App1PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App1PathText]
Meter=STRING
MeterStyle=StyleText
Text="#App1Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 2"
TooltipTitle="1st File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App1LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App1LabelText]
Meter=STRING
MeterStyle=StyleText
Text="#App1Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 3"
TooltipTitle="1st Application Label"
TooltipText=The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App1IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[App1IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#App1Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App1Icon" "#Settings#" "#App1Icon#"]
TooltipTitle="1st Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App2Name]
Meter=STRING
MeterStyle=StyleName
Text="2nd Launcher App"

[App2Text]
Meter=STRING
MeterStyle=StyleText
Text="#App2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 4"
TooltipTitle="2nd Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App2PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App2PathText]
Meter=STRING
MeterStyle=StyleText
Text="#App2Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 5"
TooltipTitle="2nd File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App2LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App2LabelText]
Meter=STRING
MeterStyle=StyleText
Text="#App2Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 6"
TooltipTitle="2nd Application Label"
TooltipText=The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App2IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[App2IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#App2Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App2Icon" "#Settings#" "#App2Icon#"]
TooltipTitle="2nd Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App3Name]
Meter=STRING
MeterStyle=StyleName
Text="3rd Launcher App"

[App3Text]
Meter=STRING
MeterStyle=StyleText
Text="#App3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 7"
TooltipTitle="3rd Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App3PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App3PathText]
Meter=STRING
MeterStyle=StyleText
Text="#App3Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 8"
TooltipTitle="3rd File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App3LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App3LabelText]
Meter=STRING
MeterStyle=StyleText
Text="#App3Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 9"
TooltipTitle="3rd Application Label"
TooltipText=The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App3IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[App3IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#App3Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App3Icon" "#Settings#" "#App3Icon#"]
TooltipTitle="3rd Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App4Name]
Meter=STRING
MeterStyle=StyleName
Text="4th Launcher App"

[App4Text]
Meter=STRING
MeterStyle=StyleText
Text="#App4#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 10"
TooltipTitle="4th Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App4PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App4PathText]
Meter=STRING
MeterStyle=StyleText
Text="#App4Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 11"
TooltipTitle="4th File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App4LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App4LabelText]
Meter=STRING
MeterStyle=StyleText
Text="#App4Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 12"
TooltipTitle="4th Application Label"
TooltipText=The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App4IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[App4IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#App4Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App4Icon" "#Settings#" "#App4Icon#"]
TooltipTitle="4th Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App5Name]
Meter=STRING
MeterStyle=StyleName
Text="5th Launcher App"

[App5Text]
Meter=STRING
MeterStyle=StyleText
Text="#App5#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 13"
TooltipTitle="5th Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App5PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App5PathText]
Meter=STRING
MeterStyle=StyleText
Text="#App5Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 14"
TooltipTitle="5th File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App5LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App5LabelText]
Meter=STRING
MeterStyle=StyleText
Text="#App5Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 15"
TooltipTitle="5th Application Label"
TooltipText=The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App5IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[App5IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#App5Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App5Icon" "#Settings#" "#App5Icon#"]
TooltipTitle="5th Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[RestoreDefaultApps]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables App1 "#DefaultApp1#" "#Settings#"][!WriteKeyValue Variables App1Path "#DefaultApp1Path#" "#Settings#"][!WriteKeyValue Variables App1Label "#DefaultApp1Label#" "#Settings#"][!WriteKeyValue Variables App1Icon "#DefaultApp1Icon#" "#Settings#"][!WriteKeyValue Variables App2 "#DefaultApp2#" "#Settings#"][!WriteKeyValue Variables App2Path "#DefaultApp2Path#" "#Settings#"][!WriteKeyValue Variables App2Label "#DefaultApp2Label#" "#Settings#"][!WriteKeyValue Variables App2Icon "#DefaultApp2Icon#" "#Settings#"][!WriteKeyValue Variables App3 "#DefaultApp3#" "#Settings#"][!WriteKeyValue Variables App3Path "#DefaultApp3Path#" "#Settings#"][!WriteKeyValue Variables App3Label "#DefaultApp3Label#" "#Settings#"][!WriteKeyValue Variables App3Icon "#DefaultApp3Icon#" "#Settings#"][!WriteKeyValue Variables App4 "#DefaultApp4#" "#Settings#"][!WriteKeyValue Variables App4Path "#DefaultApp4Path#" "#Settings#"][!WriteKeyValue Variables App4Label "#DefaultApp4Label#" "#Settings#"][!WriteKeyValue Variables App4Icon "#DefaultApp4Icon#" "#Settings#"][!WriteKeyValue Variables App5 "#DefaultApp5#" "#Settings#"][!WriteKeyValue Variables App5Path "#DefaultApp5Path#" "#Settings#"][!WriteKeyValue Variables App5Label "#DefaultApp5Label#" "#Settings#"][!WriteKeyValue Variables App5Icon "#DefaultApp5Icon#" "#Settings#"][!Refresh *]
TooltipText=Click here to reset all App settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.