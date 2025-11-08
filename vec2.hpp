#pragma once

#include <cmath>

#define Vec2Int Vec2<int>
#define Vec2Float Vec2<float>

template <typename T>
class Vec2
{
public:
	T x;
	T y;

	Vec2<T>() = default;

	Vec2<T>(T xin, T yin);

	Vec2<T> operator + (const Vec2<T> val) const;
	Vec2<T> operator - (const Vec2<T> val) const;
	Vec2<T> operator * (const T val) const;
	Vec2<T> operator / (const T val) const;
	Vec2<T> operator += (const Vec2<T> val);
	Vec2<T> operator -= (const Vec2<T> val);
	Vec2<T> operator *= (const T val);
	Vec2<T> operator /= (const T val);
	bool operator == (const Vec2<T>& rhs) const;
	bool operator != (const Vec2<T>& rhs) const;

	float length();
	Vec2<T> normalize();
};

template<typename T>
Vec2<T>::Vec2(T xin, T yin)
{
	x = xin;
	y = yin;
}

template<typename T>
Vec2<T> Vec2<T>::operator+(const Vec2<T> val) const
{
	return { x + val.x,  y + val.y };
}

template<typename T>
Vec2<T> Vec2<T>::operator-(const Vec2<T> val) const
{
	return { x - val.x,  y - val.y };

}

template<typename T>
Vec2<T> Vec2<T>::operator*(const T val) const
{
	return { x * val,  y * val };
}

template<typename T>
Vec2<T> Vec2<T>::operator/(const T val) const
{
	return { x / val,  y / val };
}

template<typename T>
Vec2<T> Vec2<T>::operator+=(const Vec2<T> val)
{
	x += val.x;
	y += val.y;
	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::operator-=(const Vec2<T> val)
{
	x -= val.x;
	y -= val.y;
	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::operator*=(const T val)
{
	x *= val;
	y *= val;
	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::operator/=(const T val)
{
	x /= val;
	y /= val;
	return *this;
}

template<typename T>
bool Vec2<T>::operator==(const Vec2<T>& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

template<typename T>
bool Vec2<T>::operator!=(const Vec2<T>& rhs) const
{
	return x != rhs.x || y != rhs.y;
}

template<typename T>
float Vec2<T>::length()
{
	return std::sqrt(x * x + y * y);
}

template<typename T>
Vec2<T> Vec2<T>::normalize()
{
	Vec2 res;
	float len = length();

	if (len > 0)
	{
		res.x = x / len;
		res.y = y / len;
	}

	return res;
}



