# ifndef _VECTOR2D_
# define _VECTOR2D_

# include <iostream>

template <class Type>
struct Vector2D
{

	Type x, y;

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Vector2D() = default;

	constexpr Vector2D(Type _x, Type _y)
		: x(_x), y(_y)
	{}

	template <class U, class V>
	constexpr Vector2D(U _x, V _y)
		: x(static_cast<Type>(_x))
		, y(static_cast<Type>(_y))
	{}

	template <class U>
	constexpr Vector2D(const Vector2D<U> &vec)
		: x(static_cast<Type>(vec.x)), y(static_cast<Type>(vec.y))
	{}


	constexpr Vector2D operator +() { return *this; }

	constexpr Vector2D operator -() { return{ -x, -y }; }

	constexpr Vector2D operator +(const Vector2D& vec) const { return{ x + vec.x, y + vec.y }; }

	constexpr Vector2D operator -(const Vector2D& vec) const { return{ x - vec.x, y - vec.y }; }

	constexpr Vector2D operator *(Type k) const { return{ x * k, y * k }; }

	constexpr Vector2D operator /(Type k) const { return{ x / k, y / k }; }

	Vector2D operator +=(const Vector2D& vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	Vector2D operator -=(const Vector2D& vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	Vector2D operator *=(Type k)
	{
		x *= k;
		y *= k;
		return *this;
	}

	Vector2D operator /=(Type k)
	{
		x /= k;
		y /= k;
		return *this;
	}

	constexpr bool operator ==(const Vector2D& vec) const { return (x == vec.x && y == vec.y); }

	constexpr bool operator !=(const Vector2D& vec) const { return (x != vec.x && y != vec.y); }

	constexpr bool operator > (const Vector2D& vec) const { return (lengthSquare() >  vec.lengthSquare()); }
	constexpr bool operator >=(const Vector2D& vec) const { return (lengthSquare() >= vec.lengthSquare()); }

	constexpr bool operator < (const Vector2D& vec) const { return (lengthSquare() <  vec.lengthSquare()); }
	constexpr bool operator <=(const Vector2D& vec) const { return (lengthSquare() <= vec.lengthSquare()); }


	/// <summary>
	/// 内積
	/// </summary>
	/// <param name="vev">
	/// 2次元ベクトル
	/// </param>
	/// <returns>
	/// 内積の値
	/// </returns>
	constexpr Type dot(const Vector2D& vec) const
	{
		return x * vec.x + y * vec.y;
	}

	/// <summary>
	/// 外積
	/// </summary>
	/// <param name="vev">
	/// 2次元ベクトル
	/// </param>
	/// <returns>
	/// 外積の値
	/// </returns>
	constexpr Type cross(const Vector2D& vec) const
	{
		return x * vec.y - vec.x * y;
	}

	/// <summary>
	/// 2次元ベクトルの大きさ
	/// </summary>
	/// <returns>
	/// 2次元ベクトルの大きさ
	/// </returns>
	constexpr Type length() const
	{
		return std::sqrt(lengthSquare());
	}

	/// <summary>
	/// ベクトルの大きさの2乗
	/// </summary>
	/// <returns>
	/// ベクトルの大きさの2乗
	/// </returns>
	constexpr Type lengthSquare() const
	{
		return this->dot(*this);
	}

	/// <summary>
	/// 零ベクトルであるかどうか
	/// </summary>
	/// <returns>
	/// 零ベクトルであるかどうか
	/// </returns>
	constexpr bool isZero() const
	{
		return x == static_cast<Type>(0.0) && y == static_cast<Type>(0.0);
	}
};

template <class Type>
std::ostream& operator<<(std::ostream& stream, const Vector2D<Type>& vec) {
	return stream << "(" << vec.x << ", " << vec.y << ")";
}

# endif // _VECTOR2D_
