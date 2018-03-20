#include <iostream>
#include "Vector2.hpp"

int main() {
   Vector2 v1(2.8, 9.3), v2(2.3, 4.3);

   std::cout << v1.isZero() << std::endl;
   std::cout << v2.lengthSquare() << std::endl;
   std::cout << v1.dot(v2) << std::endl;
   
   std::cout << (v1+v2).lengthSquare() << std::endl;
}

