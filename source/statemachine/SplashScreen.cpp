#include "SplashScreen.h"
#include "../InputManager/InputManager.h"


CSplashScreen::CSplashScreen(void)
{
	SetGameStateType(SplashScreenState);
	SetName("SplashScreen State");
}


CSplashScreen::~CSplashScreen(void)
{
}

bool CSplashScreen::Input(CInputManager* _inputManager)
{
	return true;
}

void CSplashScreen::Update(void)
{

}

void CSplashScreen::Render(void)
{

}
