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

class IStateMachine
{

public:

	IStateMachine(void);
	~IStateMachine(void);

	bool Input(void);
	void Update(void);
	void Render(void);

	void InitStateMachine();

	//When a gamestate change is required, this function will be called
	//To tell the IStateMachine class to change states on its next update.
	void ChangeState(CGameState::GameStateType _nextState);

	void ChangeToGamePlayState();
	void ChangeToCreditsState();
	void ChangeToLoadLevelState();
	void ChangeToMainMenuState();
	void ChangeToOptionsState();
	void ChangeToPauseState();



	//Accessors
	CGameState* GetCurrentState()		{return currentState;};
	CGameState* GetPrevState()			{return prevState;};

	CGameState::GameStateType  GetNextStateType()		{return nextStateType;};

	//NO MUTATORS!!!!!
	//We don't want anything but the IStateMachine class
	//Modifying its fields

private:

	//This function is responsible for the actual changing of gamestates
	void HandleStateChanging();

	CGameState* currentState, *prevState;
	CGameState::GameStateType nextStateType;
	bool changeState;

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
};

#endif

