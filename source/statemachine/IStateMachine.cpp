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

#include <Windows.h>

#include <iostream>



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
	currentState = stateStack.top();

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

	if (GetAsyncKeyState('A') & 0x1)
	{
		PushState(CGameState::MainMenuState);
	}

	if (GetAsyncKeyState('S') & 0x1)
	{
		PushState(CGameState::GamePlayState);
	}

	if (GetAsyncKeyState('D') & 0x1)
	{
		PushState(CGameState::PauseState);
	}

	if (GetAsyncKeyState('F') & 0x1)
	{
		PushState(CGameState::OptionsState);
	}

	if (GetAsyncKeyState('G') & 0x1)
	{
		PopState();
	}

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

void IStateMachine::PushState(CGameState::GameStateType _nextState)
{
	if(_nextState == currentState->GetGameStateType())
		return;

	nextStateType = _nextState;
	changeState = true;
	popState = false;
}

void IStateMachine::PopState()
{
	changeState = true;
	popState = true;
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
		currentState = stateStack.top();
	}

	for(unsigned int i = 0; i < stateStack.size(); i++)
	{
		std::cout << stateStack._Get_container()[i]->getName();
		std::cout << "\n";
	}

	std::cout << "\n\n";

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


