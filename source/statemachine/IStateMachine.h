#ifndef ISTATEMACHINE_H
#define ISTATEMACHINE_H

#include <queue>
#include "GamePlayState.h"

class IStateMachine
{

public:

	IStateMachine(void);
	virtual ~IStateMachine(void);

	bool Input(void);
	void Update(void);
	void Render(void);

	void InitStateMachine();

	//When a gamestate change is required, this function will be called
	//To tell the IStateMachine class to change states.
	void ChangeState(CGameState::GameStateType _nextState);

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
	CGamePlayState* gamePlayState;



	//Use a queue to track gamestates! This is a stack
	//based statemachine
	std::queue<CGameState*> stateStack;
};

#endif

