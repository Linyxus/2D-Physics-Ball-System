#pragma once

#include <cmath>

class Vector2;
Vector2 operator+(const Vector2 &, const Vector2 &);
Vector2 operator-(const Vector2 &);
Vector2 operator-(const Vector2 &, const Vector2 &);
Vector2 operator*(double, const Vector2 &);
Vector2 operator*(const Vector2 &, double);
double operator*(const Vector2 &, const Vector2 &);
bool operator==(const Vector2 &, const Vector2 &);

class Vector2
{
public:
	Vector2() {}
	Vector2(double, double);
	double x, y;
	double mode() const;
};