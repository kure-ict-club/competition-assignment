#include <iostream>
#include <string>

template <typename T>
void swap(T *a, T *b) {
     T tmp = *a;
     *a = *b;
     *b = tmp;
}

int main(void) {
   int a = 19, b = 828;
   std::string hello("hello"), world("world");

   std::cout << "a : " << a << "  b : " << b << std::endl;
   swap(&a, &b);
   std::cout << "a : " << a << "  b : " << b << std::endl;

   std::cout << "hello : " << hello << "  world : " << world << std::endl;
   swap(hello, world);
   std::cout << "hello : " << hello << "  world : " << world << std::endl;

   return 0;
}
