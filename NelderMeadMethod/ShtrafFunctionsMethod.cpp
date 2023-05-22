#include "ShtrafFunctionsMethod.h"
#include <iostream>
#include <algorithm>
#include <iomanip>


vector<Point> ShtrafFunctionsMethod::FindMinShtraf(int MaxOrMin)
{
	int ksh = 1;
	kolvofun = 0;
	vector<Point> point;
	vector<Point> point2;

	point.resize(config::n + 1);
	r = config::configr;

	point = DefinePoint0();

	point[0].f = DefinePoints::fsh(point[0], kolvofun, r);
	point[1].f = DefinePoints::fsh(point[1], kolvofun, r);
	point[2].f = DefinePoints::fsh(point[2], kolvofun, r);

	point = DefinePoints::DefPoints(point, MaxOrMin);

	point2 = point;

	point = FindMinPoint(MaxOrMin, point);

	while (StopCondition(point[0]) == 0)
	{
		//point[1] = point2[1];
		//point[2] = point2[2];
		cout << "\n \n \n ================= \n \n \n";
		//r = pow(r - 1,3);																		//!!!!!!!!!!!!!
		r *= config::shtrafbetta;
		point = FindMinPoint(MaxOrMin, point);
		ksh += 1;
	}
	cout << "(" << setprecision(10) << point[0].x << ", " << setprecision(10) << point[0].y << ") func: " << setprecision(10) << point[0].f << " k shtraf: " << ksh << endl;
	cout << " kolvofun: " << kolvofun << endl;
	exit(0);
}

bool ShtrafFunctionsMethod::StopCondition(Point point)
{
	//if (abs(DefinePoints::bf1(point, r)) <= config::ShtrafEps)
	if (abs(DefinePoints::bf2(point, r)) <= config::ShtrafEps)
	//if (abs(DefinePoints::H(point, r)) <= config::ShtrafEps)
	//if (abs(DefinePoints::GH(point, r)) <= config::ShtrafEps)									/////////////////!!!!!!!!!!!!!!!!!!
	//if (abs(DefinePoints::G(point,r)) <= config::ShtrafEps)
		return 1;
	return 0;
}


//#ifdef SECOND
//
//bool ShtrafFunctionsMethod::StopCondition(Point point, double r)
//{
//	double  u = r * DefinePoints::bc2(point);
//	if (abs(DefinePoints::bc2(point)) < config::ShtrafEps)
//		return 1;
//	return 0;
//}
//
//double ShtrafFunctionsMethod::P(Point point, double r)
//{
//	return DefinePoints::fun(point) + r * max(abs(DefinePoints::bc2(point)), (double)0) * max(abs(DefinePoints::bc2(point)), (double)0);
//}
//#endif


