#pragma once
#include <vector>
#include <math.h>

using namespace std;
static struct config
{
public:
	static const int k = 0; // итерация
	static constexpr double gamma = 2; // коэффициент растяжения
	static const int n = 2; // n-мерное пространство
	static constexpr double Eps = 0.001; // точность
	static constexpr double ShtrafEps = 1e-9;
	static constexpr double barrierEps = 1e-10;
	static constexpr double configr = 1;
	static constexpr double alpha = 1; // коэффициент отражения
	static constexpr double betta = 0.5; // коэффициент сжатия
	static constexpr double shtrafbetta = 0.5;
	static constexpr double barrierbetta = 0.5;
};


