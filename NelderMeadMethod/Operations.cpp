#include "Operations.h"
#include <iostream>
#include <iomanip>

Point Operations::CG(vector<Point> x)
{
	double bufx, bufy;
	Point newPoint;
	//for (int i = 0; i < config::n; i++)
	//{
	//	bufx = x[0].x + x[1].x;
	//	bufy = x[0].y + x[1].y;
	//}
	//newPoint.x = (bufx) / config::n;
	//newPoint.y = (bufy) / config::n;

	newPoint.x = (x[0].x + x[1].x) / config::n;
	newPoint.y = (x[0].y + x[1].y) / config::n;

	return newPoint;
}

double Operations::CalcDelta(vector<Point> x, Point x_gc)
{
	double buf = 0; 
	for (int i = 0; i < config::n + 1; i++)
	{
		buf += (x[i].f - x_gc.f) * (x[i].f - x_gc.f);
	}
	buf /= config::n + 1;
	
	return sqrt(buf);
}

Point Operations::Reflection(Point x_gc, Point x_h)
{
	Point newPoint;
	newPoint.x = x_gc.x + config::alpha * (x_gc.x - x_h.x);
	newPoint.y = x_gc.y + config::alpha * (x_gc.y - x_h.y);
	return newPoint;
}

Point Operations::Stretching(Point x_gc, Point x_reflect)
{
	Point newPoint;
	newPoint.x = x_gc.x + config::gamma * (x_reflect.x - x_gc.x);
	newPoint.y = x_gc.y + config::gamma * (x_reflect.y - x_gc.y);
	return newPoint;
}

Point Operations::Ñompression(Point x_gc, Point x_h)
{
	Point newPoint;
	newPoint.x = x_gc.x + config::betta * (x_h.x - x_gc.x);
	newPoint.y = x_gc.y + config::betta * (x_h.y - x_gc.y);
	return newPoint;
}

vector<Point> Operations::Reduction(vector<Point> x)
{
	for (int i = 1; i <= 2; i++)
	{
		x[i].x = x[0].x + 0.5 * (x[i].x - x[0].x);
		x[i].y = x[0].y + 0.5 * (x[i].y - x[0].y);
	}

	return x;
}

void Operations::test(vector<Point> x)
{
	for (int i = 0; i <= 2; i++)
	{
		cout << x[i].x << " " << x[i].y << "   ";
	}
	cout << endl << setprecision(10) << x[0].f << " " << setprecision(10) << x[1].f << " " << setprecision(10) << x[2].f << " " << endl << endl;

}