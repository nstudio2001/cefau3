#cs
	file: base/app.au3
	author: wuuyi123
#ce

Global $tag_CefApp = $tag_CefBase 			& _
	'ptr OnBeforeCommandLineProcessing;' 	& _
	'ptr OnRegisterCustomSchemes;' 			& _
	'ptr GetResourceBundleHandler;' 		& _
	'ptr GetBrowserProcessHandler; '		& _
	'ptr GetRenderProcessHandler'

Global $__params_OnBeforeCommandLineProcessing = 'ptr;ptr;ptr', _
	$__return_OnBeforeCommandLineProcessing = 'none'

Global $__params_OnRegisterCustomSchemes = 'ptr;ptr', _
	$__return_OnRegisterCustomSchemes = 'none'

Global $__params_GetResourceBundleHandler = 'ptr', _
	$__return_GetResourceBundleHandler = 'ptr'

Global $__params_GetBrowserProcessHandler = 'ptr', _
	$__return_GetBrowserProcessHandler = 'ptr'

Global $__params_GetRenderProcessHandler = 'ptr', _
	$__return_GetRenderProcessHandler = 'ptr'

Func CefExecuteProcess($CefMainArgs, $CefApp)
	Local $ret = DllCall($__Cefau3Dll__, 'int', 'CefExecuteProcess', _
		'ptr', $CefMainArgs, _
		'ptr', $CefApp _
	)
	Return @error ? 0 : $ret[0]
EndFunc

Func CefInitialize($CefMainArgs, $CefSettings, $CefApp)
	Local $ret = DllCall($__Cefau3Dll__, 'int', 'CefInitialize', _
		'ptr', $CefMainArgs, _
		'ptr', $CefSettings, _
		'ptr', $CefApp _
	)
	Return @error ? 0 : $ret[0]
EndFunc

Func CefShutdown()
	DllCall($__Cefau3Dll__, 'none', 'CefShutdown')
EndFunc

Func CefDoMessageLoopWork()
	DllCall($__Cefau3Dll__, 'none', 'CefDoMessageLoopWork')
EndFunc

Func CefRunMessageLoop()
	DllCall($__Cefau3Dll__, 'none', 'CefRunMessageLoop')
EndFunc

Func CefQuitMessageLoop()
	DllCall($__Cefau3Dll__, 'none', 'CefQuitMessageLoop')
EndFunc

Func CefSetOSModalLoop($osModalLoop)
	DllCall($__Cefau3Dll__, 'none', 'CefSetOSModalLoop', _
		'int', $osModalLoop _
	)
EndFunc

Func CefEnableHighDPISupport()
	DllCall($__Cefau3Dll__, 'none', 'CefEnableHighDPISupport')
EndFunc