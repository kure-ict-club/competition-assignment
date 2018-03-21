#ifndef __SOLUTION_H__
#define __SOLUTION_H__

class Solution {
  public:
    Solution() = default;     // 引数なしのデフォルトコンストラクタ
    Solution(int _x, int _y) : x(_x), y(_y) {}
    // /* void */CoincideWith'(const Equation& other) const;
    void CoincideWith(const Equation& eq1, const Equation& eq2)/* const*/;
//    std::ostream& operator <<(std::ostream& stream, const Solution& value);
    int x;
    int y;
};
std::ostream& operator <<(std::ostream& stream, const Solution& value);

#endif

