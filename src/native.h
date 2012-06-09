/**
 *	All native function prototypes lives here. Do not disturb.
 */

#ifndef NATIVE_H_
#define NATIVE_H_

#include "func_args.h"

/**
 *	--------------------------------------------------------
 *	=>	NATIVE CORE RELATED FUNCTIONS
 *	--------------------------------------------------------
 */

/**
 *	\brief		Init the native API
 */
void nui_native_init(NUI_INIT_ARGS_D);
/**
 *	\brief		Launch the native main loop
 */
void nui_native_main_loop();
/**
 *	\brief		Show an alert
 *	\param		msg		:	message to show
 */
void nui_native_alert(const char* msg);
/**
 *	\brief		Quit the application
 */
void nui_native_quit();

/**
 *	--------------------------------------------------------
 *	=>	NATIVE WINDOW RELATED FUNCTIONS
 *	--------------------------------------------------------
 */

/**
 *	\brief		Creates a new window using the native API
 *	\param		windowPtr	:	pointer to an allocated nui_window_t struct
 *	\param		title		:	title of the window
 *	\param		width		:	width of the window
 *	\param		height		:	height of the window
 *	\param		style 		:	style of the new window (see NUI_WINDOW_STYLE enum)
 *	\return		a pointer to the allocated window
 */
void nui_native_create_window(	nui_window_t* windowPtr,
								const char* title,
								unsigned int width,
								unsigned int height,
								NUI_WINDOW_STYLE style);
/**
 *	\brief		Destroy a previously allocated window
 *	\param		windowPtr	:	pointer to the window to destroy
 */
void nui_native_destroy_window(nui_window_t* windowPtr);

/**
 *	--------------------------------------------------------
 *	=>	NATIVE WIDGET RELATED FUNCTIONS
 *	--------------------------------------------------------
 */

#endif