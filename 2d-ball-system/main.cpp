#include <iostream>
#include "vector2.h"
#include "ball-system.h"
using namespace std;

ostream & operator<<(ostream & out, const Vector2 & obj)
{
	return out << "(" << obj.x << ", " << obj.y << ")";
}

int main()
{
	cout << "Wellcome to 2BS test center!" << endl;
	// #1 Vector Module Test
	// #1.1 Vector split
	Vector2 v1(-sqrt(3), -5);
	Vector2 v2(2, 1);
	Vector2 v(1, 10);
	cout << split(v, VecPair(v1, v2)).first << endl
		<< split(v, VecPair(v1, v2)).second << endl;
	// #1.2 vectorByMode
	v = Vector2(0.4, 0.3);
	cout << vectorByMode(v, 5) << endl;
	cin.get();

	return 0;
}