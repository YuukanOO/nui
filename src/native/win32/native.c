#include <windows.h>

void nui_native_alert(const char* msg)
{
	MessageBox(NULL, msg, "NUI Alert", MB_OK);
}