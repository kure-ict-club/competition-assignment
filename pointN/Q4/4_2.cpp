#include <iostream>
#include <vector>
#include <algorithm>

void findPrimeNum(std::vector<int>& primeNums) {
	std::vector<int> nums;
	for (int i = 2; i <= 1000; ++i) {
		nums.emplace_back(i);
	}
	while (nums[0] < 32) {
		auto rmvIter = std::remove_if(nums.begin() + 1, nums.end(),
			[=](int x) {
			return (x % nums[0]) == 0;
		}
		);
		primeNums.emplace_back(nums[0]);
		nums.erase(rmvIter, nums.end());
		nums.erase(nums.begin());
	}
	for (auto x : nums) {
		primeNums.emplace_back(x);
	}
}

void factorization(int num,std::vector<int> primeNums, std::vector<int>& factors) {
	for (unsigned int i = 0; i < primeNums.size(); ++i) {
		if (num % primeNums[i] == 0) {
			num /= primeNums[i];
			factors.emplace_back(primeNums[i]);
			--i;
		}
		if (num == 1) {
			break;
		}
	}
}

int main() {
	int num = 0;
	std::vector<int> primeNums;
	std::vector<int> factors;
	findPrimeNum(primeNums);
	std::cin >> num;
	factorization(num, primeNums, factors);
	std::cout << num << std::endl << "->";
	for (unsigned int i = 0; i < factors.size(); ++i) {
		std::cout << factors[i] << " ";
	}
}