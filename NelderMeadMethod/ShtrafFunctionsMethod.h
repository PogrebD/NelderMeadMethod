#pragma once
#include "FindMin.h"
class ShtrafFunctionsMethod
{
public:
	void test(vector<Point> x, double r);
	double CalcDelta(vector<Point> x, Point x_gc, double r);
	vector<Point> FindMinShtraf(int MaxOrMin);
	vector<Point> FindMinPoint(int MaxOrMin, vector<Point> point);
	double P(Point point, double r, int& kolvoFun);
	bool StopCondition(Point point);
	double r;
	vector<Point> result;
	int k;
	int minPoint(vector<Point> point, double r);
	int midPoint(vector<Point> point, double r);
	int maxPoint(vector<Point> point, double r);
	vector<Point> DefPoints(vector<Point> points, int MaxOrMin, double r);
	vector<Point> DefinePoint0();
	int kolvofun;
};

