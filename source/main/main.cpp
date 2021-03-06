#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
//#include <vld.h>

#include "../gameapp/GameApp.h"
#include "../InputManager/InputManager.h"

GameApp gameapp;

//Get a handle to the Console Window
void getConsoleHandle();

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	srand(unsigned int(time(0)));

	getConsoleHandle();

	gameapp.Init(hInstance,(WNDPROC)WndProc);


	// Main message loop:
	MSG msg; 
	ZeroMemory(&msg, sizeof( msg ));

	while(msg.message != WM_QUIT && gameapp.Run())
	{
		if(PeekMessage(&msg, NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	gameapp.ShutDown();

	return (int) msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (message)
	{

	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);

			// Here your application is laid out.
			// For this introduction, we just print out "Hello, World!"
			// in the top left corner.
			TextOut(hdc,
				5, 5,
				greeting, _tcslen(greeting));
			// End application-specific layout section.

			EndPaint(hWnd, &ps);
		}
		break;

	case WM_KEYDOWN:
		{
			gameapp.GetInputManager()->OnKeyDown(wParam);
		}
		break;

	case WM_KEYUP:
		{
			gameapp.GetInputManager()->OnKeyUp(wParam);
		}
		break;

	case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;

	default:
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	}

	return 0;
}

void getConsoleHandle()
{
	AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;
}