#ifndef CGAMEPLAYSTATE_H
#define CGAMEPLAYSTATE_H

#include "GameState.h"


class CGamePlayState : public CGameState
{

public:

	CGamePlayState(void);
	~CGamePlayState(void);

	bool Input(void);
	void Update(void);
	void Render(void);

private:

};

#endif

