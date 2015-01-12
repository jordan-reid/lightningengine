#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <Windows.h>
#include <tchar.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1440

class IStateMachine;

class GameApp
{

public:

	GameApp(HINSTANCE _hinst, WNDPROC _wndProc);
	~GameApp(void);

	//Gets
	bool GetRunApp(void) {return runApp;};
	IStateMachine* GetStateMAchine() {return StateMachine;};
	const HWND GetGameWindow(void) {return window;};


	//Sets
	void SetRunApp(bool _runApp) {runApp = _runApp;};
	void SetStateMAchine(IStateMachine* _stateMachine) { StateMachine = _stateMachine;};


	bool Run(void);
	bool ShutDown(void);

private:

	HINSTANCE Hinstance;
	WNDPROC   WndProc;
	HWND      window;

	IStateMachine* StateMachine;

	bool runApp;
};

#endif

