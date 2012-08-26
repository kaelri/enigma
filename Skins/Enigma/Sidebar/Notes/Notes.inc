[Variables]
CurrentNote=1

;---------------------------------------------------------------------
; MEASURES

[MeasureActivateTabs]
Measure=Script
ScriptFile=#@#Measures\Tabs.lua
UpdateDivider=-1
Type=Notes
TotalTabs=8

[MeasureNote]
Measure=Script
ScriptFile="#@#Measures\Notes.lua"
UpdateDivider=10
Path=#NotesFile1#
ContentDivider=<donotshow>
FinishAction=[!UpdateMeasureGroup "NotesData"][!UpdateMeterGroup "NotesData"][!Redraw][!SetVariable Reset 0]

[MeasureActive1]
Measure=Calc
Formula=#CurrentNote#=1
DynamicVariables=1
Group=NotesData | Tab2
Disabled=1

[MeasureActive2]
Measure=Calc
Formula=#CurrentNote#=2
DynamicVariables=1
Group=NotesData | Tab2
Disabled=1

[MeasureActive3]
Measure=Calc
Formula=#CurrentNote#=3
DynamicVariables=1
Group=NotesData | Tab3
Disabled=1

[MeasureActive4]
Measure=Calc
Formula=#CurrentNote#=4
DynamicVariables=1
Group=NotesData | Tab4
Disabled=1

[MeasureActive5]
Measure=Calc
Formula=#CurrentNote#=5
DynamicVariables=1
Group=NotesData | Tab5
Disabled=1

[MeasureActive6]
Measure=Calc
Formula=#CurrentNote#=6
DynamicVariables=1
Group=NotesData | Tab6
Disabled=1

[MeasureActive7]
Measure=Calc
Formula=#CurrentNote#=7
DynamicVariables=1
Group=NotesData | Tab7
Disabled=1

[MeasureActive8]
Measure=Calc
Formula=#CurrentNote#=8
DynamicVariables=1
Group=NotesData | Tab8
Disabled=1

;---------------------------------------------------------------------
; METERS

[Border]
Meter=IMAGE
MeterStyle=StyleNotesBorder

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleNotesBackground

[Icon]
Meter=IMAGE
MeterStyle=StyleNotesIcon

[Title]
Meter=STRING
Group=NotesData
MeterStyle=StyleNotesTitle
Text=#Name#
LeftMouseUpAction=["#Path#"]
ToolTipTitle=Edit Notes
ToolTipText=#Path#
DynamicVariables=1

[Notes]
Meter=STRING
Group=NotesData
MeterStyle=StyleNotesText
Text=#Content#
LeftMouseUpAction=["#Path#"]
ToolTipTitle=Edit Notes
ToolTipText=#Path#
DynamicVariables=1

;-----------------------
; BUTTONS

[BorderBottom]
Meter=IMAGE
MeterStyle=StyleNotesBorderBottom

[Grabber1]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive1] | StyleNotesGrabberFirst
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(1)"
Group=NotesData | Tab2
Hidden=1

[Grabber2]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive2]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(2)"
Group=NotesData | Tab2
Hidden=1

[Grabber3]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive3]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(3)"
Group=NotesData | Tab2
Hidden=1

[Grabber4]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive4]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(4)"
Group=NotesData | Tab4
Hidden=1

[Grabber5]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive5]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(5)"
Group=NotesData | Tab5
Hidden=1

[Grabber6]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive6]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(6)"
Group=NotesData | Tab6
Hidden=1

[Grabber7]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive7]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(7)"
Group=NotesData | Tab7
Hidden=1

[Grabber8]
Meter=IMAGE
MeterStyle=StyleNotesGrabber | StyleNotesGrabber[MeasureActive8]
LeftMouseUpAction=!CommandMeasure "MeasureNote" "Show(8)"
Group=NotesData | Tab8
Hidden=1