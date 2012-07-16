#NoTrayIcon
#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_icon=RainRGB.ico
#AutoIt3Wrapper_outfile=..\..\Addons\RainRGB4\RainRGB4.exe
#AutoIt3Wrapper_UseUpx=n
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****
#include <GUIConstantsEx.au3>
#include <WindowsConstants.au3>
#include <Misc.au3>
#include <Array.au3>
#Include "RainChooser.au3"
#Include "ColorPicker.au3"

Opt("WinTitleMatchMode", 4)
;RainRGB VarName=AnyName FileName="Path\File" Alpha=0-255 or NULL RefreshConfig=AnyConfig or * or NULL

If _ArraySearch($CmdLine, "VarName=",0,0,0,1) = -1 Or _ArraySearch($CmdLine, "FileName=",0,0,0,1) = -1 Then Exit

Global $FullRGB = 0

$Index1 = _ArraySearch($CmdLine, "VarName=",0,0,0,1)
$VarName = StringRight($CmdLine[$Index1], StringLen($CmdLine[$Index1]) - StringLen("VarName="))
$Index2 = _ArraySearch($CmdLine, "FileName=",0,0,0,1)
$FileName = StringRight($CmdLine[$Index2], StringLen($CmdLine[$Index2]) - StringLen("FileName="))
$Index3 = _ArraySearch($CmdLine, "Alpha=",0,0,0,1)
If $Index3 <> -1 Then
	$Alpha = StringRight($CmdLine[$Index3], StringLen($CmdLine[$Index3]) - StringLen("Alpha="))
Else
	$Alpha = ""
EndIf
$Index4 = _ArraySearch($CmdLine, "RefreshConfig=",0,0,0,1)
If $Index4 <> -1 Then
	$ConfigArray = StringSplit($CmdLine[$Index4], " | ", 1)
	$ConfigArray[1] = StringReplace($ConfigArray[1], "RefreshConfig=", "")
Else
	$Config = ""
EndIf

If $VarName = "" Then Exit
If $FileName = "" Then Exit


$FileVarString = IniRead($FileName, "Variables", $VarName, "")
If $FileVarString = "" Then Exit

If StringInStr($FileVarString, ",") Then
	$HexOrRGB = "R"
	$SplitFileVarString = StringSplit($FileVarString, ",")
	If $SplitFileVarString[0] = 4 Then
		If $Alpha = "" Then $Alpha = $SplitFileVarString[4]
		$FileVarString = $SplitFileVarString[1] & "," & $SplitFileVarString[2] & "," & $SplitFileVarString[3]
	EndIf

Else

	$HexOrRGB = "H"
	If $Alpha <> "" Then
		$Alpha = StringRight(hex($Alpha),2)
	Else
		If StringLen($FileVarString) = 8 Then
			$Alpha = StringRight($FileVarString, 2)
			$FileVarString = StringLeft($FileVarString, 6)
		ElseIf StringLen($FileVarString) > 8 Then
			$Alpha = StringRight($FileVarString, StringLen($FileVarString)-6)
		Else
			$Alpha = ""
		EndIf
	EndIf

EndIf

If $HexOrRGB = "R" Then
	$CurrentColor = "0x" & StringRight(hex($SplitFileVarString[1]),2) & StringRight(hex($SplitFileVarString[2]),2) & StringRight(hex($SplitFileVarString[3]),2)
Else
	$CurrentColor = "0x" & StringLeft($FileVarString, 6)
EndIf

$GUIHidden = GUICreate("RainRGB4", 463, 337, -1, -1)
$PickedColor = _ColorChooserDialog($CurrentColor, $GUIHIdden, 0, 0, -1, "RainRGB")
$PickedColor="0x" & StringRight(Hex($PickedColor),6)
If $PickedColor = -1 Then Exit
If $HexOrRGB = "H" Then $ReturnColor = StringRight($PickedColor, 6)
If $HexOrRGB = "R" Then $ReturnColor = dec(StringMId($PickedColor, 3,2)) & "," & dec(StringMid($PickedColor, 5,2)) & "," & dec(StringRight($PickedColor,2))

If $HexOrRGB = "H" Then
	IniWrite($FileName, "Variables", $VarName, $ReturnColor & $Alpha)
Else
	If $Alpha <> "" Then IniWrite($FileName, "Variables", $VarName, $ReturnColor & "," & $Alpha)
	If $Alpha = "" Then IniWrite($FileName, "Variables", $VarName, $ReturnColor)
EndIf

If $Index4 <> -1 Then
	For $i = 1 To $ConfigArray[0]
		Refresh($ConfigArray[$i])
	Next
Else
	Refresh("*")
EndIf

Func Refresh($ConfigName)

$hwnd = WinGetHandle('classname=RainmeterMeterWindow')
$iMsg = 0x004A

Local Const $szBang = "!Refresh " & $ConfigName
$iSize = StringLen($szBang) + 1

$pMem = DllStructCreate("ushort[" & $iSize & "]")
For $i = 0 To $iSize
	DllStructSetData($pMem, 1, Asc(StringMid($szBang, $i, 1)), $i)
Next
DllStructSetData($pMem, 1, 0, $iSize)

$stCds = DllStructCreate("dword;dword;ptr")
DllStructSetData($stCds, 1, 1)
DllStructSetData($stCds, 2, ($iSize * 2))
DllStructSetData($stCds, 3, DllStructGetPtr($pMem))
_SendMessage($hwnd, $iMsg, 0, DllStructGetPtr($stCds))

EndFunc