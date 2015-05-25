///////////////////////////////////////////////////////////////////
//---------------------------------------------------------------//
//File Name: CreditsState.cpp									 //
//																 //
//Author: Jordan Reid											 //
//																 //
//Purpose: House the implementation for the credits state		 //																										
//---------------------------------------------------------------//
///////////////////////////////////////////////////////////////////

#include "CreditsState.h"
#include "../InputManager/InputManager.h"


CCreditsState::CCreditsState(void)
{
	SetGameStateType(CreditsState);
	SetName("Credits State");
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
