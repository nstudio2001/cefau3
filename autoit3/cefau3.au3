#cs

Name:.............: Cefau3 - Chromium Embedded Frame Work for AutoIt3
AutoIt version:...: v3.3.14.5
Author:...........: wuuyi123
Page:.............: https://github.com/wy3/cefau3

program/
	|---app/...
	|	|---css/...			# style
	|	|---js/...			# javascript
	|	|---app.js			# app
	|	|---index.html		# index
	|
	|---cef/...				# resources
	|	|---locales/...
	|	|---autoitx3.dll	# autoitx3
	|	|---libcef.dll		# libcef
	|	|---cefau3.dll		# cefau3
	|
	|---include/...			# your autoit header
	|---cefau3/...			# cefau3 udf
	|	|---base/...
	|	|---cefau3.au3
	|
	|---main.au3			# main script
	|...

#ce

Global $__Cefau3Dll__ = Null
Global $__Cefau3DllName__ = 'cefau3.dll'

#include './base/base.au3'
#include './base/app.au3'
#include './base/client.au3'

Func CefStart($CefPath = @ScriptDir & '\cef')
	DllCall('kernel32.dll', 'int', 'SetCurrentDirectoryW', 'wstr', $CefPath)
	Local $ret = DllOpen($__Cefau3DllName__)
	DllCall('kernel32.dll', 'int', 'SetCurrentDirectoryW', 'wstr', @ScriptDir)
	If @error Or ($ret == -1) Then Return 0
	$__Cefau3Dll__ = $ret
	Return 1
EndFunc

Func CefRelease($CefHandler)
	If (Not $CefHandler) Return
	DllCall($__Cefau3Dll__, 'none', 'CefRelease', 'ptr', $CefHandler)
EndFunc

Func CefEnd()
	If ($__Cefau3Dll__)	DllClose($__Cefau3Dll__)
EndFunc






