#include "Ball.h"

#include <iostream>

#define RADIUSS 16

Ball::Ball(Platform& platform)
{
	this->Reset(platform);
	this->sprite = Sprite("Assets/Art/Ball.png", Vector3(this->pos_x, this->pos_y, 0));
	this->sprite.SetScale(0.25f);

	this->speed = 500;
}

void Ball::Update()
{

	int left_wall = 0;
	int right_wall = 965;

	int top_wall = 752;
	int bottom_wall = 0;

	if ((this->sprite.GetPos()->x - RADIUSS) < left_wall)
	{
		// Vai bumba nâk no lejas
		if (this->velocity.y > 0)
		{
			this->velocity = Vector3(1, 1, 0);
		}

		if (this->velocity.y < 0)
		{
			this->velocity = Vector3(1, -1, 0);
		}
		
	}

	if ((this->sprite.GetPos()->x + RADIUSS) > right_wall)
	{
		// Vai bumba nâk no lejas
		if (this->velocity.y > 0)
		{
			this->velocity = Vector3(-1, 1, 0);
		}

		if (this->velocity.y < 0)
		{
			this->velocity = Vector3(-1, -1, 0);
		}
	}

	if ((this->sprite.GetPos()->y + RADIUSS) > top_wall)
	{
		// Vai bumba nâk no lejas
		if (this->velocity.x > 0)
		{
			this->velocity = Vector3(1, -1, 0);
		}

		if (this->velocity.x < 0)
		{
			this->velocity = Vector3(-1, -1, 0);
		}
	}

	if ((this->sprite.GetPos()->y - RADIUSS) < bottom_wall)
	{
		this->droped = true;
		/*
				if (this->velocity.x > 0)
		{
			this->velocity = Vector3(1, 1, 0);
		}

		if (this->velocity.x < 0)
		{
			this->velocity = Vector3(-1, 1, 0);
		}
		*/
	}

	this->sprite.MoveBy(Vector3(this->velocity.x * this->speed, this->velocity.y * this->speed, 0)); //this->speed
}

void Ball::Reset(Platform& platform)
{
	this->pos_x = platform.sprite.GetPos()->x;
	this->pos_y = platform.sprite.GetPos()->y + 33;

	this->sprite.MoveTo(Vector3(this->pos_x, this->pos_y, 0));
}

bool Ball::isFixed()
{
	if (this->fixed)
	{
		return true;
	}
	return false;
}

bool Ball::isDroped()
{
	if (this->droped)
	{
		return true;
	}
	return false;
}

void Ball::SetFixed()
{
	this->fixed = true;
}

void Ball::SetMoving()
{	
	if (this->isFixed())
	{
		this->fixed = false;
		this->SetVeloctiy(Vector3(1, 1, 0));
	}
}

void Ball::SetVeloctiy(Vector3 _vector)
{
	this->velocity = _vector;
}


/*
	@TODO: ja bumba ir iekðâ objektâ velocity nevajag mainît katrâ freimâ

*/
void Ball::checkCollision(Platform& platform)
{
	int platform_x = platform.sprite.GetPos()->x;
	int platform_y = platform.sprite.GetPos()->y;

	int platform_x1 = platform_x - 61;
	int platform_y1 = platform_y + 16;

	int platform_x2 = platform_x + 61;
	int platform_y2 = platform_y - 16;

	int ball_x = this->sprite.GetPos()->x;
	int ball_y = this->sprite.GetPos()->y;

	int ball_x1 = ball_x - RADIUSS;
	int ball_y1 = ball_y + RADIUSS;

	int ball_x2 = ball_x + RADIUSS;
	int ball_y2 = ball_y - RADIUSS;

	std::cout << "P1 X1:" << platform_x1 << ", P1 y2" << platform_y1 << std::endl;
	std::cout << "P2 X2:" << platform_x2 << ", P2 y2" << platform_y2 << std::endl;
	std::cout << ball_x1 << " " << ball_y1 << " " << ball_x2 << " " << ball_y2 << std::endl;

	if ( (platform_x1 < ball_x2 && platform_x2 > ball_x1) &&
			(platform_y1 > ball_y2) ||
		(platform_x1 < ball_x2 && platform_x2 > ball_x1) &&
		(platform_y2 > ball_y1)
		)
	{
		if (this->velocity.x > 0)
		{
			if (this->velocity.y < 0)
			{
				this->velocity = Vector3(1, 1, 0);
			}
			else
			{
				this->velocity = Vector3(1, -1, 0);
			}
			
		}

		if (this->velocity.x < 0)
		{
			if (this->velocity.y < 0)
			{
				this->velocity = Vector3(-1, 1, 0);
			}
			else
			{
				this->velocity = Vector3(-1, -1, 0);
			}
			
		}
	}

}

int Ball::GetPosX()
{
	return this->pos_x;
}

int Ball::GetPosY()
{
	return this->pos_y;
}

void Ball::Render()
{
	this->Update();
	this->sprite.Render();
	//rb.Render(Vector3(0, 0, 0));
}

void Ball::Jump()
{
	//rb.SetVel(Vector3(0, jumpForce, 0));
}

Sprite & Ball::GetSprite()
{
	return sprite;
}

