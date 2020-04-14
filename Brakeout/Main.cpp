#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\Keyboard.h"
//#include "Engine\Physics\Rigidbody.h"

#include "Brakeout_Game\InputManager.h"
#include "Brakeout_Game\Ball.h"
#include "Brakeout_Game\Platform.h"


#include <iostream>

#define BRICKS_X 10
#define BRICKS_Y 6
#define BRICK_SCALE 0.25

int main()
{
	Engine engine;
	engine.Initialize("Game");

	std::cout << "Hello" << std::endl;

	//int width_platform = Engine::SCREEN_WIDTH / 2;
	//int height_platform = Engine::SCREEN_HEIGHT - 700;

	//Sprite platform = Sprite("Assets/Art/Platform.png", Vector3(width_platform, Engine::SCREEN_HEIGHT - 636, 0));
	//platform.SetScale(0.25f);
	
	//int width_ball = Engine::SCREEN_WIDTH / 2;
	//int height_ball = Engine::SCREEN_HEIGHT / 2;
	Platform platform = Platform();

	Ball ball = Ball(platform);

	//Sprite ball = Sprite("Assets/Art/Ball.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	//ball.SetScale(0.25f);

	Sprite bricks[BRICKS_Y][BRICKS_X];

	int brick_pos_x = 0;
	int brick_pos_y = 0;

	for (int i = 0; i < BRICKS_Y; i++)
	{
		for (int j = 0; j < BRICKS_X; j++)
		{
			brick_pos_x = (48 * j * 2) + 48;
			brick_pos_y = Engine::SCREEN_HEIGHT-(16 * i * 2 + 16);
			bricks[i][j] = Sprite("Assets/Art/Brick.png", Vector3(brick_pos_x, brick_pos_y, 0));
			bricks[i][j].SetScale(BRICK_SCALE);
		}
	}
	
	Texture b("Assets/Art/Brick.png");

	while (true)
	{
		engine.Update();
		ball.Update();

		platform.sprite.SpeedTo(600);

		int x_platform = platform.sprite.GetPos()->x;

		if (Keyboard::Key(GLFW_KEY_LEFT))
		{
			if (x_platform >= 61)
			{
				platform.sprite.MoveLeft();
			}
		}

		if (Keyboard::Key(GLFW_KEY_RIGHT))
		{
			if (x_platform <= 899)
			{
				platform.sprite.MoveRight();
			}
		}

		if ((Keyboard::Key(GLFW_KEY_RIGHT) || Keyboard::Key(GLFW_KEY_LEFT)) && ball.isFixed())
		{
			ball.Reset(platform);
		}

		if (Keyboard::Key(GLFW_KEY_SPACE))
		{
			ball.SetMoving();
		}

		//im.Update();

		engine.BeginRender();
		for (int i = 0; i < BRICKS_Y; i++)
		{
			for (int j = 0; j < BRICKS_X; j++)
			{
				bricks[i][j].Render();
			}
		}

		if (ball.isDroped())
		{
			ball.Reset(platform);
		}

		platform.Render();
		ball.Render();
		ball.checkCollision(platform);

		engine.EndRender();
	}

	return 0;
}