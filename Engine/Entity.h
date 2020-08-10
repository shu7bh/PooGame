#pragma once
#include "Graphics.h"
#include "Vec2D.h"

class Entity
{
public: // Data Members
	Vec2D coordinate; // Top Left Coordinates of the object
	Vec2D velocity; // Velocity of the object
	int r = 255, g = 255, b = 255; // Colour of the object
	int width;

protected: // Member Functions
public:
	Entity() = delete;
	Entity(Vec2D& coordinate, int width = 24);
	Entity(Vec2D& coordinate, int r, int g, int b, int width = 24);

	static bool checkCollision(const Entity& player, const Entity& poo);
	virtual void keepInFrame(Vec2D& vertice);
	virtual void draw(Graphics& gfx) const = 0;
};