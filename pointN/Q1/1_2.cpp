#include <iostream>


template <typename T>
void swap(T* x, T* y) {
	T tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}


class vec2d {
public:
	vec2d() {
		x = 0;
		y = 0;
	}
	vec2d(double _x, double _y) {
		x = _x;
		y = _y;
	}
	void getpos() {
		std::cout << "x:" << x << " y:" << y << std::endl;
	}
private:
	double x;
	double y;
};

int main() {
	int a = 10;
	int b = 20;
	vec2d A(5.0, 6.0);
	vec2d B(3.0, 4.0);
	std::cout << "a=" << a << "," << "b=" << b << std::endl;
	swap(&a, &b);
	std::cout << "-----swap-----" << std::endl;
	std::cout << "a=" << a << "," << "b=" << b << std::endl;
	std::cout << std::endl;
	A.getpos();
	B.getpos();
	swap(&A, &B);
	std::cout << "-----swap-----" << std::endl;
	A.getpos();
	B.getpos();
}
