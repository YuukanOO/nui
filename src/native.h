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
 *	=>	NATIVE WIDGET RELATED FUNCTIONS
 *	--------------------------------------------------------
 */

#endif