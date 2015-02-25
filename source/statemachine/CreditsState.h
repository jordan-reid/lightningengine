///////////////////////////////////////////////////////////////////
//---------------------------------------------------------------//
//File Name: CreditsState.h										 //
//																 //
//Author: Jordan Reid											 //
//																 //
//Purpose: House the Credits State class oject					 //																										
//---------------------------------------------------------------//
///////////////////////////////////////////////////////////////////

#ifndef CCREDITSSTATE_H
#define CCREDITSSTATE_H


#include "gamestate.h"

//Forward Declarations 
class CInputManager;

class CCreditsState : public CGameState
{

public:

	//Constructor && destructor
	CCreditsState(void);
	~CCreditsState(void);


	//////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------//
	//Function Name: Input										    //
	//																//
	//Parameters:													//
	//			CInputManager*: A reference to the input management	//
	//					        system.								//															
	//Return: 														//
	//			returns true or false based on unser input.			//
	//			return false if player wants to quit the game.		//
	//			return true for anything else.						//
	//																//
	//Purpose:														//
	//			Accept user input in the credits state.				//
	//--------------------------------------------------------------//
	//////////////////////////////////////////////////////////////////
	bool Input(CInputManager* _inputManager);

	//////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------//
	//Function Name: Update											//
	//																//
	//Parameters:													//
	//			void												//
	//																//															
	//Return: 														//
	//		    void.												//
	//																//
	//Purpose:														//
	//			Update the Credits state							//
	//--------------------------------------------------------------//
	//////////////////////////////////////////////////////////////////
	void Update(void);

	//////////////////////////////////////////////////////////////////
	//--------------------------------------------------------------//
	//Function Name: Render											//
	//																//
	//Parameters:													//
	//			void												//
	//																//															
	//Return: 														//
	//		    void												//
	//																//
	//Purpose:														//
	//			Render the credits state							//
	//--------------------------------------------------------------//
	//////////////////////////////////////////////////////////////////
	void Render(void);
};

#endif

