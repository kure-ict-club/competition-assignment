#include <iostream>
#include <vector>
#include <random>

int main() {
   std::mt19937 rng{ std::random_device()() };
   std::uniform_int_distribution<int> range(0, 9);

   std::vector<int> nums;

   for (int i=0; i<10; ++i) {
      nums.push_back(range(rng));
   }
   for (const auto& num : nums) {
      std::cout << num << std::endl;
   }

   std::cout << std::endl;

   for (int i=0; i<2; ++i) {
      nums.push_back(range(rng));
   }
   for (const auto& num : nums) {
      std::cout << num << std::endl;
   }

   return 0;
}

