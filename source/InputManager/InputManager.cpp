#include "InputManager.h"
#include <Windows.h>


CInputManager::CInputManager(void)
{
	for(int i = 0; i < 256; i++)
		keyTracker[i] = false;
}


CInputManager::~CInputManager(void)
{
}

void CInputManager::OnKeyUp(int _key)
{
	keyTracker[_key] = false;
}

void CInputManager::OnKeyDown(int _key)
{
	keyTracker[_key] = true;
}

bool CInputManager::KeyPressed(int _key)
{
	if (GetAsyncKeyState(_key) & 0x01)
		return true;

	return false;
}

bool CInputManager::KeyDown(int _key)
{
	return keyTracker[_key];
}
