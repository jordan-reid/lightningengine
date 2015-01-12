#include "IStateMachine.h"
#include "GamePlayState.h"
#include "CreditsState.h"
#include "LoadLevelState.h"
#include "MainMenuState.h"
#include "OptionsState.h"
#include "PauseState.h"
#include "SplashScreen.h"
#include "../renderer/Renderer.h"



IStateMachine::IStateMachine(void)
{

}


IStateMachine::~IStateMachine(void)
{
	ShutDown();
}

void IStateMachine::InitStateMachine()
{
	changeState			= false;
	popState			= false;
	nextStateType		= CGameState::GameStateType::MainMenuState;

	currentState		= splashScreenState;
	prevState			= nullptr;

	gamePlayState		= new CGamePlayState();
	creditsState		= new CCreditsState();
	loadLevelState		= new CLoadLevelState();
	mainMenuState		= new CMainMenuState();
	optionsState		= new COptionsState();
	pauseState			= new CPauseState();
	splashScreenState	= new CSplashScreen();

	stateStack.push(splashScreenState);

	renderer = new CRenderer();
}

bool IStateMachine::Input(void)
{
	if(stateStack.size() != 0)
		return stateStack.top()->Input();

	return true;
}

void IStateMachine::Update(void)
{
	if(stateStack.size() != 0)
		stateStack.top()->Update();

	if(changeState)
		HandleStateChanging();
}

void IStateMachine::Render(void)
{
	if(stateStack.size() != 0)
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
	if(popState)
	{
		prevState = stateStack.top();
		stateStack.pop();

		currentState = stateStack.top();
	}

	else
	{
		prevState = stateStack.top();

		switch (nextStateType)
		{

		case CGameState::GameStateType::GamePlayState:
			{
				stateStack.push(gamePlayState);
				currentState = gamePlayState;
			}
			break;

		case CGameState::GameStateType::MainMenuState:
			{
				stateStack.push(mainMenuState);
				currentState = mainMenuState;
			}
			break;

		case CGameState::GameStateType::LoadLevelState:
			{
				stateStack.push(loadLevelState);
				currentState = loadLevelState;
			}
			break;

		case CGameState::GameStateType::CreditsState:
			{
				stateStack.push(creditsState);
				currentState = creditsState;
			}
			break;

		case CGameState::GameStateType::OptionsState:
			{
				stateStack.push(optionsState);
				currentState = optionsState;
			}
			break;

		case CGameState::GameStateType::PauseState:
			stateStack.push(pauseState);
			currentState = pauseState;
			break;

		default:
			//This would be a great place to do a debug assert
			//Trying to switch to a state that has not been set up yet.
			break;
		};
	}

	changeState = false;
	popState = false;
}

void IStateMachine::ShutDown()
{
	delete gamePlayState;
	delete creditsState;
	delete loadLevelState;
	delete mainMenuState;
	delete optionsState;
	delete pauseState;
	delete splashScreenState;


	delete renderer;
	renderer = nullptr;
}


