/**
 *	This file contains all GUI elements definitions
 */

#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#include <windows.h>

/** 
 *	\struct 	nui_window
 *	\brief		Represents a window, obviously
 */
typedef struct nui_window
{
	HWND 	handle;	/*< Handle to the window */
} nui_window_t, nui_win32_window_t;

#endif