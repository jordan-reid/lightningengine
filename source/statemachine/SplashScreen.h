#pragma once
#include "gamestate.h"
class CSplashScreen : public CGameState
{

public:

	CSplashScreen(void);
	~CSplashScreen(void);

	bool Input(void);
	void Update(void);
	void Render(void);
};
