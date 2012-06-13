/**
 *	Contains definition of the nui world structures globally
 */

#ifndef WORLD_H__
#define WORLD_H__

#include "elements.h"

/**
 *	\struct 	nui_app
 *	Contains members related to the nui world and will be accessible
 *	globally (contains instance of the application and so on)
 */
typedef struct nui_app
{
	/** 
	 *	You should at least defines those members:
	 *		- instance : pointer to the instance of this application
	 */
	 nui_window_t* 	window;	/*!< Main window of the application */
} nui_app_t, nui_<os>_app_t;

#endif