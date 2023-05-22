#pragma once
#include "FindMin.h"
class BarrierFunctionsMethod
{
public:
	void test(vector<Point> x, double r);
	double CalcDelta(vector<Point> x, Point x_gc, double r);
	FindMin FindMinBarrier(int MaxOrMin);
	FindMin FindMinPoint(int MaxOrMin, FindMin MinPoint, double r);
	double P(Point point, double r);
	bool StopCondition(Point point, double r);
	double r;
	vector<Point> result;
	int k;
	int minPoint(vector<Point> point, double r);
	int midPoint(vector<Point> point, double r);
	int maxPoint(vector<Point> point, double r);
	vector<Point> DefPoints(vector<Point> points, int MaxOrMin, double r);
};

