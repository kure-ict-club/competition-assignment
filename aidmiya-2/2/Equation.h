#ifndef __EQUATION_H__
#define __EQUATION_H__

class Equation {  // a(x) + b(y) = pを1オブジェクトで1式表す
  public:
    Equation() = default;   // 引数なしのデフォルトコンストラクタ
    Equation(int _a, int _b, int _p) : a(_a), b(_b), p(_p) {}
    int lcm();            // 最小公倍数
    int gcd();            // 最大公約数
    Equation operator +(const Equation& other) const;     // ここでotherは式(オブジェクト)のアドレスを参照渡ししている
    Equation operator -(const Equation& other) const;
    Equation operator *(double s) const;
    Equation operator /(double s) const;
    Equation& operator +=(const Equation& other);
    Equation& operator -=(const Equation& other);
  // private:
    int a;      // other.a はc
    int b;      // other.b はd
    int p;      // other.p はqにあたる
};

#endif

