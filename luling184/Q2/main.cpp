# include <iostream>
# include <conio.h>
# include "Vector2D.h"

int main()
{
	Vector2D<int> vec1(3, 4);
	Vector2D<int> vec2(5, 12);

	std::cout << "vec1 = " << vec1 << std::endl;
	std::cout << "lengthSqueare = " << vec1.lengthSquare() << std::endl;
	std::cout << "length = " << vec1.length() << std::endl;

	std::cout << std::endl;

	std::cout << "vec2 = " << vec2 << std::endl;
	std::cout << "lengthSqueare = " << vec2.lengthSquare() << std::endl;
	std::cout << "length = " << vec2.length() << std::endl;

	std::cout << std::endl;

	std::cout << "-vec1 = " << -vec1 << std::endl;
	std::cout << "vec1 * 2 = " << vec1 * 2 << std::endl;
	std::cout << "vec1 + vec2 = " << vec1 + vec2 << std::endl;
	std::cout << "vec1 - vec2 = " << vec1 - vec2 << std::endl;

	std::cout << std::endl;

	std::cout << "vec1.dot(vec2) = " << vec1.dot(vec2) << std::endl;
	std::cout << "vec1.cross(vec2) = " << vec1.cross(vec2) << std::endl;

	std::cout << std::endl;

	std::cout << "vec1 == vec2 = " << (vec1 == vec2 ? "True" : "False") << std::endl;
	std::cout << "vec1 > vec2 = " << (vec1 > vec2 ? "True" : "False") << std::endl;
	std::cout << "vec1 < vec2 = " << (vec1 < vec2 ? "True" : "False") << std::endl;

	_getch();
	return 0;
}