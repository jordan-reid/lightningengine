#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class CInputManager
{

public:

	CInputManager(void);
	~CInputManager(void);

	void OnKeyUp(int _key);
	void OnKeyDown(int _key);

	bool KeyPressed(int _key);
	bool KeyDown(int _key);

	bool MouseButtonClicked();
	bool MouseButtonDown();

private:

	bool keyTracker[256];
};

#endif

