/**
 *	Very basic sample used to demonstrate how to use this library
 */

#include <nui.h>

NUI_MAIN(NUI_MAIN_ARGS_D)
{
	// Init the NUI lib
	nui_init(NUI_INIT_ARGS_V);

	nui_alert("This is a five: %i or maybe not %i", 5, 8);

	// Start the application
	return nui_run();
}