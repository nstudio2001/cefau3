#include "cefau3.h"

void __stdcall CefRelease(void *p)
{
	if (p) free(p);
}

