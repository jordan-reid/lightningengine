#ifndef CGAMESTATE_H
#define CGAMESTATE_H

class CInputManager;

class CGameState
{

public:

	CGameState(void);
	virtual ~CGameState(void);

	virtual bool Input(CInputManager* _inputManager);
	virtual void Update(void);
	virtual void Render(void);

	//An Enumeration of all the possible states the game can be in.
	//This can be added to if necessary
	enum GameStateType{GamePlayState, SplashScreenState, MainMenuState, LoadLevelState, CreditsState, OptionsState, PauseState};

	//Accessors
	GameStateType GetGameStateType(void) {return gameStateType;};

	//Mutators
	void SetGameStateType(GameStateType _type) {gameStateType = _type;};

	

private:

	GameStateType gameStateType;
};

#endif

