[Variables]
PanelHeight=445
ArrowY=248
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
; SEARCH

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=S  E  A  R  C  H

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set the search engines or commands run by Enigma Search.
H=24

;-----------------------

[Search1Name]
Meter=STRING
MeterStyle=StyleName
Text="1st Search Engine"

[Search1Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 1"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search1')"
TooltipTitle="1st Search Engine Name"
TooltipText=Click to type the names, icons and parameters of up to five of your favorite search engines or Windows Run commands. These will be used by Enigma Search to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' of each search skin is purely cosmetic, and will not affect the function of the skins.

[Search1PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Command"

[Search1PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search1Command#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 2"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search1Command')"
TooltipTitle="1st Command"
TooltipText=Type a URL that you would enter into your browser's address bar, or a command that you would enter into the Windows 'Run' box. Include the term '$UserInput$' where your search or command term would go.

[Search1IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[Search1IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#Search1Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Search1Icon" "#EnigmaSettings#" "#Search1Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search1Icon')"
TooltipTitle="1st Image Location"
TooltipText=Any BMP, JPG, PNG or GIF image can be used as an icon. Square images are recommended.

;-----------------------

[Search2Name]
Meter=STRING
MeterStyle=StyleName
Text="2nd Search Engine"

[Search2Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 3"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search2')"
TooltipTitle="2nd Search Engine Name"
TooltipText=Click to type the names, icons and parameters of up to five of your favorite search engines or Windows Run commands. These will be used by Enigma Search to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' of each search skin is purely cosmetic, and will not affect the function of the skins.

[Search2PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Command"

[Search2PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search2Command#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 4"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search2Command')"
TooltipTitle="2nd Command"
TooltipText=Type a URL that you would enter into your browser's address bar, or a command that you would enter into the Windows 'Run' box. Include the term '$UserInput$' where your search or command term would go.

[Search2IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[Search2IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#Search2Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Search2Icon" "#EnigmaSettings#" "#Search2Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search2Icon')"
TooltipTitle="2nd Image Location"
TooltipText=Any BMP, JPG, PNG or GIF image can be used as an icon. Square images are recommended.

;-----------------------

[Search3Name]
Meter=STRING
MeterStyle=StyleName
Text="3rd Search Engine"

[Search3Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 5"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search3')"
TooltipTitle="3rd Search Engine Name"
TooltipText=Click to type the names, icons and parameters of up to five of your favorite search engines or Windows Run commands. These will be used by Enigma Search to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' of each search skin is purely cosmetic, and will not affect the function of the skins.

[Search3PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Command"

[Search3PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search3Command#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 6"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search3Command')"
TooltipTitle="3rd Command"
TooltipText=Type a URL that you would enter into your browser's address bar, or a command that you would enter into the Windows 'Run' box. Include the term '$UserInput$' where your search or command term would go.

[Search3IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[Search3IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#Search3Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Search3Icon" "#EnigmaSettings#" "#Search3Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search3Icon')"
TooltipTitle="3rd Image Location"
TooltipText=Any BMP, JPG, PNG or GIF image can be used as an icon. Square images are recommended.

;-----------------------

[Search4Name]
Meter=STRING
MeterStyle=StyleName
Text="4th Search Engine"

[Search4Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search4#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 7"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search4')"
TooltipTitle="4th Search Engine Name"
TooltipText=Click to type the names, icons and parameters of up to five of your favorite search engines or Windows Run commands. These will be used by Enigma Search to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' of each search skin is purely cosmetic, and will not affect the function of the skins.

[Search4PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Command"

[Search4PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search4Command#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 8"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search4Command')"
TooltipTitle="4th Command"
TooltipText=Type a URL that you would enter into your browser's address bar, or a command that you would enter into the Windows 'Run' box. Include the term '$UserInput$' where your search or command term would go.

[Search4IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[Search4IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#Search4Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Search4Icon" "#EnigmaSettings#" "#Search4Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search4Icon')"
TooltipTitle="4th Image Location"
TooltipText=Any BMP, JPG, PNG or GIF image can be used as an icon. Square images are recommended.

;-----------------------

[Search5Name]
Meter=STRING
MeterStyle=StyleName
Text="5th Search Engine"

[Search5Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search5#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 9"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search5')"
TooltipTitle="5th Search Engine Name"
TooltipText=Click to type the names, icons and parameters of up to five of your favorite search engines or Windows Run commands. These will be used by Enigma Search to display links and buttons which launch these locations when clicked.#CRLF##CRLF#The 'name' of each search skin is purely cosmetic, and will not affect the function of the skins.

[Search5PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Command"

[Search5PathText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Search5Command#"
LeftMouseUpAction=!CommandMeasure "MeasureInputSearch" "ExecuteBatch 10"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search5Command')"
TooltipTitle="5th Command"
TooltipText=Type a URL that you would enter into your browser's address bar, or a command that you would enter into the Windows 'Run' box. Include the term '$UserInput$' where your search or command term would go.

[Search5IconName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Icon"

[Search5IconText]
Meter=IMAGE
MeterStyle=StyleImage
ImageName="#Search5Icon#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Search5Icon" "#EnigmaSettings#" "#Search5Icon#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Search5Icon')"
TooltipTitle="5th Image Location"
TooltipText=Any BMP, JPG, PNG or GIF image can be used as an icon. Square images are recommended.

;-----------------------

[RestoreDefault]
Meter=STRING
MeterStyle=StyleText | StyleRestoreDefault