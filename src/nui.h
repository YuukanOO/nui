/**
 *	This file is the heart of the NUI lib for client applications
 *	using this wonderful little GUI library.
 */

#ifndef NUI_H_
#define NUI_H_

#include "func_args.h"
#include "func_prototypes.h"

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
 *	\brief		Start the main loop
 */
int nui_run();
/**
 *	\brief		Alert function mostly for debugging purposes
 *	\param		format	:	string format
 */
void nui_alert(const char* format, ...);

/**
 *	--------------------------------------------------------
 *	=>	WINDOWS RELATED METHODS
 *	--------------------------------------------------------
 */



/**
 *	--------------------------------------------------------
 *	=>	WIDGETS RELATED METHODS
 *	--------------------------------------------------------
 */

#endif