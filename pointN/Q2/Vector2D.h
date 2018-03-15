#pragma once

class Vec2 {
public:
	Vec2();
	Vec2(double, double);
	double lengthSquare() const;
	double dot(const Vec2&) const;
	double cross(const Vec2&) const;
	bool isZero() const;
	Vec2 operator +(const Vec2& other) const {
		return{ x + other.x, y + other.y };
	}
private:
	double x, y;
};