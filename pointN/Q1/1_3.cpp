#include <iostream>
#include <vector>
#include <random>

int main() {
	std::vector<int> num;
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand10(0, 9);
	for (int i = 0; i < 10; ++i) {
		num.emplace_back(rand10(mt));
	}
	for (auto x : num) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	std::cout << "—v‘f‚ð’Ç‰Á" << std::endl;
	for (int i = 0; i < 2; ++i) {
		num.emplace_back(rand10(mt));
	}
	for (auto x : num) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}