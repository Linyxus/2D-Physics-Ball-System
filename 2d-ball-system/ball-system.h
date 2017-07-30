#pragma once

#include "vector2.h"
#include <vector>
using namespace std;

struct Position;
struct Ball;
struct ForceField;
class BallSystem;
bool hitted(const Ball &, const Ball &);
vector<vector<int>> hitted(const vector<Ball> &);
Vector2 calculateForce(const ForceField &, const Ball &);
Vector2 calculateForces(const vector<ForceField> &, const Ball &);

Vector2 operator-(const Position &, const Position &);
struct Position
{
	double x, y;
};

struct Ball
{
	Position pos;
	double r;
	double m;
	Vector2 v;
};

struct ForceField
{
	Position source;
	double strength;
};

class BallSystem
{
public:
	BallSystem();
	void update(double duration, double timeAtom);
	void calculate(double timeAtom);
	Vector2 getHitOffset(const Ball &, const Ball &);
private:
	vector<Ball> balls;
	vector<ForceField> forces;
};