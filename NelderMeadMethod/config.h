#pragma once
#include <vector>
#include <math.h>

using namespace std;
static struct config
{
public:
	static const int k = 0; // ��������
	static constexpr double gamma = 2; // ����������� ����������
	static const int n = 2; // n-������ ������������
	static constexpr double Eps = 0.05; // ��������
	static constexpr double alpha = 1; // ����������� ���������
	static constexpr double betta = 0.5; // ����������� ������
	static constexpr double m2_1[2] = { 0, 6 };
	static constexpr double m2_2[2] = { 1, 2 };
	static constexpr double m2_3[2] = { 5, 3 };
	static constexpr double m2[3][2] = { { 0, 6 },{ 0, 0 },{ 5, 3 } };
};


