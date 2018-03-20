#ifndef _VECTOR2_HPP_
#define _VECTOR2_HPP_

class Vector2 {
public:
  double x, y;

  Vector2(double, double);

  bool isZero() const;

  double lengthSquare() const;

  double dot(const Vector2&) const;
//  double cross(const Vector2&) const;
//  二次元ベクトルの外積は定義されない（はず）

  Vector2 operator+(const Vector2& v) const;
};

#endif
