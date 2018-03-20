#ifndef __EQUATION_H__
#define __EQUATION_H__

class Equation {
  public:
    int lcm();            // 最小公倍数
    int gcd();            // 最大公約数
    Equation operator +(const Equation& other) const;
    Equation operator -(const Equation& other) const;
    Equation operator *(double s) const;
    Equation operator /(double s) const;
    Equation& operator +=(const Equation& other);
    Equation& operator -=(const Equation& other);
  // private:
    int a;
    int b;
    int p;
    int q;
};

#endif

