#include "../cefau3.h"

cef_app_t * __stdcall CefApp_Create()
{
	size_t sz = sizeof(cef_app_t);
	cef_app_t *p = calloc(1, sz);
	p->base.size = sz;

	return p;
}

int __stdcall CefExecuteProcess(const struct _cef_main_args_t* args, cef_app_t* application)
{
	return cef_execute_process(
		args,
		application,
		NULL
	);
}

int __stdcall CefInitialize(const struct _cef_main_args_t* args,
	const struct _cef_settings_t* settings,
	cef_app_t* application,
	void* windows_sandbox_info)
{
	return cef_initialize(
		args,
		settings,
		application,
		NULL
	);
}

void __stdcall CefShutdown()
{
	cef_shutdown();
}

void __stdcall CefDoMessageLoopWork()
{
	cef_do_message_loop_work();
}

void __stdcall CefRunMessageLoop()
{
	cef_run_message_loop();
}

void __stdcall CefQuitMessageLoop()
{
	cef_quit_message_loop();
}

void __stdcall CefSetOSModalLoop(int osModalLoop)
{
	cef_set_osmodal_loop(
		osModalLoop
	);
}

void __stdcall CefEnableHighDPISupport()
{
	cef_enable_highdpi_support();
}