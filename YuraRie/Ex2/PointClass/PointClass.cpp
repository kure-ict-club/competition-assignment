// PointClass.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Point.h"

int main()
{

	Point<double> point,point2;

	Point<double> p;
	double a;
	int b;

	p = point + point2;
	p = point - point2;
	a = point * point2;
	a = point / point2;
	p = point * a;
	p = point / a;

	p = point + Point<double>(1,1);
	p = point - Point<double>(point2);
	a = point * Point<double>(point2);
	a = point / Point<double>(point2);
	p = point * 2;
	p = point / 2;

	~point;

	point.length();

	point.angle();
	point.angle(point2);
	point.angle(Point<double>(point2));

	point.x = 4.0;
	point.y = 0.0;
	point2.x = 4.0;
	point2.y = 2.0;

	std::cout << (point == point2) << std::endl;
	std::cout << (point != point2) << std::endl;
	std::cout << (point == ~point2) << std::endl;
	std::cout << (point != ~point2) << std::endl;
	std::cout << point.length() << std::endl;
	std::cout << point.angle() << std::endl;
	std::cout << point.angle(~point) << std::endl;
	std::cout << point.angle(point2) << std::endl;

	
    return 0;
}