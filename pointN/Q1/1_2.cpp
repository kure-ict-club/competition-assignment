#include <iostream>

void swap(int*, int*);

int main() {
	int a = 10;
	int b = 20;
	std::cout << "a=" << a << "," << "b=" << b << std::endl;
	swap(&a, &b);
	std::cout << "a=" << a << "," << "b=" << b << std::endl;
}

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}