#cs
	file: base/client.au3
	author: wuuyi123
#ce

Global $tag_CefClient = $tag_CefBase & _
	'ptr GetContextMenuHandler;' & _
	'ptr GetDialogHandler;' & _
	'ptr GetDisplayHandler;' & _
	'ptr GetDownloadHandler;' & _
	'ptr GetDragHandler;' & _
	'ptr GetFindHandler;' & _
	'ptr GetFocusHandler;' & _
	'ptr GetGeolocationHandler;' & _
	'ptr GetJSDialogHandler;' & _
	'ptr GetKeyboardHandler;' & _
	'ptr GetLifeSpanHandler;' & _
	'ptr GetLoadHandler;' & _
	'ptr GetRenderHandler;' & _
	'ptr GetRequestHandler;' & _
	'ptr OnProcessMessageReceived;'

Global $__params_GetContextMenuHandler = 'ptr', _
	$__return_GetContextMenuHandler = 'ptr'

Global $__params_GetDialogHandler = 'ptr', _
	$__return_GetDialogHandler = 'ptr'

Global $__params_GetDisplayHandler = 'ptr', _
	$__return_GetDisplayHandler = 'ptr'

Global $__params_GetDownloadHandler = 'ptr', _
	$__return_GetDownloadHandler = 'ptr'

Global $__params_GetDragHandler = 'ptr', _
	$__return_GetDragHandler = 'ptr'

Global $__params_GetFindHandler = 'ptr', _
	$__return_GetFindHandler = 'ptr'

Global $__params_GetFocusHandler = 'ptr', _
	$__return_GetFocusHandler = 'ptr'

Global $__params_GetGeolocationHandler = 'ptr', _
	$__return_GetGeolocationHandler = 'ptr'

Global $__params_GetJSDialogHandler = 'ptr', _
	$__return_GetJSDialogHandler = 'ptr'

Global $__params_GetKeyboardHandler = 'ptr', _
	$__return_GetKeyboardHandler = 'ptr'

Global $__params_GetLifeSpanHandler = 'ptr', _
	$__return_GetLifeSpanHandler = 'ptr'

Global $__params_GetLoadHandler = 'ptr', _
	$__return_GetLoadHandler = 'ptr'

Global $__params_GetRenderHandler = 'ptr', _
	$__return_GetRenderHandler = 'ptr'

Global $__params_GetRequestHandler = 'ptr', _
	$__return_GetRequestHandler = 'ptr'

Global $__params_OnProcessMessageReceived = 'ptr;ptr;int;ptr', _
	$__return_OnProcessMessageReceived = 'int'