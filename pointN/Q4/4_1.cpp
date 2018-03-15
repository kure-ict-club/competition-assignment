#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> nums;
	std::vector<int> primeNums;
	for (int i = 2; i <= 1000; ++i) {
		nums.emplace_back(i);
	}
	while (nums[0] < 32) {
		auto rmvIter = std::remove_if(nums.begin()+1,nums.end(),
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
	for (auto x : primeNums) {
		std::cout << x << " ";
	}
}