# ifndef _VECTOR2D_
# define _VECTOR2D_

# include <iostream>

template <class Type>
struct Vector2D
{

	Type x, y;

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
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
	/// ����
	/// </summary>
	/// <param name="vev">
	/// 2�����x�N�g��
	/// </param>
	/// <returns>
	/// ���ς̒l
	/// </returns>
	constexpr Type dot(const Vector2D& vec) const
	{
		return x * vec.x + y * vec.y;
	}

	/// <summary>
	/// �O��
	/// </summary>
	/// <param name="vev">
	/// 2�����x�N�g��
	/// </param>
	/// <returns>
	/// �O�ς̒l
	/// </returns>
	constexpr Type cross(const Vector2D& vec) const
	{
		return x * vec.y - vec.x * y;
	}

	/// <summary>
	/// 2�����x�N�g���̑傫��
	/// </summary>
	/// <returns>
	/// 2�����x�N�g���̑傫��
	/// </returns>
	constexpr Type length() const
	{
		return std::sqrt(lengthSquare());
	}

	/// <summary>
	/// �x�N�g���̑傫����2��
	/// </summary>
	/// <returns>
	/// �x�N�g���̑傫����2��
	/// </returns>
	constexpr Type lengthSquare() const
	{
		return this->dot(*this);
	}

	/// <summary>
	/// ��x�N�g���ł��邩�ǂ���
	/// </summary>
	/// <returns>
	/// ��x�N�g���ł��邩�ǂ���
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
