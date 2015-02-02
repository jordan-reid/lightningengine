#ifndef CPAUSESTATE_H
#define CPAUSESTATE_H

#include "gamestate.h"

class CPauseState : public CGameState
{

public:

	CPauseState(void);
	~CPauseState(void);

	bool Input(CInputManager* _inputManager);
	void Update(void);
	void Render(void);

};

#endif

