#ifndef ISTATEMACHINE_H
#define ISTATEMACHINE_H

#include <stack>
#include "GameState.h"

//Forward declarations
class CGamePlayState;
class CCreditsState;
class CLoadLevelState;
class CMainMenuState;
class COptionsState;
class CPauseState;
class CSplashScreen;
class CRenderer;
class CInputManager;
class CGameStateFactory;

///////////////////////////////////////////////////////////////////
//---------------------------------------------------------------//
//File Name: IStateMachine.cpp								     //
//																 //
//Author: Jordan Reid											 //
//																 //
//Purpose: House the implementation for the stateMachine		 //																										
//---------------------------------------------------------------//
///////////////////////////////////////////////////////////////////

class IStateMachine
{

public:

	IStateMachine(void);
	~IStateMachine(void);

	///////////////////////////////////////////////////////////////////
	//---------------------------------------------------------------//
	//Function Name: Input											 //
	//																 //
	//Purpose: Call the input function of the state on the top of the//
	//stack															 //
	//																 //
	//Return: bool													 //
	//        true - Continue executing game						 //
	//		  false - user exited game, commence shutdown			 //
	//																 //
	//Parameters: CInputManager* _InputManager 						 //
	//			  - A reference to the games inputManger		     //	
	//				Passed into the current states input function    //
	//---------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////
	bool Input(CInputManager* _InputManager);

	////////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------- //
	//Function Name: Update											  //
	//																  //
	//Purpose: Call the update function of the state on the top of the//
	//stack															  //
	//																  //
	//Return: void													  //
	//																  //
	//Parameters: void   											  //
	//--------------------------------------------------------------- //
	//////////////////////////////////////////////////////////////////// 
	void Update(void);

	////////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------- //
	//Function Name: Render											  //
	//																  //
	//Purpose: Call the render function of the state on the top of the//
	//stack															  //
	//																  //
	//Return: void													  //
	//																  //
	//Parameters: void   											  //
	//--------------------------------------------------------------- //
	//////////////////////////////////////////////////////////////////// 
	void Render(void);


	////////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------- //
	//Function Name: InitStateMachine								  //
	//																  //
	//Purpose: Initialize all components of the StateMachine		  //
	//stack															  //
	//																  //
	//Return: void													  //
	//																  //
	//Parameters: void   											  //
	//--------------------------------------------------------------- //
	//////////////////////////////////////////////////////////////////// 
	void InitStateMachine();

	////////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------- //
	//Function Name: ShutDown								          //
	//																  //
	//Purpose: Shutdown all components of the StateMachine		      //
	//stack															  //
	//																  //
	//Return: void													  //
	//																  //
	//Parameters: void   											  //
	//--------------------------------------------------------------- //
	////////////////////////////////////////////////////////////////////
	void ShutDown();

	////////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------- //
	//Function Name: ChangeState								      //
	//																  //
	//Purpose: Tell the StateMachine we need to change state		  //
	//																  //
	//Return: void													  //
	//																  //
	//Parameters: 													  //
	//			CGameState::GameStateType _nextState - Next state to  //
	//			begine executing									  //
	//			bool _popState 										  //
	//				true - we are removing a state from the stack	  //
	//				false - adding a state to the stack				  //
	//--------------------------------------------------------------- //
	////////////////////////////////////////////////////////////////////
	void ChangeState(CGameState::GameStateType _nextState, bool _popState = false);

	//Accessors
	CGameState* GetCurrentState()						{return currentState;};
	CGameState* GetPrevState()							{return prevState;};

	CGameState::GameStateType  GetNextStateType()		{return nextStateType;};
	CRenderer* GetRenderer(void)						{return renderer;};

	//NO MUTATORS!!!!!
	//We don't want anything but the IStateMachine class
	//Modifying its fields :D Seriously, never. 

private:

	//This function is responsible for the actual changing of gamestates
	void HandleStateChanging();

	//Referecne to the games current, and previous state
	CGameState* currentState, *prevState;

	//The state we will be changing to in the next frame
	CGameState::GameStateType nextStateType;

	//If tru, we want to change to the "nextStatetype" next frame
	bool changeState;

	//True if removing a state from the stack, false if adding
	bool popState;

	//A referencee to a GameStatefactory
	CGameStateFactory* gameStateFactory;

	//Use a queue to track gamestates! This is a stack
	//based statemachine
	std::stack<CGameState*> stateStack;

	//REference to the gamse Renderer
	CRenderer*		renderer;

	//Reference to the games InputManagement System
	CInputManager*  InputManager;
};

#endif

