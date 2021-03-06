#include "inc.h"

extern HINSTANCE __mainInstance;
extern HWND __mainHandleMessageWindow;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason) {
		case DLL_PROCESS_ATTACH: case DLL_THREAD_ATTACH:
			__mainInstance = hModule;
			break;
		case DLL_THREAD_DETACH:	case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}

void WINAPI Cef_RequireUI() {
	REQUIRE_UI_THREAD();
}

void WINAPI Cef_RequireIO() {
	REQUIRE_IO_THREAD();
}

void WINAPI Cef_RequireFILE() {
	REQUIRE_FILE_THREAD();
}

HWND WINAPI Cef_GetHandle(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	HWND hWnd = handler->GetBrowser()->GetHost()->GetWindowHandle();
	return !hWnd ? 0 : hWnd;
}

void WINAPI Cef_EnableHighDPI()
{
	CefEnableHighDPISupport();
}

HINSTANCE Cef_GetMainInstance()
{
	return __mainInstance;
}

void WINAPI Cef_Reload(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->Reload();
}

void WINAPI Cef_GoBack(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GoBack();
}

void WINAPI Cef_GoForward(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GoForward();
}

bool WINAPI Cef_CanGoBack(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->CanGoBack();
}

bool WINAPI Cef_CanGoForward(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->CanGoForward();
}

void WINAPI Cef_StopLoad(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->StopLoad();
}

void WINAPI Cef_LoadURL(Cefau3_Handler* handler, LPCWSTR lpszURL)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->LoadURL(lpszURL);
}

LPCWSTR WINAPI Cef_GetURL(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->GetMainFrame()->GetURL().ToWString().c_str();
}

void WINAPI Cef_Cut(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->Cut();
}

void WINAPI Cef_Copy(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->Copy();
}

void WINAPI Cef_Paste(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->Paste();
}

void WINAPI Cef_Delete(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->Delete();
}

void WINAPI Cef_Undo(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->Undo();
}

void WINAPI Cef_Redo(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->Redo();
}

void WINAPI Cef_SelectAll(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->SelectAll();
}

void WINAPI Cef_ViewSource(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	handler->GetBrowser()->GetMainFrame()->ViewSource();
}

LPCWSTR WINAPI Cef_GetName(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->GetMainFrame()->GetName().ToWString().c_str();
}

bool WINAPI Cef_IsFocused(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->GetMainFrame()->IsFocused();
}

bool WINAPI Cef_IsValid(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->GetMainFrame()->IsValid();
}

bool WINAPI Cef_IsMain(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	return handler->GetBrowser()->GetMainFrame()->IsMain();
}

void WINAPI Cef_FullSize(Cefau3_Handler* handler)
{
	CEF_REQUIRE_UI_THREAD();
	HWND hWnd = handler->GetHandle();
	HWND hParent = GetParent(handler->GetHandle());
	RECT rc; GetClientRect(hParent, &rc);
	MoveWindow(hWnd, 0, 0, rc.right, rc.bottom, false);
}

void WINAPI Cef_ExecuteJs(Cefau3_Handler* handler, LPCWSTR lpszCode)
{
	CEF_REQUIRE_UI_THREAD();
	auto Frame = handler->GetBrowser()->GetMainFrame();
	Frame->ExecuteJavaScript(lpszCode, Frame->GetURL(), 0);
}

void WINAPI Cef_ExitMessageLoop(int exit_code)
{
	REQUIRE_UI_THREAD();
	SendMessage(__mainHandleMessageWindow, 0x0111, QUITAPPMESSAGE, exit_code);
}

void WINAPI Cef_Close(Cefau3_Handler* handler)
{
	REQUIRE_UI_THREAD();
	handler->DoClose(handler->GetBrowser());
}

void WINAPI Cef_Shutdown()
{
	REQUIRE_UI_THREAD();
	CefShutdown();
}