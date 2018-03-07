
#ifndef _Point_CPP

#define _Point_CPP

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#include <math.h>

template<typename T>
class Point
{
public:

	T x;
	T y;

	Point() noexcept {
		this->x = this->y = 0;
	}
	Point(const Point& iValie) noexcept = default;
	Point(Point&& iValie) noexcept = default;

	Point(const T& iValie) noexcept {
		this->x = iValie;
		this->y = iValie;
	}
	Point(T&& iValie) noexcept {
		this->x = iValie;
		this->y = iValie;
	}
	Point(const T& iValie_x, const T& iValie_y) noexcept {
		this->x = iValie_x;
		this->y = iValie_y;
	}
	Point(T&& iValie_x, T&& iValie_y) noexcept {
		this->x = iValie_x;
		this->y = iValie_y;
	}
	~Point() noexcept = default;

	//=
	Point& operator= (const Point& iValie) noexcept {
		this->x = iValie.x;
		this->y = iValie.y;
		return *this;
	}
	Point& operator= (Point&& iValie) noexcept {
		this->x = iValie.x;
		this->y = iValie.y;
		return *this;
	}

	//+
	Point&& operator+ (const Point& iValie) const noexcept {
		return Point(this->x + iValie.x, this->y + iValie.y);
	}
	Point&& operator+ (Point&& iValie) const noexcept {
		return Point(this->x + iValie.x, this->y + iValie.y);
	}
	Point&& operator+ (const T& iValie) const noexcept {
		return Point(this->x + iValie, this->y + iValie);
	}
	Point&& operator+ (T&& iValie) const noexcept {
		return Point(this->x + iValie, this->y + iValie);
	}
	//+=
	Point& operator+= (const Point& iValie) noexcept {
		this->x += iValie.x;
		this->y += iValie.y;
		return *this;
	}
	Point& operator+= (Point&& iValie) noexcept {
		this->x += iValie.x;
		this->y += iValie.y;
		return *this;
	}
	Point& operator+= (const T& iValie) noexcept {
		this->x += iValie;
		this->y += iValie;
		return *this;
	}
	Point& operator+= (T&& iValie) noexcept {
		this->x += iValie;
		this->y += iValie;
		return *this;
	}

	//-
	Point&& operator- (const Point& iValie) const noexcept {
		return Point(this->x - iValie.x, this->y - iValie.y);
	}
	Point&& operator- (Point&& iValie) const noexcept {
		return Point(this->x - iValie.x, this->y - iValie.y);
	}
	Point&& operator- (const T& iValie) const noexcept {
		return Point(this->x - iValie, this->y - iValie);
	}
	Point&& operator- (T&& iValie) const noexcept {
		return Point(this->x - iValie, this->y - iValie);
	}
	//-=
	Point& operator-= (const Point& iValie)noexcept {
		this->x -= iValie.x;
		this->y -= iValie.y;
		return *this;
	}
	Point& operator-= (Point& iValie)noexcept {
		this->x -= iValie.x;
		this->y -= iValie.y;
		return *this;
	}
	Point& operator-= (const T& iValie)noexcept {
		this->x -= iValie;
		this->y -= iValie;
		return *this;
	}
	Point& operator-= (T&& iValie)noexcept {
		this->x -= iValie;
		this->y -= iValie;
		return *this;
	}

	//*
	T&& operator* (const Point& iValie)const noexcept {
		return (this->x * iValie.x + this->y * iValie.y);
	}
	T&& operator* (Point&& iValie)const noexcept {
		return (this->x * iValie.x + this->y * iValie.y);
	}
	Point&& operator* (const T& iValie)const noexcept {
		return Point(this->x * iValie, this->y * iValie);
	}
	Point&& operator* (T&& iValie)const noexcept {
		return Point(this->x * iValie, this->y * iValie);
	}
	//*=
	Point& operator*= (const T& iValie)noexcept {
		this->x *= iValie;
		this->y *= iValie;
		return *this;
	}
	Point& operator*= (T&& iValie)noexcept {
		this->x *= iValie;
		this->y *= iValie;
		return *this;
	}

	// /
	T&& operator/ (const Point& iValie)const noexcept {
		return (this->x * iValie.y - this->y * iValie.x);
	}
	T&& operator/ (Point&& iValie)const noexcept {
		return (this->x * iValie.y - this->y * iValie.x);
	}
	Point&& operator/ (const T& iValie)const noexcept {
		return Point(this->x / iValie, this->y / iValie);
	}
	Point&& operator/ (T&& iValie)const noexcept {
		return Point(this->x / iValie, this->y / iValie);
	}
	// /=
	Point& operator/= (const T& iValie)noexcept {
		this->x /= iValie;
		this->y /= iValie;
		return *this;
	}
	Point& operator/= (T&& iValie)noexcept {
		this->x /= iValie;
		this->y /= iValie;
		return *this;
	}

	// %
	Point<unsigned int>&& operator% (const unsigned int& iValie)const noexcept {
		return Point<unsigned int>(this->x % iValie, this->y % iValie);
	}
	Point<unsigned int>&& operator% (unsigned int&& iValie)const noexcept {
		return Point<unsigned int>(this->x % iValie, this->y % iValie);
	}
	Point<unsigned int>&& operator% (const Point<unsigned int>& iValie)const noexcept {
		return Point<unsigned int>(this->x % iValie.x, this->y % iValie.y);
	}
	Point<unsigned int>&& operator% (Point<unsigned int>&& iValie)const noexcept {
		return Point<unsigned int>(this->x % iValie.x, this->y % iValie.y);
	}

	// == != ~
	bool&& operator== (const Point& iValie)const noexcept {
		return (this->x == iValie.x && this->y == iValie.y);
	}
	bool&& operator== (Point&& iValie)const noexcept {
		return (this->x == iValie.x && this->y == iValie.y);
	}
	bool&& operator!= (const Point& iValie)const noexcept {
		return (this->x != iValie.x || this->y != iValie.y);
	}
	bool&& operator!= (Point&& iValie)const noexcept {
		return (this->x != iValie.x || this->y != iValie.y);
	}
	Point&& operator~ ()const noexcept {
		return Point(-1 * this->x, -1 * this->y);
	}


	T&& length()const noexcept {
		return sqrt(this->x*this->x + this->y*this->y);
	}
	T&& angle()const noexcept {
		return acos((this->x) / (this->length()))*(180 / PI);
	}
	T&& angle(const Point& iValie)const noexcept {
		return acos(((*this) * iValie) / (this->length() * iValie.length())) *(180 / PI);
	}
	T&& angle(Point&& iValie)const noexcept {
		return acos(((*this) * iValie) / (this->length() * iValie.length())) *(180 / PI);
	}

	T&& lengthSquare()const noexcept {
		return (this->x*this->x + this->y*this->y);
	}
	bool&& isZero()const noexcept {
		return *this == Point(0);
	}


private:


};


#endif
