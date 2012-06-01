/**
 *	Defines platform specific arguments list.
 *	The basic syntax of those macros are as follow:
 *
 *		<FUNCTION_NAME>_ARGS_<D | V>
 *
 *	where:
 *		- FUNCTION_NAME is the name of the function
 *		- the last letter stands for 	D -> Declaration
 *										V -> Value
 */

#ifndef FUNC_ARGS_H_
#define FUNC_ARGS_H_

/**
 *	--------------------------------------------------------
 *	=>	ARGUMENTS FOR INITIALIZATION STUFF
 *	--------------------------------------------------------
 */

/** Program's main arguments declaration */
#define NUI_MAIN_ARGS_D			// On most platform, this will be: int argc, char* argv[]
/** Declaration of the nui_init function */
#define NUI_INIT_ARGS_D			// Your value
/** Values of the nui_init function. Those values comes from the NUI_MAIN function */
#define NUI_INIT_ARGS_V			// Your value

#endif