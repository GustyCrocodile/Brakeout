#ifndef DR_INPUTMANAGER
#define DR_INPUTMANAGER

#include "..\Engine\Engine.h"
#include "Ball.h"

class InputManager
{
public:	
	InputManager(Ball* _ball);

	void Update();

private:
	Ball* ball;
};

#endif // !DR_INPUTMANAGER
