#ifndef CCREDITSSTATE_H
#define CCREDITSSTATE_H


#include "gamestate.h"

class CInputManager;

class CCreditsState : public CGameState
{

public:

	CCreditsState(void);
	~CCreditsState(void);

	bool Input(CInputManager* _inputManager);
	void Update(void);
	void Render(void);
};

#endif

