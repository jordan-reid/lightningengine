#ifndef COPTIONSSTATE_H
#define COPTIONSSTATE_H

#include "gamestate.h"

class COptionsState : public CGameState
{

public:

	COptionsState(void);
	~COptionsState(void);

	virtual bool Input(CInputManager* _inputManager);
	virtual void Update(void);
	virtual void Render(void);

};

#endif

