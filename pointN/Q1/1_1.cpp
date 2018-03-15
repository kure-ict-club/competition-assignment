#include <iostream>

void toFizzBuzz(int value);

int main() {
	for (int i = 1; i <= 100; ++i) {
		toFizzBuzz(i);
	}
	return 0;
}

void toFizzBuzz(int value) {
	if (value % 15 == 0) {
		std::cout << "FizzBuzz" << std::endl;
	}
	else if (value % 3 == 0) {
		std::cout << "Fizz" << std::endl;
	}
	else if (value % 5 == 0) {
		std::cout << "Buzz" << std::endl;
	}
	else {
		std::cout << value << std::endl;
	}
}