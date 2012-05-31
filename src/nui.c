#include "nui.h"
#include "native.h"
#include <stdio.h>
#include <stdarg.h>

void nui_init(NUI_INIT_ARGS_D)
{
	nui_native_init(NUI_INIT_ARGS_V);
}

int nui_run()
{
	// Launch the native main loop which process events
	nui_native_main_loop();
	return 0;
}

void nui_alert(const char* format, ...)
{
	char buf[256];
	va_list p_args;
	va_start(p_args, format);
	vsprintf(buf, format, p_args); // Format the string to the buffer
	nui_native_alert(buf); // Call the native API to display a basic message box or some kind of alert
	va_end(p_args);
}