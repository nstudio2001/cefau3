#include "../cefau3.h"

cef_client_t * __stdcall CefClient_Create()
{
	size_t sz = sizeof(cef_client_t);
	cef_client_t *p = calloc(1, sz);
	p->base.size = sz;

	return p;
}