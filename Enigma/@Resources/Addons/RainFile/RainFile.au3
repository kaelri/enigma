#NoTrayIcon
#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_icon=RainFile.ico
#AutoIt3Wrapper_outfile=RainFile.exe
#AutoIt3Wrapper_Res_Comment=RainFile
#AutoIt3Wrapper_Res_Description=Provides an Open File dialog for Rainmeter and passes input to external program. This version has been modified to send !RainmeterWriteKeyValue bangs to Rainmeter.exe.
#AutoIt3Wrapper_Res_Fileversion=0.9.4.0
#AutoIt3Wrapper_Res_Fileversion_AutoIncrement=p
#AutoIt3Wrapper_Res_LegalCopyright=By Kaelri (Kaelri@gmail.com) with contributions by Jeffrey Morley - Creative Commons Attribution-Noncommercial-Share Alike 3.0.
#AutoIt3Wrapper_Res_Language=1033
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****
#include <Array.au3>
#include <File.au3>
#include <SendMessage.au3>
#include <GUIConstantsEx.au3>
#include <WindowsConstants.au3>

$RAINMETER_QUERY_WINDOW = WinGetHandle("[CLASS:RainmeterTrayClass]")
$WM_QUERY_RAINMETER = $WM_APP + 1000
$RAINMETER_QUERY_ID_SKINS_PATH = 4101
$RAINMETER_QUERY_ID_SETTINGS_PATH = 4102
$RAINMETER_QUERY_ID_PROGRAM_PATH = 4104
$RAINMETER_QUERY_ID_CONFIG_EDITOR = 4106
$WM_QUERY_RAINMETER_RETURN = ""

$szDrive = ""
$szDir = ""
$szFName = ""
$szExt = ""

$hGUI = GUICreate("", 1, 1, -1, -1)

If Not ProcessExists("Rainmeter.exe") Then
	Exit
EndIf

GUIRegisterMsg($WM_COPYDATA, "_ReadMessage")

_SendMessage($RAINMETER_QUERY_WINDOW, $WM_QUERY_RAINMETER, $RAINMETER_QUERY_ID_PROGRAM_PATH, $hGUI)
$RainmeterPath = $WM_QUERY_RAINMETER_RETURN & "Rainmeter.exe"

_SendMessage($RAINMETER_QUERY_WINDOW, $WM_QUERY_RAINMETER, $RAINMETER_QUERY_ID_SKINS_PATH, $hGUI)
$RainmeterSkins = $WM_QUERY_RAINMETER_RETURN

If $CmdLine[0] > 4 Then
	$DialogType = $CmdLine[1]
	$SectionName = $CmdLine[2]
	$KeyName = $CmdLine[3]
	$TargetFile = $CmdLine[4]
	$Current = $CmdLine[5]
	If $CmdLine[0] > 5 Then
		$NameOnly = $CmdLine[6]
	Else
		$NameOnly = ""
	EndIf
	If $CmdLine[0] > 6 Then
		$Debug=1
	Else
		$Debug=0
	EndIf
Else
	If $Debug = 1 Then MsgBox("RainFile Error", 16, "Invalid number of parameters to RainFile.")
	Exit
EndIf

if $Debug = 1 Then
	_ArrayDisplay($Cmdline)
EndIf

If Not FileExists($TargetFile) Then
	If $Debug = 1 Then MsgBox(16, "RainFile Error", "Can't find target file: " & @CRLF & @CRLF & $TargetFile)
	Exit
Endif

If StringUpper($DialogType) = "FILE" Then
	_PathSplit($Current, $szDrive, $szDir, $szFName, $szExt)
	$CurrentPath = $szDrive & $szDir
	$CurrentFile = $szFName & $szExt
	$ChosenFile = FileOpenDialog( "Choose File", $CurrentPath, "All (*.*)", 3)
	If $ChosenFile = "" Then Exit
	If $Debug = 1 Then MsgBox("","Chosen File",$ChosenFile)
	_SendBang("!WriteKeyValue " & $SectionName & " " & $KeyName & " " & Chr(34) & $ChosenFile & chr(34) & " " & chr(34) &$TargetFile & chr(34))
	Sleep(100)
	_SendBang("!Refresh *")
Elseif StringUpper($DialogType) = "FOLDER" Then
	If $Current = "" Then
		$Current = StringLeft($RainmeterSkins, StringLen($RainmeterSkins)-1)
	EndIf
	$CurrentPath = $Current
	$ChosenFolder = FileSelectFolder("Choose Folder", "", 4, $CurrentPath)
	If $ChosenFolder = "" Then Exit
	If $Debug = 1 Then MsgBox("","Chosen Folder",$ChosenFolder)
	
	If StringUpper($NameOnly) = "NAMEONLY" Then
		_PathSplit($ChosenFolder, $szDrive, $szDir, $szFName, $szExt)
		_SendBang("!WriteKeyValue " & $SectionName & " " & $KeyName & " " & Chr(34) & $szFName & chr(34) & " " & chr(34) &$TargetFile & chr(34))
	Else
		_SendBang("!WriteKeyValue " & $SectionName & " " & $KeyName & " " & Chr(34) & $ChosenFolder & chr(34) & " " & chr(34) &$TargetFile & chr(34))
	EndIf
	
	Sleep(100)
	_SendBang("!Refresh *")
Else
	Exit
EndIf

Exit

Func _ReadMessage($hWnd, $uiMsg, $wParam, $lParam)

	$pCds = DllStructCreate("dword;dword;ptr", $lParam)

	$pData = DllStructGetData($pCds, 3)

	$pMem = DllStructCreate("wchar[" & DllStructGetData($pCds, 2) & "]", DllStructGetData($pCds, 3))

	$WM_QUERY_RAINMETER_RETURN = DllStructGetData($pMem, 1)

EndFunc ;_ReadMessage

Func _SendBang($szBang)

   Local Const $hWnd = WinGetHandle("[CLASS:RainmeterMeterWindow]")

   If $hWnd <> 0 Then
      Local Const $iSize = StringLen($szBang) + 1

      Local Const $pMem = DllStructCreate("wchar[" & $iSize & "]")
      DllStructSetData($pMem, 1, $szBang)

      Local Const $pCds = DllStructCreate("dword;dword;ptr")
      DllStructSetData($pCds, 1, 1)
      DllStructSetData($pCds, 2, ($iSize * 2))
      DllStructSetData($pCds, 3, DllStructGetPtr($pMem))

      Local Const $WM_COPYDATA = 0x004A
      _SendMessage($hWnd, $WM_COPYDATA, 0, DllStructGetPtr($pCds))
  EndIf

EndFunc ;_SendBang
