#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void findPrimeNum(std::vector<int>& primeNums) {
	std::vector<int> nums;
	for (int i = 2; i <= 10000; ++i) {
		nums.emplace_back(i);
	}
	while (nums[0] < 100) {
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

int rad(int num) {
	std::vector<int> primeNums;
	std::vector<int> factors;
	bool added = false;
	int ans = 1;
	findPrimeNum(primeNums);
	for (unsigned int i = 0; i < primeNums.size(); ++i) {
		if (num % primeNums[i] == 0) {
			num /= primeNums[i];
			if (!added) {
				factors.emplace_back(primeNums[i]);
				added = true;
			}
			--i;
			if (num == 1) {
				break;
			}
			continue;
		}
		added = false;
	}
	for (unsigned int i = 0; i < factors.size(); ++i) {
		ans *= factors[i];
	}
	return ans;
}

double q(int a, int b, int c) {
	return log(c) / log(rad(a*b*c));
}

int main() {
	int a = 1, b = 2, c;
	std::cin >> a;
	std::cin >> b;
	c = a + b;
	std::cout << q(a,b,c) << std::endl;
}