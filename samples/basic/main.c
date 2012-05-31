#include <nui.h>

NUI_MAIN(NUI_MAIN_ARGS_D)
{
	nui_init(NUI_INIT_ARGS_V);
	nui_alert("This is a five: %i or maybe not %i", 5, 8);
	return 0;
}