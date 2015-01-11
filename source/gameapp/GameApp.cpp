#include "GameApp.h"
#include "../statemachine/IStateMachine.h"

//TESTING STATEMACHINE!!
#include "../statemachine/GameState.h"



GameApp::GameApp(HINSTANCE _hinst, WNDPROC _wndProc)
{
	// The main window class name.
	static TCHAR szWindowClass[] = _T("Lightning Engine");

	// The string that appears in the application's title bar.
	static TCHAR szTitle[] = _T("Lightning Engine");

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = _wndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = _hinst;
	wcex.hIcon          = LoadIcon(_hinst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = NULL;
	wcex.lpszClassName  = szWindowClass;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Lightning Engine"),
			NULL);

		//return 1;
	}

	//hInst = _hinst; // Store instance handle in our global variable

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 1920, 1440: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	window = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1920, 1440,
		NULL,
		NULL,
		_hinst,
		NULL
		);

	if (!window)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Lightning Engine"),
			NULL);

		//return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(window, SW_SHOW);

	UpdateWindow(window);

	runApp = true;
	StateMachine = new IStateMachine();
	StateMachine->InitStateMachine();
}


GameApp::~GameApp(void)
{
}

bool GameApp::Run(void)
{
	runApp = StateMachine->Input();
	StateMachine->Update();
	StateMachine->Render();

	return runApp;
}


bool GameApp::ShutDown(void)
{
	return true;
}


