// [1] その2 「参照渡し」を使わず、ポインタでswap関数
// swap関数…二つの変数の値を入れ替える関数

#include <iostream>
using namespace std;

void swap(int*, int*);
void put(int, int);

int main() {
  int a = 42;
  int b = 3;
  put(a, b);
  swap(&a, &b);
  put(a, b);
  return 0;
}

void swap(int* p1, int* p2) { // int* p1 = &a;であり、int* p2 = &b;である
  int tmp = *p1;              // int tmp = a;とは書けないが、p1とp2がポインタ変数でなければ、int tmp = p1;と書ける
  *p1 = *p2;                  // *p1 = &bとすると、aにbのアドレスを書くことになる。関数内ではa = b;と書けない。
  *p2 = tmp;                  // もとの*p1(a)をtmpに入れていたので、*p2(b)にtmp。
}
void put(int a, int b) {
  cout << "a=" << a << ", b=" << b << endl;
}
