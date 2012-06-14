#include "memory.h"
#include "nui.h"
#include "native.h"
#include "utils/log.h"
#include <stdarg.h>
#include <stdio.h>

/**
 *	--------------------------------------------------------
 *	=>	NUI EXTERNS DECLARATION
 *	--------------------------------------------------------
 */

LOG_DECLARE()
nui_app_t nui_g_app;

/**
 *	--------------------------------------------------------
 *	=>	CORE IMPLEMENTATION
 *	--------------------------------------------------------
 */

void nui_init(NUI_INIT_ARGS_D)
{
	LOG_INIT("log.txt")

	// Init the global app structure
	nui_g_app.window = NULL;

	nui_native_init(NUI_INIT_ARGS_V);

	LOG_WITH_TIME("[NUI_CORE] Initialized!\n")
}
// -----------------------------------------------------------------
void nui_cleanup()
{
	if(nui_g_app.window != NULL)
	{
		nui_destroy_window(nui_g_app.window);
	}

	LOG_WITH_TIME("[NUI_CORE] Cleaned!\n")
	LOG_CLEAN()
}
// -----------------------------------------------------------------
int nui_run()
{
	// If we do not have create a window yet, just exit
	if(nui_g_app.window != NULL)
	{
		LOG_WITH_TIME("[NUI_CORE] Launching main loop...\n")
		// Launch the native main loop which process events
		nui_native_main_loop();
	}

	// Cleanup some stuff ?? Does the program always reach this point?
	nui_cleanup();

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
	LOG_WITH_TIME("[NUI_CORE] Exit requested.\n")
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
	// Allocates the window
	nui_window_t* window = nui_alloc(sizeof(nui_window_t));

	// If this is the first window, this is the app window
	if(nui_g_app.window == NULL)
	{
		nui_g_app.window = window;
	}

	nui_native_create_window(window, title, width, height, style);

	LOG_WITH_TIME("[NUI_WIDGET] Window created:\n \
\t\t\taddr: %p\n \
\t\t\ttitle: \"%s\"\n", window, title)

	return window;
}
// -----------------------------------------------------------------
void nui_destroy_window(nui_window_t* window)
{
	nui_native_destroy_window(window);
	nui_free(window);

	if(window == nui_g_app.window)
	{
		nui_g_app.window = NULL;
		// Maybe I should call nui_quit?
	}

	LOG_WITH_TIME("[NUI_WIDGET] Window destroyed: %p\n", window)

	window = NULL; // Doesn't work??!!
}