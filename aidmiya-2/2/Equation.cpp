#include <iostream>
#include "Equation.h"
using namespace std;

// a, b, pの最小公倍数
int Equation::lcm() {   // 未実装
  return 0;
}

// a, b, pの最大公約数
int Equation::gcd() {   // 未実装
  return 0;
}

// 式(オブジェクト)同士の演算を定義する、演算子のオーバーロード(演算子+)
// 使用例 eq3 = eq1 + eq2;
Equation Equation::operator +(const Equation& other) const {
  return Equation( a + other.a , b + other.b , p + other.p );
}

// 演算子-
Equation Equation::operator -(const Equation& other) const {
  return Equation( a - other.a , b - other.b , p - other.p );
}

// 演算子*
Equation Equation::operator *(double s) const {
  return Equation( a*s, b*s, p*s );
}

// 演算子/
Equation Equation::operator /(double s) const {
  return Equation( a/s, b/s, p/s );
}

/* 未実装
// 演算子+= a+=b -> a=a+b
// 使用例 eq1 += eq2;       ...eq1 = eq1 + eq2;
Equation& Equation::operator +=(const Equation& other) {
  return Equation( a + other.a , b + other.b , p + other.p );
}

// 演算子-=
Equation& Equation::operator -=(const Equation& other) {
  return Equation( a - other.a , b - other.b , p - other.p );
}
*/

