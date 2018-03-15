#include "Vector2D.h"

Vec2::Vec2() {}

Vec2::Vec2(double _x, double _y) : x(_x), y(_y) {}

double Vec2::lengthSquare() const {
	return this->x * this->x + this->y * this->y;
}

double Vec2::dot(const Vec2& other) const {
	return this->x * other.x + this->y * other.y;
}

double Vec2::cross(const Vec2& other) const {
	return this->x * other.y - this->y * other.x;
}

bool Vec2::isZero() const {
	if (this->x == 0.0 && this->y == 0.0) {
		return true;
	}
	return false;
}