#include "DefinePoints.h"

double DefinePoints::fun(Point point, int& kolvoFun)
{
	kolvoFun += 1;
	//return -(2 * point.x * point.x + point.x * point.y + point.y * point.y);
	//return -((point.x+2) * (point.x +2)) - (point.y * point.y );
	//return (point.x) * (point.x);
	//return (point.x + point.y) * (point.x + point.y);
	//return (point.x * point.x) - (point.x * point.y) + (point.y * point.y) + 9 * point.x - 6 * point.y + 20;
	/*2 лаба*/    //return (2 * exp(-(((point.x - 3) / 1) * ((point.x - 3) / 1)) - (((point.y - 2) / 1) * ((point.y - 2) / 1)))) + (3 * exp(-(((point.x - 1) / 1) * ((point.x - 1) / 1)) - (((point.y - 1) / 3) * ((point.y - 1) / 3))));
	//return 100 * (point.y - point.x) * (point.y - point.x) + (1 - point.x) * (1 - point.x);
	//return 100 * (point.y - point.x * point.x) * (point.y - point.x * point.x) + (1 - point.x) * (1 - point.x);


	/*3 лаба*/    return 4 * (point.x + point.y) * (point.x + point.y) + point.x * point.x;


	//return 5 * pow(point.x - point.y, 2) + pow(point.x - 2, 2);
}

double DefinePoints::fsh(Point point, int& kolvoFun, double r)
{
	//return fun(point, kolvoFun) + GH(point, r);
	//return fun(point, kolvoFun) + G(point,r);										///////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//return fun(point, kolvoFun) + H(point,r);
	//return fun(point, kolvoFun) + bf1(point, r);
	return fun(point, kolvoFun) + bf2(point, r);
}

double DefinePoints::g(Point point)
{
	return 5 - point.y + point.x;

	//return point.x + point.y - 1;
}

double DefinePoints::h(Point point)
{
	return  point.y + point.x - 2;

	//return point.x + point.y;
}

double DefinePoints::G(Point point, double r)
{
	return r * pow(0.5 * (g(point) + abs(g(point))), 1);
}

double DefinePoints::H(Point point, double r)
{
	return r * pow(abs(h(point)), 2);
}

double DefinePoints::GH(Point point, double r)
{
	return G(point, r) + H(point, r);
}

//double DefinePoints::Gb1(Point point, double r)
//{
//	return G(point, r) + H(point, r);
//}
//
//double DefinePoints::Gb2(Point point, double r)
//{
//	return G(point, r) + H(point, r);
//}

double DefinePoints::bf1(Point point, double r)
{
	return  -1 * r * (1 / g(point));
}

double DefinePoints::bf2(Point point, double r)
{
	return  -1 * r * log(-1*g(point));
}

//double DefinePoints::ShtrafFun1(Point point)
//{
//	return 1 / bc(point);
//}
//
//double DefinePoints::ShtrafFun2(Point point)
//{
//	return -log(bc(point));
//}

int DefinePoints::maxPoint(vector<Point> point)
{
	if ((point[0].f > point[1].f) && (point[0].f > point[2].f))
	{
		return 0;
	}
	else if (point[1].f > point[2].f)
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
	if ((point[0].f < point[1].f) && (point[0].f < point[2].f))
	{
		return 0;
	}
	else if (point[1].f < point[2].f)
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
	if ((point[0].f > point[1].f) && (point[0].f > point[2].f))
	{
		if (point[1].f > point[2].f)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if ((point[0].f < point[1].f) && (point[0].f < point[2].f))
	{
		if (point[1].f > point[2].f)
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
vector<Point> DefinePoints::DefPoints(vector<Point> points, int MaxOrMin)
{
	vector<Point> newVec;

	int max = DefinePoints::maxPoint(points);
	int min = DefinePoints::minPoint(points);

	int mid = DefinePoints::midPoint(points);
	if ((mid == min) || (mid == max))
	{
		for (int i = 0; i < 3; i++)
		{
			if ((i != min) && (i != min))
			{
				mid = i;
			}
		}
	}

	if (MaxOrMin == 1)
	{
		newVec.push_back(points[max]);
		newVec.push_back(points[mid]); // Для поиска максимума
		newVec.push_back(points[min]);
	}
	else
	{
		newVec.push_back(points[min]);
		newVec.push_back(points[mid]); // Для поиска минимума
		newVec.push_back(points[max]);
	}

	return newVec;
}