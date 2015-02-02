#ifndef CGAMEPLAYSTATE_H
#define CGAMEPLAYSTATE_H

#include "GameState.h"

class CInputManager;

class CGamePlayState : public CGameState
{

public:

	CGamePlayState(void);
	~CGamePlayState(void);

	bool Input(CInputManager* _inputManager);
	void Update(void);
	void Render(void);

private:

};

#endif

