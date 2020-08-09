#include "Entity.h"

Entity::Entity(int x, int y, int width)
	: x(x), y(y), width(width)
{
	calculateEdges();
}

Entity::Entity(int x, int y, int r, int g, int b, int width)
	: x(x), y(y), r(r), g(g), b(b), width(width)
{
	calculateEdges();
}

void Entity::calculateEdges()
{
	left = x - width;
	right = x + width;
	top = y - width;
	bottom = y + width;
}

void Entity::keepInFrame(int right, int bottom)
{
	if (this->right >= right)
		x = right - width - 1, vx = 0;
	if (this->bottom >= bottom)
		y = bottom - width - 1, vy = 0;
	if (left < 0)
		x = width, vx = 0;
	if (top < 0)
		y = width, vy = 0;

	calculateEdges();
}
