#include "ball-system.h"

//Tools

bool hitted(const Ball & a, const Ball & b)
{
	Vector2 vec(a.pos.x - b.pos.x, a.pos.y - b.pos.y);
	return vec.mode() <= (a.r + b.r);
}

vector<vector<int>> hitted(const vector<Ball> & balls)
{
	vector<vector<int>> res;
	for (int i = 0; i < balls.size(); i++)
		res.push_back(vector<int>());
	for (int i = 0; i < balls.size(); i++) {
		for (int j = i + 1; j < balls.size(); j++) {
			if (hitted(balls[i], balls[j])) {
				res[i].push_back(j);
				res[j].push_back(i);
			}
		}
	}
	return res;
}

Vector2 calculateForce(const ForceField & ff, const Ball & obj)
{
	Vector2 vec = ff.source - obj.pos;
	double dist = vec.mode();
	double f = obj.m * ff.strength / dist;
	return vectorByMode(vec, f);
}

Vector2 calculateForces(const vector<ForceField> & ff, const Ball & obj)
{
	Vector2 force(0, 0);
	for (int i = 0; i < ff.size(); i++)
		force = force + calculateForce(ff[i], obj);
	return force;
}

//Position

Vector2 operator-(const Position & p1, const Position & p2)
{
	Vector2 vec(p1.x - p2.x, p1.y - p2.y);
	return vec;
}

//Ball System

BallSystem::BallSystem()
{

}

void BallSystem::update(double duration, double timeAtom)
{

}

void BallSystem::calculate(double timeAtom)
{
	
}

Vector2 BallSystem::getHitOffset(const Ball & obj, const Ball & hit)
{
	
}
