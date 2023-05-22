#pragma once
#include "config.h"
#include "Operations.h"
#include "DefinePoints.h"

class FindMin
{
public:
	double Find(int MaxOrMin, vector<Point> point0);
	vector<Point> DefinePoint0 ();
	vector<Point> point;
	vector<double> f0;
	int k = 0;
	double F0;
};

