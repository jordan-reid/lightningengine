#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <Windows.h>
#include <tchar.h>

class IStateMachine;

class GameApp
{

public:

	GameApp(HINSTANCE _hinst, WNDPROC _wndProc);
	~GameApp(void);

	//Gets
	bool GetRunApp(void) {return runApp;};
	IStateMachine* GetStateMAchine() {return StateMachine;};


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

