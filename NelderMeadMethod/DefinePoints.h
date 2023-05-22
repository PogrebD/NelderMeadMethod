#pragma once
#include <vector>
#include "config.h"

using namespace std;

struct Point {
	double x, y, f;
};

class DefinePoints
{
public:
	static int maxPoint(vector<Point> point);
	static int minPoint(vector<Point> point);
	static int midPoint(vector<Point> point);
	static double fun(Point point, int& kolvoFun);
	static double fsh(Point point, int& kolvoFun, double r);
	static double g(Point point);
	static double h(Point point);
	static double G(Point point, double r);
	static double H(Point point, double r);
	static double bf1(Point point, double r);
	static double bf2(Point point, double r);
	static double GH(Point point, double r);
	static vector<Point> DefPoints(vector<Point> points, int MaxOrMin);
};

