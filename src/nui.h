/**
 *	This file is the heart of the NUI lib for client applications
 *	using this wonderful little GUI library.
 */

#ifndef NUI_H_
#define NUI_H_

#include "constants.h"
#include "elements.h"
#include "flags.h"
#include "world.h"
#include "func_args.h"
#include "func_prototypes.h"

/**
 *	--------------------------------------------------------
 *	=>	NUI EXTERNS
 *	--------------------------------------------------------
 */
extern nui_app_t nui_g_app;

/**
 *	--------------------------------------------------------
 *	=>	NUI CORE RELATED FUNCTIONS
 *	--------------------------------------------------------
 */

/**
 *	\brief		Init the NUI lib and native OS API
 */
void nui_init(NUI_INIT_ARGS_D);
/**
 *	\brief		Clean up all stuff allocated by the NUI library
 */
void nui_cleanup();
/**
 *	\brief		Start the main loop
 */
int nui_run();
/**
 *	\brief		Alert function mostly for debugging purposes
 *	\param		format	:	string format
 */
void nui_alert(const char* format, ...);
/**
 *	\brief		Quit the main application
 */
void nui_quit();

/**
 *	--------------------------------------------------------
 *	=>	WINDOWS RELATED METHODS
 *	--------------------------------------------------------
 */

/**
 *	\brief		Creates a new window
 *	\param		title		:	title of the window
 *	\param		width		:	width of the window
 *	\param		height		:	height of the window
 *	\param		style 		:	style of the new window (see NUI_WINDOW_STYLE_* flags)
 *	\return		a pointer to the allocated window
 */
nui_window_t*	nui_create_window(	const char* title,
									unsigned int width,
									unsigned int height,
									NUI_WINDOW_STYLE style);
/**
 *	\brief		Manually destroy a previously allocated window
 *	\param		window_ptr	:	pointer to the window to destroy
 */
void			nui_destroy_window(nui_window_t* window_ptr);

/**
 *	--------------------------------------------------------
 *	=>	WIDGETS RELATED METHODS
 *	--------------------------------------------------------
 */

#endif