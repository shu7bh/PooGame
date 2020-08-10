#include "Entity.h"

Entity::Entity(Vec2D& coordinate, int width)
	: coordinate(coordinate), width(width) {}

Entity::Entity(Vec2D& coordinate, int r, int g, int b, int width)
	: coordinate(coordinate), r(r), g(g), b(b), width(width) {}


bool Entity::checkCollision(const Entity& entity1, const Entity& entity2)
{
	return
		entity1.coordinate.x < entity2.coordinate.x + entity2.width &&
		entity1.coordinate.x + entity2.width > entity2.coordinate.x &&
		entity1.coordinate.y < entity2.coordinate.y + entity2.width &&
		entity1.coordinate.y + entity1.width > entity2.coordinate.y;
}

void Entity::keepInFrame(Vec2D& vertice) // Bottom right vertice taken
{
	if (int(coordinate.x) + width >= vertice.x)
		coordinate.x = float(vertice.x - width - 1), velocity.x = 0;
	if (int(coordinate.y) + width >= vertice.y)
		coordinate.y = float(vertice.y - width - 1), velocity.y = 0;
	if (int(coordinate.x) < 0)
		coordinate.x = 0, velocity.x = 0;
	if (int(coordinate.y) < 0)
		coordinate.y = 0, velocity.y = 0;
}
