#ifndef DR_RECT
#define DR_RECT

#include "Vector3.h"
#include <string>

class Rect
{
public:
	Rect();
	Rect(Vector3 _size);
	Rect(Vector3 _pos, Vector3 _size);

	void MoveBy(Vector3 by);
	void MoveTo(Vector3 to);
	void SetSize(Vector3 _size);

	std::string ToString();

	Vector3 upperLeftVertex;
	Vector3 upperRightVertex;
	Vector3 lowerLeftVertex;
	Vector3 lowerRightVertex;
private:
	void UpdateVertices();

	Vector3 pos;
	Vector3 size;
};

#endif // !DR_RECT

