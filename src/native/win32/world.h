/**
 *	Contains definition of the nui world structures globally
 */

#ifndef WORLD_H__
#define WORLD_H__

#include <windows.h>
#include "elements.h"

/**
 *	\struct 	nui_app
 *	Contains members related to the nui world and will be accessible
 *	globally (contains instance of the application and so on)
 */
typedef struct nui_app
{
	HINSTANCE 		instance;	/*!< Pointer to the win32 app instance */
	int 			nCmdShow;	/*!< Specific for win32 */
	nui_window_t* 	window;		/*!< Main window of the application */
} nui_app_t, nui_win32_app_t;

#endif