#include "Vector2.hpp"

Vector2::Vector2(double x, double y) : x(x), y(y) {

} 

bool Vector2::isZero() const {
   return x == 0.0 && y == 0.0;
}

double Vector2::lengthSquare() const {
   return x*x + y*y;
}

double Vector2::dot(const Vector2& v) const {
   return x*v.x + y*v.y;
}

Vector2 Vector2::operator+(const Vector2& v) const {
   return Vector2(x+v.x, y+v.y);
}
