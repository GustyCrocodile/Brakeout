#ifndef DR_PLATFORM
#define DR_PLATFORM

#include "..\Engine\Graphics\Sprite.h"
//#include "..\Engine\Physics\Rigidbody.h"
#include "..\Engine\Engine.h"

class Platform
{
public:
	Platform();

	void Update();
	void Render();
	Sprite sprite;

	Sprite& GetSprite();
private:
	float pos_x;
	float pos_y;

};


#endif