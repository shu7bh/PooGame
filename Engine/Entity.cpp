#include "Entity.h"

Entity::Entity(float x, float y, int width)
	: x(x), y(y), width(width) {}

Entity::Entity(float x, float y, int r, int g, int b, int width)
	: x(x), y(y), r(r), g(g), b(b), width(width) {}


bool Entity::checkCollision(const Entity& entity1, const Entity& entity2)
{
	return
		entity1.x < entity2.x + entity2.width &&
		entity1.x + entity2.width > entity2.x &&
		entity1.y < entity2.y + entity2.width &&
		entity1.y + entity1.width > entity2.y;
}

void Entity::keepInFrame(int right, int bottom)
{
	if (int(x) + width >= right)
		x = float(right - width - 1), vx = 0;
	if (int(y) + width >= bottom)
		y = float(bottom - width - 1), vy = 0;
	if (int(x) < 0)
		x = 0, vx = 0;
	if (int(y) < 0)
		y = 0, vy = 0;
}
