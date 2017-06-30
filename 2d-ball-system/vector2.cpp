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

double veccos(const Vector2 & l, const Vector2 & r)
{
	return (l * r) / (l.mode() * r.mode());
}

double vecsin(const Vector2 & l, const Vector2 & r)
{
	double c = veccos(l, r);
	return sqrt(1 - c * c);
}

double vectan(const Vector2 & l, const Vector2 & r)
{
	return vecsin(l, r) / veccos(l, r);
}

VecPair split(const Vector2 & obj, const VecPair & base)
{
	double c1 = obj.x;
	double c2 = obj.y;
	double a1 = base.first.x;
	double a2 = base.first.y;
	double b1 = base.second.x;
	double b2 = base.second.y;
	//(c1, c2) = x(a1, a2) + y(b1, b2)
	double x = (c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2);
	double y = (a1 * c2 - a2 * c1) / (a1 * b2 - b1 * a2);
	return VecPair(x * base.first, y * base.second);
}

Vector2 Vector2::cross() const
{
	if (x == 0)
		return Vector2(0, 1);
	if (y == 0)
		return Vector2(1, 0);
	return Vector2(1 / x, -1 / y);
}