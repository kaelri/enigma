[Variables]
PanelHeight=460
ArrowY=48

;---------------------------------------------------------------------
; MEASURES

[MeasureCalendarExtraDaysSubstitute]
Measure=CALC
Formula=#CalendarExtraDays#
Substitute="1":"Yes","0":"No"

[MeasureCalendarLeadingZeroesSubstitute]
Measure=CALC
Formula=#CalendarLeadingZeroes#
Substitute="1":"Yes","0":"No"

[MeasureCalendarMondaysSubstitute]
Measure=CALC
Formula=#CalendarMondays#
Substitute="1":"Monday","0":"Sunday"

[MeasureGalleryPreserveRatioSubstitute]
Measure=CALC
Formula=#GalleryPreserveRatio#
Substitute="1":"Yes","0":"No"

[MeasureGallerySubfoldersSubstitute]
Measure=CALC
Formula=#GallerySubfolders#
Substitute="1":"Yes","0":"No"

[MeasureTriptychDisabledSubstitute]
Measure=CALC
Formula=#TriptychDisabled#
Substitute="1":"No","0":"Yes"

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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Note1Path" "#Settings#" "#Note1Path#"]
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Note2Path" "#Settings#" "#Note2Path#"]
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "File" "Variables" "Note3Path" "#Settings#" "#Note3Path#"]
TooltipTitle="3rd Text File Location"
TooltipText=Click to choose the text files to be displayed by each of Enigma Notes' three 'pages.' By default, Enigma uses text files inside its own folder to store your notes. However, you may wish to use an external file to integrate it with another application, or to prevent it from being erased when you update your Rainmeter skins.

