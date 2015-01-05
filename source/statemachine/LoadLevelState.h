#pragma once
#include "gamestate.h"
class CLoadLevelState : public CGameState
{

public:

	CLoadLevelState(void);
	~CLoadLevelState(void);

	bool Input(void);
	void Update(void);
	void Render(void);
};

