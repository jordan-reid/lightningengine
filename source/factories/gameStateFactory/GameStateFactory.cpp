#include "GameStateFactory.h"

#include "../../statemachine/CreditsState.h"
#include "../../statemachine/GamePlayState.h"
#include "../../statemachine/LoadLevelState.h"
#include "../../statemachine/MainMenuState.h"
#include "../../statemachine/OptionsState.h"
#include "../../statemachine/PauseState.h"
#include "../../statemachine/SplashScreen.h"

///////////////////////////////////////////////////////////////////
//---------------------------------------------------------------//
//File Name: GameStateFactory.cpp								 //
//																 //
//Author: Jordan Reid											 //
//																 //
//Purpose: House the implementation for creating gameStates		 //																										
//---------------------------------------------------------------//
///////////////////////////////////////////////////////////////////
CGameStateFactory::CGameStateFactory(void)
{
	gamePlayState = nullptr;
	creditsState = nullptr;
	loadLevelState = nullptr;
	mainMenuState = nullptr;
	optionsState = nullptr;
	pauseState = nullptr;
	splashScreenState = nullptr;
}


CGameStateFactory::~CGameStateFactory(void)
{
	for (auto iter = gameStates.begin(); iter != gameStates.end(); iter++)
	{
		delete iter->second;
		iter->second = nullptr;
	}	
}

///////////////////////////////////////////////////////////////////
//---------------------------------------------------------------//
//Function Name: InitGameStates								     //
//																 //
//Purpose: Create all game states and store them in a map for the// 
//         StateMachine to manage								 //
//																 //
//Return: void													 //
//																 //
//Parameters: None												 //
//																 //										
//---------------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void CGameStateFactory::InitGameStates()
{
	gamePlayState = new CGamePlayState();
	creditsState = new CCreditsState();
	loadLevelState = new CLoadLevelState();
	mainMenuState = new CMainMenuState();
	optionsState = new COptionsState();
	pauseState = new CPauseState();
	splashScreenState = new CSplashScreen();

	gameStates[CGameState::GameStateType::GamePlayState] = gamePlayState;
	gameStates[CGameState::GameStateType::CreditsState] = creditsState;
	gameStates[CGameState::GameStateType::LoadLevelState] = loadLevelState;
	gameStates[CGameState::GameStateType::MainMenuState] = mainMenuState;
	gameStates[CGameState::GameStateType::OptionsState] = optionsState;
	gameStates[CGameState::GameStateType::PauseState] = pauseState;
	gameStates[CGameState::GameStateType::SplashScreenState] = splashScreenState;
}

CGameState* CGameStateFactory::getGameState(CGameState::GameStateType gameStateType)
{
	return gameStates[gameStateType];
}
