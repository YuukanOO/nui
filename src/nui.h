#ifndef NUI_H_
#define NUI_H_

#include "native.h"
#include "func_args.h"
#include "func_prototypes.h"

void nui_init(NUI_INIT_ARGS_D);
void nui_alert(const char* format, ...);
#endif