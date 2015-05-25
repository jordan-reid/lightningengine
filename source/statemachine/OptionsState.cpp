#include "OptionsState.h"
#include "../InputManager/InputManager.h"


COptionsState::COptionsState(void)
{
	SetGameStateType(OptionsState);
	SetName("OptionsState State");
}


COptionsState::~COptionsState(void)
{
}

bool COptionsState::Input(CInputManager* _inputManager)
{

	return true;
}

void COptionsState::Update(void)
{

}

void COptionsState::Render(void)
{

}
