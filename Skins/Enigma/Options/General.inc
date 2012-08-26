[Variables]
PanelHeight=550
ArrowY=48
LabelsQueue=CalendarShowEvents|CalendarExtraDays|CalendarLeadingZeroes|CalendarMondays|GallerySubfolders|TriptychDisabled

;---------------------------------------------------------------------
; METERS

;-----------------------
; INDICATOR ARROW

[Arrow]
Meter=IMAGE
MeterStyle=StyleMenuArrow
Y=#ArrowY#

;-----------------------
; GENERAL

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=G  E  N  E  R  A  L

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set general preferences that apply to a number of skins.
H=24

;-----------------------

[Notes1PathName]
Meter=STRING
MeterStyle=StyleName
Text="1st Notes File"

[Notes1PathText]
Meter=STRING
MeterStyle=StyleText
Text="#Note1Path#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Note1Path" "#EnigmaSettings#" "#Note1Path#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Note1Path')"
TooltipTitle="1st Text File Location"
TooltipText=Click to choose the text files to be displayed by each of Enigma Notes' three 'pages.' By default, Enigma uses text files inside its own folder to store your notes. However, you may wish to use an external file to integrate it with another application, or to prevent it from being erased when you update your Rainmeter skins.

[Notes2PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd Notes File"

[Notes2PathText]
Meter=STRING
MeterStyle=StyleText
Text="#Note2Path#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Note2Path" "#EnigmaSettings#" "#Note2Path#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Note2Path')"
TooltipTitle="2nd Text File Location"
TooltipText=Click to choose the text files to be displayed by each of Enigma Notes' three 'pages.' By default, Enigma uses text files inside its own folder to store your notes. However, you may wish to use an external file to integrate it with another application, or to prevent it from being erased when you update your Rainmeter skins.

[Notes3PathName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd Notes File"

[Notes3PathText]
Meter=STRING
MeterStyle=StyleText
Text="#Note3Path#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Note3Path" "#EnigmaSettings#" "#Note3Path#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Note3Path')"
TooltipTitle="3rd Text File Location"
TooltipText=Click to choose the text files to be displayed by each of Enigma Notes' three 'pages.' By default, Enigma uses text files inside its own folder to store your notes. However, you may wish to use an external file to integrate it with another application, or to prevent it from being erased when you update your Rainmeter skins.

[NotesHeightName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Height"

[NotesHeightText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#NoteHeight#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 1"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('NoteHeight')"
TooltipTitle="Notes Display Height (pixels)"
TooltipText=You can choose the height of Enigma Notes' display area. Any content in your notes file below this point will not be displayed, although you can store as much as you want in the file.

;-----------------------

[Drive1Name]
Meter=STRING
MeterStyle=StyleName
Text="1st Drive"

[Drive1Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Drive1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 2"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Drive1')"
TooltipTitle="1st Drive Letter"
TooltipText=Click to type the letters of up to three of your hard drives or SSDs. Enigma System will display the free and used space on these drives. You do not need to include the colon.

[Drive2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd Drive"

[Drive2Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Drive2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 3"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Drive2')"
TooltipTitle="2nd Drive Letter"
TooltipText=Click to type the letters of up to three of your hard drives or SSDs. Enigma System will display the free and used space on these drives. You do not need to include the colon.

[Drive3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd Drive"

[Drive3Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Drive3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 4"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Drive3')"
TooltipTitle="3rd Drive Letter"
TooltipText=Click to type the letters of up to three of your hard drives or SSDs. Enigma System will display the free and used space on these drives. You do not need to include the colon.

;-----------------------

[SystemGraphTypeName]
Meter=STRING
MeterStyle=StyleName
Text=Graph Type

[SystemGraphTypeText]
Meter=STRING
MeterStyle=StyleText
Text="#SystemGraphType#"
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('SystemGraphType')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('SystemGraphType')"
TooltipTitle="System Graph Type (Floating/Percent)"
TooltipText=Click to toggle how the Enigma System and Network skins show graphs. "Floating" means that the maximum will be the highest value on the graph. "Percent" means that the maximum will be 100% (for CPU) or your max upload/download speeds (for Network).

[NetworkMaxDownloadName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text=Max Down Speed

[NetworkMaxDownloadText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#NetworkMaxDownload#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 5"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('NetworkMaxDownload')"
TooltipTitle="Maximum Download Speed (B)"
TooltipText=Click to type your maximum upload and download speeds (in bytes). Enigma Network will show your network activity as a percentage of these figures.

[NetworkMaxUploadName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text=Max Up Speed

[NetworkMaxUploadText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#NetworkMaxUpload#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 6"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('NetworkMaxUpload')"
TooltipTitle="Maximum Upload Speed (B)"
TooltipText=Click to type your maximum upload and download speeds (in bytes). Enigma Network will show your network activity as a percentage of these figures.

;-----------------------

[CalendarEventFileName]
Meter=STRING
MeterStyle=StyleName
Text="Calendar File"

[CalendarEventFileText]
Meter=STRING
MeterStyle=StyleText
Text=#CalendarEventFile#
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "CalendarEventFile" "#EnigmaSettings#" "#CalendarEventFile#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('CalendarEventFile')"
TooltipTitle="Calendar Event Library (Filepath)"
TooltipText=Click to select one or more calendar files to display events in Enigma Calendar.

[CalendarShowEventsName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Show Events"

[CalendarShowEventsText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('CalendarShowEvents')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('CalendarShowEvents')"
TooltipTitle="Show Event Tooltips on Calendar (Yes/No)"
TooltipText=Click to toggle whether the Calendar skins show events from your selected calendar file(s).

[CalendarMondaysName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Start Day"

[CalendarMondaysText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('CalendarMondays')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('CalendarMondays')"
TooltipTitle="First Weekday on Calendar Rows (Sun/Mon)"
TooltipText=Click to toggle whether the Calendar skins show weeks beginning with Sunday or Monday.

[CalendarExtraDaysName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Extra Dates"

[CalendarExtraDaysText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('CalendarExtraDays')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('CalendarExtraDays')"
TooltipTitle="Show Extra Calendar Days (Y/N)"
TooltipText=Click to toggle whether Enigma Calendar shows dates from the next and previous months.

[CalendarLeadingZeroesName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Leading Zeroes"

[CalendarLeadingZeroesText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('CalendarLeadingZeroes')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('CalendarLeadingZeroes')"
TooltipTitle="Show Leading Zeroes on Calendar Dates (Y/N)"
TooltipText=You can also toggle whether the calendar shows leading zeroes for one-digit dates.

;-----------------------

[GalleryPathName]
Meter=STRING
MeterStyle=StyleName
Text="Gallery Path"

[GalleryPathText]
Meter=STRING
MeterStyle=StyleText
Text="#GalleryPath#"
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "Folder" "Variables" "GalleryPath" "#EnigmaSettings#" "#GalleryPath#"]
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GalleryPath')"
TooltipTitle="Folder Location (C:\Users\...)"
TooltipText=Click to type the path to the folder containing the images which you would like Enigma Gallery to display.

[GallerySubfoldersName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Include Subfolders?"

[GallerySubfoldersText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('GallerySubfolders')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GallerySubfolders')"
TooltipTitle="Include Subfolders (Y/N)"
TooltipText=Choose whether the Gallery skin includes images in subfolders within your chosen path.

[GalleryRatioName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Aspect Ratio"

[GalleryRatioText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#GalleryRatio#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 7"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GalleryRatio')"
TooltipTitle="Image Aspect Ratio (width/height)"
TooltipText=You can also determine the aspect ratio of the Gallery skin's display window. (The skin itself allows you to toggle whether the displayed images are stretched to fit this ratio.)

[GalleryPositionName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Wallpaper Position"

[GalleryPositionText]
Meter=STRING
MeterStyle=StyleText
Text=#GalleryPosition#
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('GalleryPosition')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GalleryPosition')"
TooltipTitle="Wallpaper Position (Center, Tile, Stretch, Fit, Fill)"
TooltipText=Choose how the Gallery skin sets your desktop wallpaper. "Fit" and "Fill" are compatible with Windows 7 and above.

;-----------------------

[VolumeIncrementName]
Meter=STRING
MeterStyle=StyleName
Text="Volume Step"

[VolumeIncrementText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#VolumeIncrement#%"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 8"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('VolumeIncrement')"
TooltipTitle="Volume Change Increment (percent)"
TooltipText=Click to change the amount by which Enigma Volume increases and decreases your system volume when clicked.

;-----------------------

[TriptychIntervalName]
Meter=STRING
MeterStyle=StyleName
Text="Switcher Time"

[TriptychIntervalText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#TriptychInterval#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 9"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TriptychInterval')"
TooltipTitle="Switcher Rotation Period (seconds)"
TooltipText=Click to type the length of time (in seconds) that Enigma Reader, Gcal, Remember The Milk, Notes, and Gallery display one tab before automatically rotating to the next.

[TriptychDisabledName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Enable Switcher"

[TriptychDisabledText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('TriptychDisabled')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TriptychDisabled')"
TooltipTitle="Enable Switcher Action (Y/N)"
TooltipText=You can choose to disable the switcher action entirely.

;-----------------------

[ProcessIntervalName]
Meter=STRING
MeterStyle=StyleName
Text="Process Time"

[ProcessIntervalText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#ProcessInterval#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 10"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('ProcessInterval')"
TooltipTitle="Process Update Period (seconds)"
TooltipText=Click to type the period between updates (in seconds) for Enigma Process.

;-----------------------

[RestoreDefault]
Meter=STRING
MeterStyle=StyleText | StyleRestoreDefault