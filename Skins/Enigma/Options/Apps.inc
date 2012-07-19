[Variables]
PanelHeight=520
ArrowY=208
LabelsQueue=

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
MeterStyle=StyleText | StyleInput
Text="#App1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 1"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App1')"
TooltipTitle="1st Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App1PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App1PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App1Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 2"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App1Path')"
TooltipTitle="1st File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App1LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App1LabelText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App1Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 3"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App1Label')"
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App1Icon" "#EnigmaSettings#" "#App1Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App1Icon')"
TooltipTitle="1st Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App2Name]
Meter=STRING
MeterStyle=StyleName
Text="2nd Launcher App"

[App2Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 4"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App2')"
TooltipTitle="2nd Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App2PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App2PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App2Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 5"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App2Path')"
TooltipTitle="2nd File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App2LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App2LabelText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App2Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 6"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App2Label')"
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App2Icon" "#EnigmaSettings#" "#App2Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App2Icon')"
TooltipTitle="2nd Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App3Name]
Meter=STRING
MeterStyle=StyleName
Text="3rd Launcher App"

[App3Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 7"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App3')"
TooltipTitle="3rd Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App3PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App3PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App3Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 8"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App3Path')"
TooltipTitle="3rd File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App3LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App3LabelText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App3Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 9"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App3Label')"
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App3Icon" "#EnigmaSettings#" "#App3Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App3Icon')"
TooltipTitle="3rd Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App4Name]
Meter=STRING
MeterStyle=StyleName
Text="4th Launcher App"

[App4Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App4#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 10"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App4')"
TooltipTitle="4th Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App4PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App4PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App4Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 11"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App3Path')"
TooltipTitle="4th File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App4LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App4LabelText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App4Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 12"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App4Label')"
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App4Icon" "#EnigmaSettings#" "#App4Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App4Icon')"
TooltipTitle="4th Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[App5Name]
Meter=STRING
MeterStyle=StyleName
Text="5th Launcher App"

[App5Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App5#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 13"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App5')"
TooltipTitle="5th Application Name"
TooltipText=Click to type the names, locations, icons and one-word descriptions of up to five of your favorite applications, folders or web addresses. These will be used by Enigma Launcher to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' and 'label' of each Launcher is purely cosmetic, and will not affect the function of the skin.

[App5PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Location"

[App5PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App5Path#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 14"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App5Path')"
TooltipTitle="5th File Location"
TooltipText=Type the location of a file, folder or website as if you were opening it from the Windows 'Run' box. Some apps, such as Notepad and Firefox, do not require the full filepath. You can simply type e.g. 'notepad.exe' or 'firefox.exe'.

[App5LabelName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Label"

[App5LabelText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#App5Label#"
LeftMouseUpAction=!CommandMeasure "MeasureInputApps" "ExecuteBatch 15"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App5Label')"
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "App5Icon" "#EnigmaSettings#" "#App5Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('App5Icon')"
TooltipTitle="5th Image Location"
TooltipText=You may choose any BMP, JPG, PNG, GIF or ICO image to use as an icon. Square images are recommended.

;-----------------------

[RestoreDefault]
Meter=STRING
MeterStyle=StyleText | StyleRestoreDefault