vector<Point> ShtrafFunctionsMethod::FindMinPoint(int MaxOrMin, vector<Point> point)
{
	point[0].f = DefinePoints::fsh(point[0], kolvofun, r);
	point[1].f = DefinePoints::fsh(point[1], kolvofun, r);
	point[2].f = DefinePoints::fsh(point[2], kolvofun, r);
	int k = 0;
	int l = 0;
	while (k < 100)
	{
		//Operations::test(point);
		for (int i = 0; i < 3; i++)
		{
			if (DefinePoints::g(point[i]) > 0)
			{
				return point;
			}
		}

		point = DefinePoints::DefPoints(point, MaxOrMin);
		Point x_gc = Operations::CG(point); //точка равная центру тяжести
		x_gc.f = DefinePoints::fsh(x_gc, kolvofun, r);

		if (Operations::CalcDelta(point, x_gc) <= config::Eps)
		{
			//cout << "x: " << point[0].x << " y: " << point[0].y << " func: " << point[0].f << " k: " << k << endl;
			//cout << sqrt((point[0].x * point[0].x) + (point[0].y * point[0].y)) << endl; //!!!!!!!!!!!!!!!!
			return point;
		}

		Point x_reflect = Operations::Reflection(x_gc, point[2]); // отраженная точка
		x_reflect.f = DefinePoints::fsh(x_reflect, kolvofun, r);

		if (MaxOrMin)
		{
			if (x_reflect.f >= point[0].f)
			{
				Point x_stretch = Operations::Stretching(x_gc, x_reflect);
				x_stretch.f = DefinePoints::fsh(x_stretch, kolvofun, r);
				if (x_stretch.f > point[0].f)
				{
					point[2] = x_stretch; // точка растяжения
					k++;
					continue;
					// перейти к след итерации
				}
				else
				{
					point[2] = x_reflect;
					k++;
					continue;
					// перейти к след итерации
				}
			}
			else if ((point[1].f > x_reflect.f) && (x_reflect.f >= point[2].f))
			{
				point[2] = Operations::Сompression(x_gc, point[2]); // точка сжатия
				point[2].f = DefinePoints::fsh(point[2], kolvofun, r);
				k++;
				continue;
				// перейти к след итерации
			}
			else if ((point[0].f > x_reflect.f) && (x_reflect.f >= point[1].f))
			{
				point[2] = x_reflect;
				k++;
				continue;
				// перейти к след итерации
			}
			else if (point[2].f > x_reflect.f)
			{
				point = Operations::Reduction(point); // треугольник в 2 раза меньше
				point[1].f = DefinePoints::fsh(point[1], kolvofun, r);
				point[2].f = DefinePoints::fsh(point[2], kolvofun, r);
				k++;
				continue;
				// перейти к след итерации
			}
		}
		else
		{
			if (x_reflect.f <= point[0].f)
			{
				Point x_stretch = Operations::Stretching(x_gc, x_reflect);
				x_stretch.f = DefinePoints::fsh(x_stretch, kolvofun, r);
				if (x_stretch.f > point[0].f)
				{
					point[2] = x_stretch; // точка растяжения
					k++;
					continue;
					// перейти к след итерации
				}
				else
				{
					point[2] = x_reflect;
					k++;
					continue;
					// перейти к след итерации
				}
			}
			else if ((point[1].f < x_reflect.f) && (x_reflect.f <= point[2].f))
			{
				point[2] = Operations::Сompression(x_gc, point[2]); // точка сжатия
				point[2].f = DefinePoints::fsh(point[2], kolvofun, r);
				k++;
				continue;
				// перейти к след итерации
			}
			else if ((point[0].f < x_reflect.f) && (x_reflect.f <= point[1].f))
			{
				point[2] = x_reflect;
				k++;
				continue;
				// перейти к след итерации
			}
			else if (point[2].f < x_reflect.f)
			{
				point = Operations::Reduction(point); // треугольник в 2 раза меньше
				point[1].f = DefinePoints::fsh(point[1], kolvofun, r);
				point[2].f = DefinePoints::fsh(point[2], kolvofun, r);
				k++;
				continue;
				// перейти к след итерации
			}
		}
		k++;
		l++;
		if (l > 2)
		{
			return point;
		}
	}
	return point;
}



vector<Point> ShtrafFunctionsMethod::DefinePoint0()
{
	vector<Point> point0;
	//point0.push_back({ -1, -1 });
	//point0.push_back({ 5, 3 });
	//point0.push_back({ 0, 6 });

	//point0.push_back({ 0.5, 0 });
	//point0.push_back({ 0, 0.5 });
	//point0.push_back({ 1, 0.5 });

	//point0.push_back({ 1.5 , 2 });
	//point0.push_back({ 2, 1.5 }); // 2 лаба
	//point0.push_back({ 2, 2 });

	//point0.push_back({ 2, -2 });
	//point0.push_back({ -2, -2 }); // 2 лаба
	//point0.push_back({ 2, 2 });

	//point0.push_back({ 2.1, 2.1 });
	//point0.push_back({ -2, -2 }); // 2 лабаsdgfsf sdfgs f
	//point0.push_back({ 2, 2 });

	//point0.push_back({ 3, 3 });
	//point0.push_back({ 3.1, 3.1 }); // 2 лаба
	//point0.push_back({ 3, 3.2 });

	//point0.push_back({ -1, 1 });
	//point0.push_back({ 1, -1 }); // 2 лаба
	//point0.push_back({ 2, 1 });

	//point0.push_back({ -1, 2 });
	//point0.push_back({ 0, 0 }); // 2 лаба
	//point0.push_back({ 2, -1 });

	//point0.push_back({ 1, 10 });
	//point0.push_back({ 2, 0 }); // 2 лаба
	//point0.push_back({ 0, 0 });

	point0.push_back({ -5, 5 });
	point0.push_back({ -6, 5 }); // 3 лаба
	point0.push_back({ -5, 6 });

	//point0.push_back({ -10, 10 });
	//point0.push_back({ -11, 10 }); // 3 лаба
	//point0.push_back({ -10, 11 });

	//point0.push_back({ -40, 40 });
	//point0.push_back({ -50, 40 }); // 3 лаба
	//point0.push_back({ -40, 50 });

	//point0.push_back({ -4, 6 });
	//point0.push_back({ -3, 6 }); // 3 лаба
	//point0.push_back({ -4, 5 });

	//point0.push_back({ 0, 0 });
	//point0.push_back({ -1, 0 }); // 3 лаба
	//point0.push_back({ 0, -1 });

	return point0;
}
