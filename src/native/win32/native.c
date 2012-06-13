/**
 *	Native methods implementation. See nui/native.h for explanation of all methods.
 */

#include <windows.h>
#include "world.h"
#include "elements.h"
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
			nui_quit();
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
	WNDCLASSEX windowClass;
	// Sets the windowClass members
	windowClass.cbSize        = sizeof(WNDCLASSEX);
	windowClass.style         = 0;
	windowClass.lpfnWndProc   = nui_win32_wndproc;
	windowClass.cbClsExtra    = 0;
	windowClass.cbWndExtra    = 0;
	windowClass.hInstance     = hInstance;
	windowClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	windowClass.lpszMenuName  = NULL;
	windowClass.lpszClassName = nui_g_win32_class_name;
	windowClass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&windowClass))
	{
		// TODO: Should create a dialog with custom parameters
		nui_alert("Can't register the WIN32 class!");
		// TODO: Should quit the application!
	}

	// Sets the nui world structure
	nui_g_app.instance = hInstance;
	nui_g_app.nCmdShow = nCmdShow;
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
// -----------------------------------------------------------------
void nui_native_quit()
{
	PostQuitMessage(0);
}
// -----------------------------------------------------------------
void nui_native_create_window(	nui_window_t* window,
								const char* title,
								unsigned int width,
								unsigned int height,
								NUI_WINDOW_STYLE style)
{
	window->handle = CreateWindowEx(WS_EX_CLIENTEDGE,
							        nui_g_win32_class_name,
							        title,
							        WS_OVERLAPPEDWINDOW,
							        CW_USEDEFAULT, CW_USEDEFAULT, 
							        width, height,
							        NULL, 
							        NULL, 
							        nui_g_app.instance, 
							        NULL);

	if(window->handle == NULL)
	{
		nui_alert("Can't create the window!");
		return;
	}

	// Actually show the window
	ShowWindow(window->handle, nui_g_app.nCmdShow);
	// Ensure that window properties are up to date
	UpdateWindow(window->handle);
}
// -----------------------------------------------------------------
void nui_native_destroy_window(nui_window_t* window)
{
	DestroyWindow(window->handle);
}