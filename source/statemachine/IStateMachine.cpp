#include "IStateMachine.h"
#include "GamePlayState.h"
#include "CreditsState.h"
#include "LoadLevelState.h"
#include "MainMenuState.h"
#include "OptionsState.h"
#include "PauseState.h"
#include "SplashScreen.h"



IStateMachine::IStateMachine(void)
{

}


IStateMachine::~IStateMachine(void)
{
	delete gamePlayState;
	delete creditsState;
	delete loadLevelState;
	delete mainMenuState;
	delete optionsState;
	delete pauseState;
	delete splashScreenState;
}

void IStateMachine::InitStateMachine()
{
	changeState			= false;
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

void IStateMachine::ChangeState(CGameState::GameStateType _nextState)
{
	nextStateType = _nextState;
	changeState = true;
}

void IStateMachine::HandleStateChanging()
{
	switch (nextStateType)
	{

	case CGameState::GameStateType::GamePlayState:
		ChangeToGamePlayState();
		break;

	case CGameState::GameStateType::MainMenuState:
		ChangeToMainMenuState();
		break;

	case CGameState::GameStateType::LoadLevelState:
		ChangeToLoadLevelState();
		break;

	case CGameState::GameStateType::CreditsState:
		ChangeToCreditsState();
		break;

	case CGameState::GameStateType::OptionsState:
		ChangeToCreditsState();
		break;

	case CGameState::GameStateType::PauseState:
		ChangeToPauseState();
		break;

	default:
		break;
	}

	changeState = false;
}

void IStateMachine::ChangeToGamePlayState()
{


}

void IStateMachine::ChangeToCreditsState()
{


}

void IStateMachine::ChangeToLoadLevelState()
{

}

void IStateMachine::ChangeToMainMenuState()
{


}

void IStateMachine::ChangeToOptionsState()
{


}

void IStateMachine::ChangeToPauseState()
{


}

