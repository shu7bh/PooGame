#include "Vec2D.h"

Vec2D::Vec2D()
	: x(0.0f), y(0.0f) {}
Vec2D::Vec2D(float x, float y)
	: x(x), y(y) {}

Vec2D Vec2D::operator*(const float scalar) const
{
	return Vec2D(x * scalar, y * scalar);
}

Vec2D Vec2D::operator+(const Vec2D& rhs) const
{
	return Vec2D(x + rhs.x, y + rhs.y);
}

Vec2D& Vec2D::operator+=(const Vec2D& rhs)
{
	return *this = *this + rhs;
}

void Vec2D::set(const float x, const float y)
{
	this->x = x, this->y = y;
}
