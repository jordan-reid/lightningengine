#pragma once
#include "gamestate.h"
class CCreditsState : public CGameState
{

public:

	CCreditsState(void);
	~CCreditsState(void);

	bool Input(void);
	void Update(void);
	void Render(void);
};

