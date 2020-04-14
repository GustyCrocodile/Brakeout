#include "..\Engine\IO\Keyboard.h"
#include "InputManager.h"

InputManager::InputManager(Ball * _ball)
{
	ball = _ball;
}

void InputManager::Update()
{
	if (Keyboard::Key(GLFW_KEY_SPACE))
	{
		ball->Jump();
	}
}
