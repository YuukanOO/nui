/**
 *	Defines WIN32 specific function prototypes
 */

#ifndef FUNC_PROTOTYPES_H_
#define FUNC_PROTOTYPES_H_

#include <windows.h>

/**
 *	--------------------------------------------------------
 *	=>	PROTOTYPES FOR INITIALIZATION STUFF
 *	--------------------------------------------------------
 */

/** Entry point of the program */
#define NUI_MAIN(ARGS)			int WINAPI WinMain(ARGS)

#endif