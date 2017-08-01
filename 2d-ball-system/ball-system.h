#pragma once

#include "vector2.h"
#include <vector>
using namespace std;

struct Position;
struct Ball;
struct ForceField;
class BallSystem;
bool hitted(const Ball &, const Ball &);
vector<vector<int>> hitted_old(const vector<Ball> &);
vector<pair<int, int>> hitted(const vector<Ball> &);
Vector2 calculateForce(const ForceField &, const Ball &);
Vector2 calculateForces(const vector<ForceField> &, const Ball &);

Vector2 operator-(const Position &, const Position &);
Position operator+(const Position &, const Vector2 &);
Position operator+(const Vector2 &, const Position &);
struct Position
{
	double x, y;
};

struct ForceField
{
	Position source;
	double strength;
};

typedef pair<Ball, Ball> BallPair;
struct Ball
{
	Position pos;
	double r;
	double m;
	Vector2 v;
	ForceField bindedForce;
};

class BallSystem
{
public:
	BallSystem();
	void update(double duration, double timeAtom);
	void calculate(double timeAtom);
	VecPair getHitOffset(const BallPair &);
	void handleHit(double);
	void handleMove(double);
private:
	vector<Ball> balls;
	vector<ForceField> additional_forces;
};