#include "Entity.h"

Entity::Entity(int x, int y, int width)
	: x(x), y(y), width(width) {}

Entity::Entity(int x, int y, int r, int g, int b, int width)
	: x(x), y(y), r(r), g(g), b(b), width(width) {}


bool Entity::checkCollision(const Entity& entity1, const Entity& entity2)
{
	return
		entity1.x <= entity2.x + entity2.width &&
		entity1.x + entity2.width >= entity2.x &&
		entity1.y <= entity2.y + entity2.width &&
		entity1.y + entity1.width >= entity2.y;
}

void Entity::keepInFrame(int right, int bottom)
{
	if (x + width >= right)
		x = right - width - 1, vx = 0;
	if (y + width >= bottom)
		y = bottom - width - 1, vy = 0;
	if (x < 0)
		x = width, vx = 0;
	if (y < 0)
		y = width, vy = 0;
}
