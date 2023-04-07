#pragma once
#include <vector>
#include "config.h"

using namespace std;

struct Point {
	double x, y;
};

class DefinePoints
{
public:
	static int maxPoint(vector<Point> point);
	static int minPoint(vector<Point> point);
	static int midPoint(vector<Point> point);
	static double fun(Point point);
	static vector<Point> DefPoints(vector<Point> points);
};

