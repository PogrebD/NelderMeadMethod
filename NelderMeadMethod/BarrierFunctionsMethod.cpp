#include "BarrierFunctionsMethod.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

//FindMin BarrierFunctionsMethod::FindMinBarrier(int MaxOrMin)
//{
//	FindMin MinPoints2;
//	FindMin MinPoints;
//	Point resultPoint;
//
//	MinPoints.point.resize(config::n + 1);
//	r = config::configr;
//	MinPoints.point = DefPoints(MinPoints.DefinePoint0(), MaxOrMin, r);
//	MinPoints2 = MinPoints;
//	if (DefinePoints::bc1(MinPoints.point[0]) > 0)
//	{
//		cout << "Точка 0 не подходит по условию задачи" << endl;
//		exit(0);
//	}
//	if (DefinePoints::bc1(MinPoints.point[1]) > 0)
//	{
//		cout << "Точка 1 не подходит по условию задачи" << endl;
//		exit(0);
//	}
//	if (DefinePoints::bc1(MinPoints.point[2]) > 0)
//	{
//		cout << "Точка 2 не подходит по условию задачи" << endl;
//		exit(0);
//	}
//	MinPoints = FindMinPoint(MaxOrMin, MinPoints, r);
//	while (StopCondition(MinPoints.point[0], r) == 0)
//	{
//		MinPoints.point[1] = MinPoints2.point[1];
//		MinPoints.point[2] = MinPoints2.point[2];
//		cout << "\n \n \n ================= \n \n \n";
//		r *= config::barrierbetta;
//		MinPoints = FindMinPoint(MaxOrMin, MinPoints, r);
//	}
//	return MinPoints;
//}
//
//bool BarrierFunctionsMethod::StopCondition(Point point, double r)
//{
//	double  u = DefinePoints::bf1(point,r);
//	if (abs(u) < config::barrierEps)
//		return 1;
//	return 0;
//}
//
//double BarrierFunctionsMethod::P(Point point, double r)
//{
//	return DefinePoints::fun(point) + DefinePoints::bf1(point, r);
//}
//
//FindMin BarrierFunctionsMethod::FindMinPoint(int MaxOrMin, FindMin MinPoint, double r)
//{
//	FindMin MinPoint0;
//	int k = 0;
//	while (k < 100)
//	{
//		if ((DefinePoints::bc1(MinPoint.point[0]) > 0) || (DefinePoints::bc1(MinPoint.point[1]) > 0) || (DefinePoints::bc1(MinPoint.point[2]) > 0))
//		{
//			cout << "Точка не подходит по условию задачи" << endl;
//			MinPoint.point = DefPoints(MinPoint.point, MaxOrMin, r);
//			MinPoint0.point[0] = MinPoint.point[1];
//			return MinPoint0;
//		}
//		MinPoint0 = MinPoint;
//		test(MinPoint.point, r);
//		MinPoint.point = DefPoints(MinPoint.point, MaxOrMin, r);
//
//		Point x_gc = Operations::CG(MinPoint.point); //точка равная центру тяжести
//		double f = CalcDelta(MinPoint.point, x_gc, r);
//		if (CalcDelta(MinPoint.point, x_gc, r) <= config::Eps)
//		{
//			cout << "x: " << MinPoint.point[0].x << " y: " << MinPoint.point[0].y << " func: " << P(MinPoint.point[0], r) << " k: " << k << endl;
//			cout << sqrt((MinPoint.point[0].x * MinPoint.point[0].x) + (MinPoint.point[0].y * MinPoint.point[0].y)) << endl;
//			return MinPoint;
//		}
//
//		Point x_reflect = Operations::Reflection(x_gc, MinPoint.point[2]); // отраженная точка
//
//		if (MaxOrMin)
//		{
//			if (P(x_reflect, r) >= P(MinPoint.point[0], r))
//			{
//				Point x_stretch = Operations::Stretching(x_gc, x_reflect);
//				if (P(x_stretch, r) > P(MinPoint.point[0], r))
//				{
//					MinPoint.point[2] = x_stretch; // точка растяжения
//					k++;
//					continue;
//					// перейти к след итерации
//				}
//				else
//				{
//					MinPoint.point[2] = x_reflect;
//					k++;
//					continue;
//					// перейти к след итерации
//				}
//			}
//			else if ((P(MinPoint.point[1], r) > P(x_reflect, r)) && (P(x_reflect, r) >= P(MinPoint.point[2], r)))
//			{
//				MinPoint.point[2] = Operations::Сompression(x_gc, MinPoint.point[2]); // точка сжатия
//				k++;
//				continue;
//				// перейти к след итерации
//			}
//			else if ((P(MinPoint.point[0], r) > P(x_reflect, r)) && (P(x_reflect, r) >= P(MinPoint.point[1], r)))
//			{
//				MinPoint.point[2] = x_reflect;
//				k++;
//				continue;
//				// перейти к след итерации
//			}
//			else if (P(MinPoint.point[2], r) > P(x_reflect, r))
//			{
//				MinPoint.point = Operations::Reduction(MinPoint.point); // треугольник в 2 раза меньше
//				k++;
//				continue;
//				// перейти к след итерации
//			}
//		}
//		else
//		{
//			if (P(x_reflect, r) <= P(MinPoint.point[0], r))
//			{
//				Point x_stretch = Operations::Stretching(x_gc, x_reflect);
//				if (P(x_stretch, r) < P(MinPoint.point[0], r))
//				{
//					MinPoint.point[2] = x_stretch; // точка растяжения
//					k++;
//					continue;
//					// перейти к след итерации
//				}
//				else
//				{
//					MinPoint.point[2] = x_reflect;
//					k++;
//					continue;
//					// перейти к след итерации
//				}
//			}
//			else if ((P(MinPoint.point[1], r) < P(x_reflect, r)) && (P(x_reflect, r) <= P(MinPoint.point[2], r)))
//			{
//				MinPoint.point[2] = Operations::Сompression(x_gc, MinPoint.point[2]); // точка сжатия
//				k++;
//				continue;
//				// перейти к след итерации
//			}
//			else if ((P(MinPoint.point[0], r) < P(x_reflect, r)) && (P(x_reflect, r) <= P(MinPoint.point[1], r)))
//			{
//				MinPoint.point[2] = x_reflect;
//				k++;
//				continue;
//				// перейти к след итерации
//			}
//			else if (P(MinPoint.point[2], r) < P(x_reflect, r))
//			{
//				MinPoint.point = Operations::Reduction(MinPoint.point); // треугольник в 2 раза меньше
//				k++;
//				continue;
//				// перейти к след итерации
//			}
//		}
//	}
//	return MinPoint;
//}
//
//void BarrierFunctionsMethod::test(vector<Point> x, double r)
//{
//	for (int i = 0; i <= 2; i++)
//	{
//		cout << x[i].x << " " << x[i].y << "   ";
//	}
//	cout << endl << setprecision(16) << P(x[0], r) << " " << setprecision(16) << P(x[1], r) << " " << setprecision(16) << P(x[2], r) << " " << endl << endl;
//
//}
//
//int BarrierFunctionsMethod::maxPoint(vector<Point> point, double r)
//{
//	if ((P(point[0], r) > P(point[1], r)) && (P(point[0], r) > P(point[2], r)))
//	{
//		return 0;
//	}
//	else if (P(point[1], r) > P(point[2], r))
//	{
//		return 1;
//	}
//	else
//	{
//		return 2;
//	}
//}
//
//int BarrierFunctionsMethod::minPoint(vector<Point> point, double r)
//{
//	if ((P(point[0], r) < P(point[1], r)) && (P(point[0], r) < P(point[2], r)))
//	{
//		return 0;
//	}
//	else if (P(point[1], r) < P(point[2], r))
//	{
//		return 1;
//	}
//	else
//	{
//		return 2;
//	}
//}
//
//int BarrierFunctionsMethod::midPoint(vector<Point> point, double r)
//{
//	if ((P(point[0], r) > P(point[1], r)) && (P(point[0], r) > P(point[2], r)))
//	{
//		if (P(point[1], r) > P(point[2], r))
//		{
//			return 1;
//		}
//		else
//		{
//			return 2;
//		}
//	}
//	else if ((P(point[0], r) < P(point[1], r)) && (P(point[0], r) < P(point[2], r)))
//	{
//		if (P(point[1], r) > P(point[2], r))
//		{
//			return 2;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//}
//vector<Point> BarrierFunctionsMethod::DefPoints(vector<Point> points, int MaxOrMin, double r)
//{
//	vector<Point> newVec;
//	int max = maxPoint(points, r);
//	int min = minPoint(points, r);
//	int mid = midPoint(points, r);
//
//	if ((mid == min) && (mid == max))
//	{
//		cout << "непредвиденые обстоятельства в квадрате, исправь!!!" << endl;
//		cout << max << "  " << mid << "  " << min << "  " << endl;
//		exit(0);
//	}
//	if (max == min)
//	{
//		cout << "непредвиденые обстоятельства, исправь!!!" << endl;
//		exit(0);
//		cout << max << "  " << mid << "  " << min << "  " << endl;
//	}
//	cout << max << "  " << mid << "  " << min << "  " << endl;
//	if ((mid == min) || (mid == max))
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if ((i != min) && (i != max))
//			{
//				mid = i;
//			}
//		}
//	}
//	cout << max << "  " << mid << "  " << min << "  " << endl;
//
//	if (MaxOrMin == 1)
//	{
//		newVec.push_back(points[max]);
//		newVec.push_back(points[mid]); // Для поиска максимума
//		newVec.push_back(points[min]);
//	}
//	else
//	{
//		newVec.push_back(points[min]);
//		newVec.push_back(points[mid]); // Для поиска минимума
//		newVec.push_back(points[max]);
//	}
//
//	return newVec;
//}
//
//double BarrierFunctionsMethod::CalcDelta(vector<Point> x, Point x_gc, double r)
//{
//	double buf = 0, func_gc = P(x_gc, r);
//
//	for (int i = 0; i < config::n + 1; i++)
//	{
//		double func = P(x[i], r);
//		buf += (func - func_gc) * (func - func_gc);
//	}
//	buf /= config::n + 1;
//
//	return sqrt(buf);
//}