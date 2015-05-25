#include "PauseState.h"
#include "../InputManager/InputManager.h"


CPauseState::CPauseState(void)
{
	SetGameStateType(PauseState);
	SetName("Pause State");
}


CPauseState::~CPauseState(void)
{
}

bool CPauseState::Input(CInputManager* _inputManager)
{

	return true;
}

void CPauseState::Update(void)
{

}

void CPauseState::Render(void)
{


}


