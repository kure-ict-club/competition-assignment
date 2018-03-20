#ifndef __SOLUTION_H__
#define __SOLUTION_H__

class Solution {
  public:
    Solution() = default;
    Solution(int _x, int _y)
      : x(_x)
      , y(_y)
    {
    }
    CoincideWith'(const Equation& other) const;
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& stream, const Solution& value) {
  return stream << '(' << value.x << "," << value.y << ')';
}

#endif

