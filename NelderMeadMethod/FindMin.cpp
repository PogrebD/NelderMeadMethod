#include "FindMin.h"

#include <iostream>

double FindMin::Find(int MaxOrMin, vector<Point> point0)
{
	int kolvoFun = 0;
	point0[0].f = DefinePoints::fun(point0[0], kolvoFun);
	point0[1].f = DefinePoints::fun(point0[1], kolvoFun);
	point0[2].f = DefinePoints::fun(point0[2], kolvoFun);

	point.resize(config::n + 1);

	point = DefinePoints::DefPoints(point0, MaxOrMin);
	//point[0] = DefinePoints::maxPoint(point0); //  наилучшая точка
	//point[1] = DefinePoints::midPoint(point0); //  средняя точка
	//point[2] = DefinePoints::minPoint(point0); //  наихудшая точка
	k = 0;
	while (k < 1000000)
	{
		point = DefinePoints::DefPoints(point, MaxOrMin);
		Operations::test(point);
		Point x_gc = Operations::CG(point); //точка равная центру тяжести
		x_gc.f = DefinePoints::fun(x_gc, kolvoFun);
		if (Operations::CalcDelta(point, x_gc) <= config::Eps)
		{
			cout << "(" << point[0].x << ", " << point[0].y << ") func: " << point[0].f << " k: " << k << endl;
			cout << sqrt((point[0].x * point[0].x) + (point[0].y * point[0].y));
			F0 = point[0].f;
			cout << " kolvofun: " << kolvoFun<< endl;
			exit(0);
		}

		Point x_reflect = Operations::Reflection(x_gc, point[2]); // отраженная точка
		x_reflect.f = DefinePoints::fun(x_reflect, kolvoFun);

		if (MaxOrMin)
		{
			if (x_reflect.f >= point[0].f)
			{
				Point x_stretch = Operations::Stretching(x_gc, x_reflect);
				x_stretch.f = DefinePoints::fun(x_stretch, kolvoFun);
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
				point[2].f = DefinePoints::fun(point[2], kolvoFun);
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
				point[1].f = DefinePoints::fun(point[1], kolvoFun);
				point[2].f = DefinePoints::fun(point[2], kolvoFun);
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
				x_stretch.f = DefinePoints::fun(x_stretch, kolvoFun);
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
				point[2].f = DefinePoints::fun(point[2], kolvoFun);
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
				point[1].f = DefinePoints::fun(point[1], kolvoFun);
				point[2].f = DefinePoints::fun(point[2], kolvoFun);
				k++;
				continue;
				// перейти к след итерации
			}
		}


	}
}

vector<Point> FindMin::DefinePoint0()
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

	point0.push_back({ -1, 2 });
	point0.push_back({ 0, 0 }); // 2 лаба
	point0.push_back({ 2, -1});

	//point0.push_back({ 1, 10 });
	//point0.push_back({ 2, 0 }); // 2 лаба
	//point0.push_back({ 0, 0 });

	//point0.push_back({ -9, 4 });
	//point0.push_back({ -7, 5 }); // 3 лаба
	//point0.push_back({ -10, 7 });

	return point0;
}