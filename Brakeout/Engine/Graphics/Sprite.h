#ifndef DR_SPRITE
#define DR_SPRITE

#include "GLFW\glfw3.h"
#include "Texture.h"
#include "..\Math\Vector3.h"

#include <iostream>	
#include <string>

class Sprite
{
public:
	Sprite();
	Sprite(std::string imagePath);
	Sprite(std::string imagePath, Vector3 _pos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScalse(Vector3 v);

	Vector3* GetPos();
	float*	 GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;

	float speed;

	Vector3 pos;
	Vector3 scale;
	float rot;
	Vector3 size;
};

#endif

