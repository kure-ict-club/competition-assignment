// [2] 連立一次方程式を解く
// ax+by=p, bx+cy=qで、xとyを求める

#include <iostream>
#include "Equation.h"
#include "Solution.h"
using namespace std;

int main() {

  // 変数の定義
  int a, b, p, c, d, q;

  // 式の入力・設定・表示
  a = 2;  b = 3;  p = 1;  c = 3;  d = 5;  q = 11;  // x=2, y=-1

  cout << "代入したa, b, p, c, d, qを表示します。" << endl;
  cout << "式1: " << a << "x + " << b << "y = " << p << endl;
  cout << "式2: " << c << "x + " << d << "y = " << q << endl;

  Equation eq1(a, b, p);
  Equation eq2(c, d, q);
  cout << "式をインスタンス化したので、eq1.a, eq1.b, eq1.p, eq2.a, eq2.b, eq2.pを表示します。" << endl;
  cout << "eq1: " << eq1.a << "x + " << eq1.b << "y = " << eq1.p << endl;
  cout << "eq2: " << eq2.a << "x + " << eq2.b << "y = " << eq2.p << endl;

/*
  // 演算子のテスト…動的につくるインスタンスで
  Equation eq_add = new Equation();
  eq_add = eq1 + eq2;
  cout << "eq_add=eq1+eq2のa, b, p: " << eq_add->a << eq_add->b << eq_add->p << endl;
  delete eq_add;
*/

  // 解く
  Solution ans;
  ans.CoincideWith(eq1, eq2);
  // 表示

  return 0;
}

