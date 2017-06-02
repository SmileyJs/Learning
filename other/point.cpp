#include <iostream>
#include "cmath"

using namespace std;

class Point
{
public:
	friend float calculate(const Point&, const Point&);

	Point(float i, float j) : x(i), y(j) {}
	
private:
	float x;
	float y;
};

float
calculate(const Point& a, const Point& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int
main(int argc, char const *argv[])
{
	Point a(1.0, 2.0);
	Point b(2.0, 3.0);

	cout << calculate(a, b) << endl;

	return 0;
}