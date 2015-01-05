#ifndef CGAMESTATE_H
#define CGAMESTATE_H

class CGameState
{

public:

	CGameState(void);
	virtual ~CGameState(void);

	virtual bool Input(void);
	virtual void Update(void);
	virtual void Render(void);

	//An Enumeration of all the possible states the game can be in.
	//This can be added to if necessary
	enum GameStateType{GamePlayState, SplashScreenState, MainMenuState, LoadLevelState, CreditsState};

private:

	GameStateType gameStateType;
};

#endif

