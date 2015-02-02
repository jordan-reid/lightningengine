#include "MainMenuState.h"
#include "../InputManager/InputManager.h"


CMainMenuState::CMainMenuState(void)
{
	SetGameStateType(MainMenuState);
}


CMainMenuState::~CMainMenuState(void)
{
}

bool CMainMenuState::Input(CInputManager* _inputManager)
{

	return true;
}

void CMainMenuState::Update(void)
{

}

void CMainMenuState::Render(void)
{


}
