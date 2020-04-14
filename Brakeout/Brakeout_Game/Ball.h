#ifndef DR_BALL
#define DR_BALL

#include "..\Engine\Graphics\Sprite.h"
//#include "..\Engine\Physics\Rigidbody.h"
#include "..\Engine\Engine.h"

#include "..\Brakeout_Game\Platform.h"

class Ball
{
public:
	Ball(Platform& platform);

	void Update();
	void Render();

	void Jump();

	Sprite& GetSprite();
	void Reset(Platform& platform);

	bool isFixed();
	bool isDroped();

	void SetFixed();
	void SetMoving();

	void SetVeloctiy(Vector3 _vector);
	//void MoveDirection();

	void checkCollision(Platform& platform);

	int GetPosX();
	int GetPosY();

private:
	Sprite sprite;
	int pos_x;
	int pos_y;
	bool fixed;
	int speed;

	bool droped;

	Vector3 velocity;
};

#endif
