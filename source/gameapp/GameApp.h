#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <Windows.h>
#include <tchar.h>

#define WINDOW_WIDTH  1024    //1920
#define WINDOW_HEIGHT 1024    //1440

class IStateMachine;
class CInputManager;

class GameApp
{

public:

	GameApp(void) {};
	~GameApp(void) {};

	bool Init(HINSTANCE _hinst, WNDPROC _wndProc);

	//Gets
	 bool GetRunApp					(void)	{return runApp;};
	 HWND GetGameWindow				(void)	{return window;};
	 IStateMachine* GetStateMAchine	(void)	{return StateMachine;};
	 CInputManager* GetInputManager	(void)	{return InputManager;};


	//Sets
	void SetRunApp(bool _runApp) {runApp = _runApp;};


	bool Run(void);
	bool ShutDown(void);

private:

	HINSTANCE Hinstance;
	WNDPROC   WndProc;
	HWND      window;

	IStateMachine* StateMachine;
	CInputManager* InputManager;

	bool runApp;
};

#endif

