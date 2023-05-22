#include <iostream>
#include "config.h"
#include <algorithm>
#include "DefinePoints.h"
#include "Operations.h"
#include "FindMin.h"
#include <iomanip>
#include "ShtrafFunctionsMethod.h"
#include "BarrierFunctionsMethod.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int MaxOrMin;
	int hz;
	cout << " А че искать то? \n" << " Если максимум, тыкни 1\n" << " Если минимум тыкни 0\n" << endl;
	cin >> MaxOrMin;

	FindMin xMin;
	cout << " А че потестить хочешь то? \n" << " Если 2 лабу, тыкни 2\n" << " Если штраф тыкни 0\n" << " Если барьер тыкни 1\n" << endl;
	cin >> hz;

	if (hz == 2)
	{
		xMin.Find(MaxOrMin, xMin.DefinePoint0()); // 2 лаба
	}
	else if (hz == 0)
	{
		ShtrafFunctionsMethod result;
		result.FindMinShtraf(MaxOrMin); // 3 лаба
	}
	//else if (hz == 1)
	//{
	//	BarrierFunctionsMethod result;
	//	xMin = result.FindMinBarrier(MaxOrMin); // 3 лаба
	//}




	cout << "(" << setprecision(10) << xMin.point[0].x << ", " << setprecision(10) << xMin.point[0].y << ") func: " << setprecision(10) << xMin.F0 << " k: " << xMin.k << endl;
	cout << setprecision(10) << sqrt((xMin.point[0].x * xMin.point[0].x) + (xMin.point[0].y * xMin.point[0].y));



}