[NotesHeightName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Height"

[NotesHeightText]
Meter=STRING
MeterStyle=StyleText
Text="#NoteHeight#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 1"
TooltipTitle="Notes Display Height (pixels)"
TooltipText=You can choose the height of Enigma Notes' display area. Any content in your notes file below this point will not be displayed, although you can store as much as you want in the file.

;-----------------------

[Drive1Name]
Meter=STRING
MeterStyle=StyleName
Text="1st Drive"

[Drive1Text]
Meter=STRING
MeterStyle=StyleText
Text="#Drive1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 2"
TooltipTitle="1st Drive Letter"
TooltipText=Click to type the letters of up to three of your hard drives or SSDs. Enigma System will display the free and used space on these drives. You do not need to include the colon.

[Drive2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd Drive"

[Drive2Text]
Meter=STRING
MeterStyle=StyleText
Text="#Drive2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 3"
TooltipTitle="2nd Drive Letter"
TooltipText=Click to type the letters of up to three of your hard drives or SSDs. Enigma System will display the free and used space on these drives. You do not need to include the colon.

[Drive3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd Drive"

[Drive3Text]
Meter=STRING
MeterStyle=StyleText
Text="#Drive3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 4"
TooltipTitle="3rd Drive Letter"
TooltipText=Click to type the letters of up to three of your hard drives or SSDs. Enigma System will display the free and used space on these drives. You do not need to include the colon.

;-----------------------

[NetworkMaxDownloadName]
Meter=STRING
MeterStyle=StyleName
Text=Max Down Speed

[NetworkMaxDownloadText]
Meter=STRING
MeterStyle=StyleText
Text="#NetworkMaxDownload#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 5"
TooltipTitle="Maximum Download Speed (B)"
TooltipText=Click to type your maximum upload and download speeds (in bytes). Enigma Network will show your network activity as a percentage of these figures.

[NetworkMaxUploadName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text=Max Up Speed

[NetworkMaxUploadText]
Meter=STRING
MeterStyle=StyleText
Text="#NetworkMaxUpload#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 6"
TooltipTitle="Maximum Upload Speed (B)"
TooltipText=Click to type your maximum upload and download speeds (in bytes). Enigma Network will show your network activity as a percentage of these figures.

;-----------------------

[CalendarMondaysName]
Meter=STRING
MeterStyle=StyleName
Text="Calendar Start Day"

[CalendarMondaysText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureCalendarMondaysSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables CalendarMondays (1-#CalendarMondays#) "#Settings#"][!Refresh *]
TooltipTitle="First Weekday on Calendar Rows (Sun/Mon)"
TooltipText=Click to toggle whether the Calendar skins show weeks beginning with Sunday or Monday.

[CalendarExtraDaysName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Extra Dates"

[CalendarExtraDaysText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureCalendarExtraDaysSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables CalendarExtraDays (1-#CalendarExtraDays#) "#Settings#"][!Refresh *]
TooltipTitle="Show Extra Calendar Days (Y/N)"
TooltipText=Click to toggle whether Enigma Calendar shows dates from the next and previous months.

[CalendarLeadingZeroesName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Leading Zeroes"

[CalendarLeadingZeroesText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureCalendarLeadingZeroesSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables CalendarLeadingZeroes (1-#CalendarLeadingZeroes#) "#Settings#"][!Refresh *]
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
LeftMouseUpAction=["#@#Addons\RainFile\RainFile.exe" "Folder" "Variables" "GalleryPath" "#Settings#" "#GalleryPath#"]
TooltipTitle="Folder Location (C:\Users\...)"
TooltipText=Click to type the path to the folder containing the images which you would like Enigma Gallery to display.

[GallerySubfoldersName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Include Subfolders?"

[GallerySubfoldersText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureGallerySubfoldersSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables GallerySubfolders (1-#GallerySubfolders#) "#Settings#"][!Refresh *]
TooltipTitle="Include Subfolders (Y/N)"
TooltipText=Choose whether the Gallery skin includes images in subfolders within your chosen path.

[GalleryRatioName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Aspect Ratio"

[GalleryRatioText]
Meter=STRING
MeterStyle=StyleText
Text="#GalleryRatio#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 7"
TooltipTitle="Image Aspect Ratio (width/height)"
TooltipText=You can also determine the aspect ratio of the Gallery skin's display window. (The skin itself allows you to toggle whether the displayed images are stretched to fit this ratio.)

;-----------------------

[VolumeIncrementName]
Meter=STRING
MeterStyle=StyleName
Text="Volume Step"

[VolumeIncrementText]
Meter=STRING
MeterStyle=StyleText
Text="#VolumeIncrement#%"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 8"
TooltipTitle="Volume Change Increment (percent)"
TooltipText=Click to change the amount by which Enigma Volume increases and decreases your system volume when clicked.

;-----------------------

[TriptychIntervalName]
Meter=STRING
MeterStyle=StyleName
Text="Switcher Time"

[TriptychIntervalText]
Meter=STRING
MeterStyle=StyleText
Text="#TriptychInterval#"
LeftMouseUpAction=!CommandMeasure "MeasureInputGeneral" "ExecuteBatch 9"
TooltipTitle="Switcher Rotation Period (seconds)"
TooltipText=Click to type the length of time (in seconds) that Enigma Reader, Gcal, Remember The Milk, Notes, and Gallery display one tab before automatically rotating to the next.

[TriptychDisabledName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Enable Switcher"

[TyiptychDisabledText]
Meter=STRING
MeterStyle=StyleText
MeasureName=MeasureTriptychDisabledSubstitute
LeftMouseUpAction=[!WriteKeyValue Variables TriptychDisabled (1-#TriptychDisabled#) "#Settings#"][!Refresh *]
TooltipTitle="Enable Switcher Action (Y/N)"
TooltipText=You can choose to disable the switcher action entirely.

;-----------------------

[RestoreDefaultGeneral]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables Note1Path "#DefaultNote1Path#" "#Settings#"][!WriteKeyValue Variables Note2Path "#DefaultNote2Path#" "#Settings#"][!WriteKeyValue Variables Note3Path "#DefaultNote3Path#" "#Settings#"][!WriteKeyValue Variables NoteHeight "#DefaultNoteHeight#" "#Settings#"][!WriteKeyValue Variables NoteDisablePages "#DefaultNoteDisablePages#" "#Settings#"][!WriteKeyValue Variables Drive1 "#DefaultDrive1#" "#Settings#"][!WriteKeyValue Variables Drive2 "#DefaultDrive2#" "#Settings#"][!WriteKeyValue Variables Drive3 "#DefaultDrive3#" "#Settings#"][!WriteKeyValue Variables NetworkMaxDownload "#DefaultNetworkMaxDownload#" "#Settings#"][!WriteKeyValue Variables NetworkMaxUpload "#DefaultNetworkMaxUpload#" "#Settings#"][!WriteKeyValue Variables CalendarMondays "#DefaultCalendarMondays#" "#Settings#"][!WriteKeyValue Variables CalendarExtraDays "#DefaultCalendarExtraDays#" "#Settings#"][!WriteKeyValue Variables CalendarLeadingZeroes "#DefaultCalendarLeadingZeroes#" "#Settings#"][!WriteKeyValue Variables GalleryPath "#DefaultGalleryPath#" "#Settings#"][!WriteKeyValue Variables GallerySubfolders "#DefaultGallerySubfolders#" "#Settings#"][!WriteKeyValue Variables GalleryTime "#DefaultGalleryTime#" "#Settings#"][!WriteKeyValue Variables GalleryRatio "#DefaultGalleryRatio#" "#Settings#"][!WriteKeyValue Variables VolumeIncrement "#DefaultVolumeIncrement#" "#Settings#"][!Refresh *]
TooltipText=Click here to reset all General settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.