#include <iostream>
#include "Vector2D.h"

int main() {
	Vec2 v1(3, 4);
	Vec2 v2(5, -6);
	Vec2 v3(0, 0);
	Vec2 v4 = v1 + v2;
	std::cout << v1.dot(v2) << std::endl;
	std::cout << v1.cross(v2) << std::endl;
	std::cout << v4.lengthSquare() << std::endl;
	if (v1.isZero()) std::cout << "v1 is zero" << std::endl;
	if (v3.isZero()) std::cout << "v3 is zero" << std::endl;
}
