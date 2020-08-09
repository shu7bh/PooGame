#pragma once
#include "Graphics.h"

class Entity
{
public: // Data Members
	float x, y; // Top Left Coordinates of the object
	float vx = 0, vy = 0; // Velocity of the object
	int r = 255, g = 255, b = 255; // Colour of the object
	int width;

protected: // Member Functions
public:
	Entity() = delete;
	Entity(float x, float y, int width = 24);
	Entity(float x, float y, int r, int g, int b, int width = 24);

	static bool checkCollision(const Entity& player, const Entity& poo);
	virtual void keepInFrame(int right, int bottom);
	virtual void draw(Graphics& gfx) const = 0;
};