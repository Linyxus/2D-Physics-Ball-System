#pragma once

#include <cmath>
#include <utility>
using namespace std;

class Vector2;
typedef pair<Vector2, Vector2> VecPair;
Vector2 operator+(const Vector2 &, const Vector2 &);
Vector2 operator-(const Vector2 &);
Vector2 operator-(const Vector2 &, const Vector2 &);
Vector2 operator*(double, const Vector2 &);
Vector2 operator*(const Vector2 &, double);
double operator*(const Vector2 &, const Vector2 &);
bool operator==(const Vector2 &, const Vector2 &);
double veccos(const Vector2 &, const Vector2 &);
double vecsin(const Vector2 &, const Vector2 &);
double vectan(const Vector2 &, const Vector2 &);
VecPair split(const Vector2 &, const VecPair &);
Vector2 vectorByMode(const Vector2 &, double);

class Vector2
{
public:
	Vector2() {}
	Vector2(double, double);
	double x, y;
	double mode() const;
	Vector2 cross() const;
};