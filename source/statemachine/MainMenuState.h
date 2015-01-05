#pragma once
#include "gamestate.h"
class CMainMenuState : public CGameState
{

public:

	CMainMenuState(void);
	~CMainMenuState(void);

	bool Input(void);
	void Update(void);
	void Render(void);
};

