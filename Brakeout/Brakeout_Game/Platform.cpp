#include "Platform.h"

Platform::Platform()
{
	this->pos_x = (float)Engine::SCREEN_WIDTH / 2;
	this->pos_y = (float)Engine::SCREEN_HEIGHT - 650;
	
	this->sprite = Sprite("Assets/Art/Platform.png", Vector3(pos_x, pos_y, 0));
	this->sprite.SetScale(0.25f);
}

void Platform::Update()
{
}

void Platform::Render()
{
	this->sprite.Render();
}

Sprite & Platform::GetSprite()
{
	// TODO: insert return statement here
	return this->sprite;
}
