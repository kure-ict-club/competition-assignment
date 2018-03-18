#include <iostream>
#include <vector>
#include <random>

int main() {
   std::mt19937 rng{ std::random_device()() };

   std::vector<int> nums;

   for (int i=0; i<10; ++i) {
      nums.push_back( rng()%10 );
   }
   for (const auto& num : nums) {
      std::cout << num << std::endl;
   }

   std::cout << std::endl;

   for (int i=0; i<2; ++i) {
      nums.push_back( rng()%10 );
   }
   for (const auto& num : nums) {
      std::cout << num << std::endl;
   }

   return 0;
}

