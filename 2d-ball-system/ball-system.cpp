#include "ball-system.h"

//Tools

bool hitted(const Ball & a, const Ball & b)
{
	Vector2 vec(a.pos.x - b.pos.x, a.pos.y - b.pos.y);
	return vec.mode() <= (a.r + b.r);
}

vector<pair<int, int>> hitted(const vector<Ball> & balls)
{
	vector<pair<int, int>> res;
	for (int i = 0; i < balls.size(); i++) {
		for (int j = i + 1; j < balls.size(); j++) {
			if (hitted(balls[i], balls[j])) {
				res.push_back(make_pair(i, j));
			}
		}
	}
	return res;
}

vector<vector<int>> hitted_old(const vector<Ball> & balls)
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

Position operator+(const Position & pos, const Vector2 & vec)
{
	Position res;
	res.x = pos.x + vec.x;
	res.y = pos.y + vec.y;
	return res;
}

Position operator+(const Vector2 & vec, const Position & pos)
{
	return pos + vec;
}

//Ball System

BallSystem::BallSystem()
{

}

void BallSystem::update(double duration, double timeAtom)
{
	int cnt = (int)(duration / timeAtom);
	for (int i = 0; i < cnt; i++)
		this->calculate(timeAtom);
	this->calculate(duration - timeAtom * cnt);
}

void BallSystem::calculate(double timeAtom)
{
	handleMove(timeAtom);
	handleHit(timeAtom);
}

VecPair BallSystem::getHitOffset(const BallPair & balls)
{
	Vector2 line = balls.first.pos - balls.second.pos;
	Vector2 norm = line.cross();
	Vector2 v1 = split(balls.first.v, VecPair(line, norm)).first;
	Vector2 v2 = split(balls.second.v, VecPair(line, norm)).first;
	double vv1_m = ((balls.first.m - balls.second.m) * v1.mode() + 2 * balls.second.m * v2.mode()) / (balls.first.m + balls.second.m);
	double vv2_m = ((balls.second.m - balls.first.m) * v2.mode() + 2 * balls.first.m * v1.mode()) / (balls.first.m + balls.second.m);
	Vector2 vv1 = vectorByMode(-v1, vv1_m);
	Vector2 vv2 = vectorByMode(-v2, vv2_m);
	return VecPair(vv1 - v1, vv2 - v2);
}

void BallSystem::handleHit(double timeAtom)
{
	//unused variable: timeAtom(double)
	vector<Vector2> offsets;
	for (int i = 0; i < this->balls.size(); i++) {
		offsets.push_back(Vector2(0, 0));
	}
	vector<pair<int, int>> hits = hitted(this->balls);
	for (int i = 0; i < hits.size(); i++) {
		VecPair off = getHitOffset(make_pair(this->balls[hits[i].first], this->balls[hits[i].second]));
		offsets[hits[i].first] = offsets[hits[i].first] + off.first;
		offsets[hits[i].second] = offsets[hits[i].second] + off.second;
	}
	for (int i = 0; i < this->balls.size(); i++) {
		this->balls[i].v = this->balls[i].v + offsets[i];
	}
}

void BallSystem::handleMove(double timeAtom)
{
	for (int i = 0; i < this->balls.size(); i++) {
		Vector2 f(0, 0);
		for (int x = 0; x < this->balls.size(); x++) {
			if (x == i) continue;
			f = f + calculateForce(this->balls[x].bindedForce, this->balls[i]);
		}
		f = f + calculateForces(this->additional_forces, this->balls[i]);
		Vector2 x = f * timeAtom;
		this->balls[i].pos = this->balls[i].pos + x;
	}
}
