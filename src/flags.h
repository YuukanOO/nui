/**
 *	Contains flags definition for element styles.
 *	Flags are almost grouped as enums because I thought it was clearer.
 */

#ifndef FLAGS_H_
#define FLAGS_H_

/**
 *	--------------------------------------------------------
 *	=>	WINDOWS RELATED FLAGS / ENUMS
 *	--------------------------------------------------------
 */

/**
 *	\enum 		NUI_WINDOW_STYLE
 *	\brief		Defines window style
 */
typedef enum
{
	NUI_WINDOW_STYLE_NORESIZE   = 1 << 0,	/*!< the window will not be resizable */
	NUI_WINDOW_STYLE_NOMAXIMIZE = 1 << 1,	/*!< the window will not have a maximize button */
	NUI_WINDOW_STYLE_NOMINIMIZE = 1 << 2,	/*!< the window will not have a minimize button */
	NUI_WINDOW_STYLE_DEFAULT    = 0			/*!< default style */
} NUI_WINDOW_STYLE;

#endif