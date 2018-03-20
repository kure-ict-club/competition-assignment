// [1] その2 「参照渡し」を使わず、ポインタでswap関数
// swap関数…二つの変数の値を入れ替える関数

#include <iostream>
#include "swap.h"
using namespace std;

int main() {
  int a = 42;
  int b = 3;
  put(a, b);
  swap(&a, &b);
  put(a, b);
  return 0;
}

