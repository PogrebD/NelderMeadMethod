#pragma once
#include <vector>
#include "config.h"
#include "DefinePoints.h"

using namespace std;

class Operations
{
public:
	static Point CG(vector<Point> x);
	static double CalcDelta(vector<Point> x, Point x_gc);
	static Point Reflection(Point x_gc, Point x_h);
	static Point Stretching(Point x_gc, Point x_reflect);
	static Point Ñompression(Point x_gc, Point x_h);
	static vector<Point> Reduction(vector<Point> x);
	static void test(vector<Point> x);
};

