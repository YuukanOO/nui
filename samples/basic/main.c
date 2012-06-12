/**
 *	Very basic sample used to demonstrate how to use this library
 */

#include <nui.h>

NUI_MAIN(NUI_MAIN_ARGS_D)
{
	// Declare our variables
	nui_window_t* mainWindow;

	// Init the NUI lib
	nui_init(NUI_INIT_ARGS_V);
	
	// Create the main window
	mainWindow = nui_create_window(	"My NUI window",
									500,
									300,
									NUI_WINDOW_STYLE_DEFAULT);

	nui_destroy_window(mainWindow);
	nui_alert("%p", mainWindow);

	// Start the application
	return nui_run();
}