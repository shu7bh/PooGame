#pragma once
class Vec2D
{
public:

	float x;
	float y;

public:

	Vec2D();
	Vec2D(float x, float y);

	Vec2D operator*(const float scalar) const;
	Vec2D operator+(const Vec2D& rhs) const;
	Vec2D& operator+=(const Vec2D& rhs);

	void set(const float x, const float y);
};

