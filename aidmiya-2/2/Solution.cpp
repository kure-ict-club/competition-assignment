#include <iostream>
#include "Equation.h"
#include "Solution.h"
using namespace std;

ostream& operator<<(ostream& stream, const Solution& value) {
  return stream << '(' << value.x << "," << value.y << ')';
}

// void Solution::CoincideWith'(const Equation& other) const {
void Solution::CoincideWith(const Equation& eq1, const Equation& eq2)/* const*/ {
  // x = \frac{pd-bq}{ad-bc}
  // y = \frac{aq-pc}{ad-bc}
  // a = eq1.a , b = eq1.b , p = eq1.p, c = eq2.a, d = eq2.b , q = eq2. p
  x = (eq1.p * eq2.b - eq1.b * eq2.p) / (eq1.a * eq2.b - eq1.b * eq2.a);
  y = (eq1.a * eq2.p - eq1.p * eq2.a) / (eq1.a * eq2.b - eq1.b * eq2.a);
}

