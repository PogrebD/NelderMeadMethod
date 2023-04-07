#include <iostream>
#include "config.h"
#include <algorithm>
#include "DefinePoints.h"
#include "Operations.h"

using namespace std;


int main()
{
	vector<Point> x0, x; // начальный симплекс
	vector<double> f0;
	//x0.push_back({ -1, -1 });
	//x0.push_back({ 5, 3 });
	//x0.push_back({ 0, 6 });

	x0.push_back({ 0.5, 0 });
	x0.push_back({ 0, 0.5 });
	x0.push_back({ 1, 0.5 });

	//x0.push_back({ 1, 1 });
	//x0.push_back({ 5, 3 }); // интересный тест
	//x0.push_back({ 0, 6 });

	x.resize(config::n + 1);


	x = DefinePoints::DefPoints(x0);
	//x[0] = DefinePoints::maxPoint(x0); //  наилучшая точка
	//x[1] = DefinePoints::midPoint(x0); //  средняя точка
	//x[2] = DefinePoints::minPoint(x0); //  наихудшая точка

	int k = 0;
	while (k < 100)
	{
		Operations::test(x);
		x = DefinePoints::DefPoints(x);

		Point x_gc = Operations::CG(x); //точка равная центру тяжести
		double f = Operations::CalcDelta(x, x_gc);
		if (Operations::CalcDelta(x, x_gc) <= config::Eps)
		{
			cout << "x: " << x[0].x << " y: " << x[0].y << " func: " << DefinePoints::fun(x[0]) << " k: " << k << endl;
			cout << sqrt((x[0].x * x[0].x) + (x[0].y * x[0].y));
			exit(0);
		}

		Point x_reflect = Operations::Reflection(x_gc, x[2]); // отраженная точка

		if (DefinePoints::fun(x_reflect) >= DefinePoints::fun(x[0]))
		{
			Point x_stretch = Operations::Stretching(x_gc, x_reflect);
			if (DefinePoints::fun(x_stretch) > DefinePoints::fun(x[0]))
			{
				x[2] = x_stretch; // точка растяжения
				k++;
				continue;
				// перейти к след итерации
			}
			else
			{
				x[2] = x_reflect;
				k++;
				continue;
				// перейти к след итерации
			}
		}
		else if ((DefinePoints::fun(x[1]) > DefinePoints::fun(x_reflect)) && (DefinePoints::fun(x_reflect) >= DefinePoints::fun(x[2])))
		{
			x[2] = Operations::Сompression(x_gc, x[2]); // точка сжатия
			k++;
			continue;
			// перейти к след итерации
		}
		else if ((DefinePoints::fun(x[0]) > DefinePoints::fun(x_reflect)) && (DefinePoints::fun(x_reflect) >= DefinePoints::fun(x[1])))
		{
			x[2] = x_reflect;
			k++;
			continue;
			// перейти к след итерации
		}
		else if (DefinePoints::fun(x[2]) > DefinePoints::fun(x_reflect))
		{
			x = Operations::Reduction(x); // треугольник в 2 раза меньше
			k++;
			continue;
			// перейти к след итерации
		}
	}
	cout << "x: " << x[0].x << " y: " << x[0].y << " func: " << DefinePoints::fun(x[0]) << " k: " << k << endl;
	cout << sqrt((x[0].x * x[0].x) + (x[0].y * x[0].y));
}
