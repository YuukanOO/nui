#include <windows.h>

void nui_native_init(HINSTANCE hInstance, int nCmdShow)
{
	
}

void nui_native_main_loop()
{
	
}

void nui_native_alert(const char* msg)
{
	MessageBox(NULL, msg, "NUI Alert", MB_OK | MB_ICONINFORMATION);
}