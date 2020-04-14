#ifndef DR_TEXTURE
#define DR_TEXTURE

#include "GLFW\glfw3.h"
#include "SOIL\src\SOIL.h"

#include <iostream>
#include <string>

class Texture
{
public:
	Texture();
	Texture(int _id);
	Texture(std::string path);

	int GetID();
	int GetWidth();
	int GetHeight();

private:
	bool GetTextureParams();

	int id;
	int width;
	int height;
};

#endif

