#include "DefinePoints.h"

double DefinePoints::fun(Point point)
{
	return -(2 * point.x * point.x + point.x * point.y + point.y * point.y);
	//return -((point.x+2) * (point.x +2)) - (point.y * point.y );
	//return (point.x) * (point.x);
	//return (point.x + point.y) * (point.x + point.y);
	//return (2 * exp(-(((point.x - 1) / 2) * ((point.x - 1) / 2)) - (((point.y - 1) / 2) * ((point.y - 1) / 2)))) + (3 * exp(-(((point.x - 1) / 3) * ((point.x - 1) / 3)) - (((point.y - 3) / 3) * ((point.y - 3) / 3))));
}

int DefinePoints::maxPoint(vector<Point> point)
{
	if ((fun(point[0]) > fun(point[1])) && (fun(point[0]) > fun(point[2])))
	{
		return 0;
	}
	else if (fun(point[1]) > fun(point[2]))
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int DefinePoints::minPoint(vector<Point> point)
{
	if ((fun(point[0]) < fun(point[1])) && (fun(point[0]) < fun(point[2])))
	{
		return 0;
	}
	else if (fun(point[1]) < fun(point[2]))
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int DefinePoints::midPoint(vector<Point> point)
{
	if ((fun(point[0]) > fun(point[1])) && (fun(point[0]) > fun(point[2])))
	{
		if (fun(point[1]) > fun(point[2]))
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if ((fun(point[0]) < fun(point[1])) && (fun(point[0]) < fun(point[2])))
	{
		if (fun(point[1]) > fun(point[2]))
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
vector<Point> DefinePoints::DefPoints(vector<Point> points)
{
	vector<Point> newVec;
	int max = DefinePoints::maxPoint(points);
	int min = DefinePoints::minPoint(points);

	int mid = DefinePoints::midPoint(points);
	if (mid == min)
	{
		for (int i = 0; i < 3; i++)
		{
			if ((i != min) && (i != min))
			{
				mid = i;
			}
		}
	}
	newVec.push_back(points[max]);
	newVec.push_back(points[max]);
	newVec.push_back(points[max]);
	return newVec;
}