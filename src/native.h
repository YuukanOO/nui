#ifndef NATIVE_H_
#define NATIVE_H_

#include "func_args.h"

void nui_native_init(NUI_INIT_ARGS_D);
void nui_native_main_loop();
void nui_native_alert(const char* msg);

#endif