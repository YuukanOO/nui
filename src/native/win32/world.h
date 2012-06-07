/**
 *	Contains definition of the nui world structures globally
 */

#ifndef WORLD_H__
#define WORLD_H__

#include <windows.h>

/**
 *	\struct 	nui_app
 *	Contains members related to the nui world and will be accessible
 *	globally (contains instance of the application and so on)
 */
typedef struct nui_app
{
	HINSTANCE instance;	/*!< pointer to the win32 app instance */
} nui_app_t, nui_win32_app_t;

#endif