# include <iostream>
# include <vector>
# include <random>

int main()
{
	std::mt19937 mt{ std::random_device()() };
	std::uniform_int_distribution<int> rand0_10(0, 9);
	std::vector<int> nums;

	for (int i = 0; i < 10; ++i)
	{
		nums.push_back(rand0_10(mt));
	}

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	nums.push_back(rand0_10(mt));
	nums.push_back(rand0_10(mt));

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}

	return 0;
}
