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

/** Program's main arguments declaration */
#define NUI_MAIN_ARGS_D // On most platform, this will be: int argc, char* argv[]

#endif