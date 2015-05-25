#include "GamePlayState.h"
#include "../InputManager/InputManager.h"


CGamePlayState::CGamePlayState(void)
{
	SetGameStateType(GamePlayState);
	SetName("GamePlay State");
}


CGamePlayState::~CGamePlayState(void)
{
}

bool CGamePlayState::Input(CInputManager* _inputManager)
{

	return true;
}

void CGamePlayState::Update(void)
{


}

void CGamePlayState::Render(void)
{


}
