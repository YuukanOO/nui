#ifndef FUNC_ARGS_H_
#define FUNC_ARGS_H_

#include <windows.h>

#define NUI_MAIN_ARGS_D HINSTANCE hInstance, \
						HINSTANCE hPrevInstance, \
						LPSTR lpCmdLine, \
						int nCmdShow
#define NUI_INIT_ARGS_D HINSTANCE hInstance, \
						int nCmdShow
#define NUI_INIT_ARGS_V hInstance, nCmdShow

#endif