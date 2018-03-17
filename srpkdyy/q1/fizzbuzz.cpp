#include <iostream>
#include <string>

std::string toFizzBuzz(int num) {
  if (num % 15 == 0) return "FizzBuzz";
  if (num %  5 == 0) return "Buzz";
  if (num %  3 == 0) return "Fizz";
  return std::to_string(num);
}

int main(void) {
 
  for (int i=0; i<=100; ++i) {
    std::cout << toFizzBuzz(i) << std::endl; 
  }
  return 0;
} 

