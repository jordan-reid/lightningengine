#ifndef CGAMESTATEFACTORY_H
#define CGAMESTATEFACTORY_H

#include "../../statemachine/GameState.h"
#include <unordered_map>

class CGamePlayState;
class CCreditsState;
class CLoadLevelState;
class CMainMenuState;
class COptionsState;
class CPauseState;
class CSplashScreen;

class CGameStateFactory
{

public:

	CGameStateFactory(void);
	~CGameStateFactory(void);

	void InitGameStates();

	CGameState* getGameState(CGameState::GameStateType gameStateType);


private:

	std::unordered_map<CGameState::GameStateType, CGameState*> gameStates;

	//All the states the StateMachine has to manage
	CGamePlayState*		gamePlayState;
	CCreditsState*		creditsState;
	CLoadLevelState*	loadLevelState;
	CMainMenuState*		mainMenuState;
	COptionsState*		optionsState;
	CPauseState*		pauseState;
	CSplashScreen*		splashScreenState;
};

#endif

