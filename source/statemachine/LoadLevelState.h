#ifndef CLOADLEVELSTATE_H
#define CLOADLEVELSTATE_H

#include "gamestate.h"

class CInputManager;

class CLoadLevelState : public CGameState
{

public:

	CLoadLevelState(void);
	~CLoadLevelState(void);

	bool Input(CInputManager* _inputManager);
	void Update(void);
	void Render(void);
};

#endif

