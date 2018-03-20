#include <iostream>
#include "swap.h"
using namespace std;

void swap(int* p1, int* p2) { // int* p1 = &a;であり、int* p2 = &b;である
  int tmp = *p1;              // int tmp = a;とは書けないが、p1とp2がポインタ変数でなければ、int tmp = p1;と書ける
  *p1 = *p2;                  // *p1 = &bとすると、aにbのアドレスを書くことになる。関数内ではa = b;と書けない。
  *p2 = tmp;                  // もとの*p1(a)をtmpに入れていたので、*p2(b)にtmp。
}
void put(int a, int b) {
  cout << "a=" << a << ", b=" << b << endl;
}

