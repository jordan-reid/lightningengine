#ifndef CSPLASHSCREEN_H
#define CSPLASHSCREEN_H

#include "gamestate.h"

class CInputManager;

class CSplashScreen : public CGameState
{

public:

	CSplashScreen(void);
	~CSplashScreen(void);

	bool Input(CInputManager* _inputManager);
	void Update(void);
	void Render(void);
};

#endif

