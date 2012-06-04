#include "nui.h"
#include "native.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *	--------------------------------------------------------
 *	=>	NUI EXTERNS DECLARATION
 *	--------------------------------------------------------
 */

nui_app_t nui_g_app;

/**
 *	--------------------------------------------------------
 *	=>	CORE IMPLEMENTATION
 *	--------------------------------------------------------
 */

void nui_init(NUI_INIT_ARGS_D)
{
	nui_native_init(NUI_INIT_ARGS_V);
}
// -----------------------------------------------------------------
int nui_run()
{
	// Launch the native main loop which process events
	nui_native_main_loop();

	// Cleanup some stuff ?? Does the program always reach this point?
	nui_alert("Reach the end of the program");

	return 0;
}
// -----------------------------------------------------------------
void nui_alert(const char* format, ...)
{
	char buf[256];
	va_list p_args;
	va_start(p_args, format);
	vsprintf(buf, format, p_args); // Format the string to the buffer
	nui_native_alert(buf); // Call the native API to display a basic message box or some kind of alert
	va_end(p_args);
}
// -----------------------------------------------------------------
void nui_quit()
{
	nui_native_quit();
}

/**
 *	--------------------------------------------------------
 *	=>	WINDOWS RELATED IMPLEMENTATION
 *	--------------------------------------------------------
 */

nui_window_t* nui_create_window(const char* title,
								unsigned int width,
								unsigned int height,
								NUI_WINDOW_STYLE style)
{
	// TODO: I should allocates the struct here to avoid having nui_alloc in different places
	return NULL;
}
// -----------------------------------------------------------------
void nui_destroy_window(nui_window_t* windowPtr)
{
	// TODO: And I should free the allocated window here, after the native stuff are done
}