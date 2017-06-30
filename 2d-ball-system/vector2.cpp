#include "vector2.h"

Vector2::Vector2(double _x, double _y)
{
	x = _x;
	y = _y;
}

double Vector2::mode() const
{
	double m = sqrt(x * x + y * y);
	return m;
}

Vector2 operator+(const Vector2 &l, const Vector2 &r)
{
	return Vector2(l.x + r.x, l.y + r.y);
}

Vector2 operator-(const Vector2 & obj)
{
	return Vector2(-obj.x, -obj.y);
}

Vector2 operator-(const Vector2 & l, const Vector2 & r)
{
	return l + (-r);
}

Vector2 operator*(double fac, const Vector2 & obj)
{
	return Vector2(fac * obj.x, fac * obj.y);
}

Vector2 operator*(const Vector2 & obj, double fac)
{
	return fac * obj;
}

double operator*(const Vector2 & l, const Vector2 & r)
{
	return l.x * r.x + l.y * r.y;
}

bool operator==(const Vector2 & l, const Vector2 & r)
{
	return (l.x == r.x) && (l.y == r.y);
}
