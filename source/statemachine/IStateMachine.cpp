#include "IStateMachine.h"
#include "GamePlayState.h"
#include "CreditsState.h"
#include "LoadLevelState.h"
#include "MainMenuState.h"
#include "OptionsState.h"
#include "PauseState.h"
#include "SplashScreen.h"
#include "../renderer/Renderer.h"
#include "../InputManager/InputManager.h"
#include "../factories/gameStateFactory/GameStateFactory.h"



IStateMachine::IStateMachine(void)
{

}


IStateMachine::~IStateMachine(void)
{
	ShutDown();
}

void IStateMachine::InitStateMachine()
{
	changeState = false;
	popState = false;
	nextStateType = CGameState::GameStateType::MainMenuState;

	gameStateFactory = new CGameStateFactory();
	gameStateFactory->InitGameStates();

	stateStack.push(gameStateFactory->getGameState(CGameState::SplashScreenState));

	prevState = nullptr;

	renderer = new CRenderer();
}

bool IStateMachine::Input(CInputManager* _InputManager)
{
	if (stateStack.size() != 0)
		return stateStack.top()->Input(_InputManager);

	return true;
}

void IStateMachine::Update(void)
{

	if (GetAsyncKeyState('A'))
		ChangeState(CGameState::GamePlayState, false);

	if (stateStack.size() != 0)
		stateStack.top()->Update();

	if (changeState)
		HandleStateChanging();
}

void IStateMachine::Render(void)
{
	if (stateStack.size() != 0)
		stateStack.top()->Render();
}

void IStateMachine::ChangeState(CGameState::GameStateType _nextState, bool _popState)
{
	nextStateType = _nextState;
	changeState = true;
	popState = _popState;
}


void IStateMachine::HandleStateChanging()
{
	if (popState)
	{
		prevState = stateStack.top();
		stateStack.pop();

		currentState = stateStack.top();
	}

	else
	{
		prevState = stateStack.top();
		stateStack.push(gameStateFactory->getGameState(nextStateType));
	}

	changeState = false;
	popState = false;
}

void IStateMachine::ShutDown()
{
	delete gameStateFactory;
	gameStateFactory = nullptr;

	delete renderer;
	renderer = nullptr;
}


