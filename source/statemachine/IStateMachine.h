#ifndef ISTATEMACHINE_H
#define ISTATEMACHINE_H

#include <stack>
#include "GameState.h"

//Forward declarations

class CGamePlayState;
class CCreditsState;
class CLoadLevelState;
class CMainMenuState;
class COptionsState;
class CPauseState;
class CSplashScreen;
class CRenderer;
class CInputManager;

class IStateMachine
{

public:

	IStateMachine(void);
	~IStateMachine(void);

	bool Input(CInputManager* _InputManager);
	void Update(void);
	void Render(void);

	void InitStateMachine();
	void ShutDown();

	//When a gamestate change is required, this function will be called
	//To tell the IStateMachine class to change states on its next update.
	void ChangeState(CGameState::GameStateType _nextState, bool _popState = false);

	//Accessors
	CGameState* GetCurrentState()						{return currentState;};
	CGameState* GetPrevState()							{return prevState;};

	CGameState::GameStateType  GetNextStateType()		{return nextStateType;};
	CRenderer* GetRenderer(void)						{return renderer;};

	//NO MUTATORS!!!!!
	//We don't want anything but the IStateMachine class
	//Modifying its fields

private:

	//This function is responsible for the actual changing of gamestates
	void HandleStateChanging();

	CGameState* currentState, *prevState;
	CGameState::GameStateType nextStateType;
	bool changeState;
	bool popState;

	//All the states the StateMachine has to manage
	CGamePlayState*		gamePlayState;
	CCreditsState*		creditsState;
	CLoadLevelState*	loadLevelState;
	CMainMenuState*		mainMenuState;
	COptionsState*		optionsState;
	CPauseState*		pauseState;
	CSplashScreen*		splashScreenState;


	//Use a queue to track gamestates! This is a stack
	//based statemachine
	std::stack<CGameState*> stateStack;

	CRenderer*		renderer;
	CInputManager*  InputManager;
};

#endif

