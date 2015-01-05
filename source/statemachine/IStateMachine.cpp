#include "IStateMachine.h"



IStateMachine::IStateMachine(void)
{
	changeState		= false;
	nextStateType	= CGameState::GameStateType::SplashScreenState;

	currentState	= nullptr;
	prevState		= nullptr;
}


IStateMachine::~IStateMachine(void)
{

}

void IStateMachine::InitStateMachine()
{
	gamePlayState = new CGamePlayState();
}

bool IStateMachine::Input(void)
{
	return true;
}

void IStateMachine::Update(void)
{

}

void IStateMachine::Render(void)
{

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
		break;
	case CGameState::GameStateType::MainMenuState:
		break;
	case CGameState::GameStateType::SplashScreenState:
		break;
	case CGameState::GameStateType::LoadLevelState:
		break;
	case CGameState::GameStateType::CreditsState:
		break;
	default:
		break;
	}
}
