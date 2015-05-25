#include "LoadLevelState.h"
#include "../InputManager/InputManager.h"


CLoadLevelState::CLoadLevelState(void)
{
	SetGameStateType(LoadLevelState);
	SetName("LoadLevel State");
}


CLoadLevelState::~CLoadLevelState(void)
{
}

bool CLoadLevelState::Input(CInputManager* _inputManager)
{
	return true;
}

void CLoadLevelState::Update(void)
{

}

void CLoadLevelState::Render(void)
{


}
