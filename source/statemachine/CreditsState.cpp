#include "CreditsState.h"
#include "../InputManager/InputManager.h"


CCreditsState::CCreditsState(void)
{
	SetGameStateType(CreditsState);
}


CCreditsState::~CCreditsState(void)
{
}


bool CCreditsState::Input(CInputManager* _inputManager)
{
	return true;
}

void CCreditsState::Update(void)
{


}

void CCreditsState::Render(void)
{


}
