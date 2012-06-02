/**
 *	Native methods implementation. See nui/native.h for explanation of all methods.
 */

#include <windows.h>
#include "../../memory.h"
#include "../../nui.h"

/**
 *	--------------------------------------------------------
 *	=>	WIN32 CONSTANTS
 *	--------------------------------------------------------
 */

const char nui_g_win32_class_name[] = "nui_window_class";

/**
 *	--------------------------------------------------------
 *	=>	WIN32 NATIVE FUNCTIONS
 *	--------------------------------------------------------
 */

LRESULT CALLBACK nui_win32_wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

/**
 *	--------------------------------------------------------
 *	=>	FUNCTIONS
 *	--------------------------------------------------------
 */

void nui_native_init(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX window_class;
	// Sets the window_class members
	window_class.cbSize        = sizeof(WNDCLASSEX);
	window_class.style         = 0;
	window_class.lpfnWndProc   = nui_win32_wndproc;
	window_class.cbClsExtra    = 0;
	window_class.cbWndExtra    = 0;
	window_class.hInstance     = hInstance;
	window_class.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	window_class.hCursor       = LoadCursor(NULL, IDC_ARROW);
	window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	window_class.lpszMenuName  = NULL;
	window_class.lpszClassName = nui_g_win32_class_name;
	window_class.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&window_class))
	{
		// TODO: Should create a dialog with custom parameters
		nui_alert("Can't register the WIN32 class!");
		// TODO: Should quit the application!
	}
}
// -----------------------------------------------------------------
void nui_native_main_loop()
{
	MSG msg;
	// Start the message loop
	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
// -----------------------------------------------------------------
void nui_native_alert(const char* msg)
{
	MessageBox(NULL, msg, "NUI Alert", MB_OK | MB_ICONINFORMATION);
}