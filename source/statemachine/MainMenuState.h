#ifndef CMAINMENUSTATE_H
#define CMAINMENUSTATE_H

#include "gamestate.h"

class CInputManager;

class CMainMenuState : public CGameState
{

public:

	CMainMenuState(void);
	~CMainMenuState(void);

	bool Input(CInputManager* _inputManager);
	void Update(void);
	void Render(void);
};

#endif

