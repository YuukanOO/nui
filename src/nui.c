#include "nui.h"
#include <stdio.h>
#include <stdarg.h>

void nui_init(NUI_INIT_ARGS_D)
{
	nui_native_init(NUI_INIT_ARGS_V);
}

void nui_run()
{
	// Launch the native main loop which processed events
	nui_native_main_loop();
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