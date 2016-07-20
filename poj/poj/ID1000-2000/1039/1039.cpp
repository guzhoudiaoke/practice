/*
 * problem: poj 1039
 * author : guzhoudiaoke
 * time:	2011-09-26
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const double INC = 10000000.0;
const double precision = 1e-8;

int n;
typedef struct point {
	double x;
	double y;
} point;

// 向量a(x1, y1)叉乘b(x2, y2)
double det(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}

double cross(point a, point b, point c)
{
	return det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
}

int dblcmp(double d)
{
	if (fabs(d) < precision)
		return 0;
	return (d > 0) ? 1 : -1;
}

// 直线ab 与线段cd 判交
int intersect(point a, point b, point c, point d, double &intersect_x)
{
	double c1 = cross(a, b, c);
	double c2 = cross(a, b, d);
	int d1 = dblcmp(c1);
	int d2 = dblcmp(c2);

	intersect_x = -INC;
	
	if (d1 * d2 > 0)
		return 0;
	else if (d1 * d2 < 0)	// 符号不同则有交点
		intersect_x = (c2*c.x - c1*d.x) / (c2-c1);
	return 1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int i, j, k, through_all;
	double intersect_x, max_x;
	while (1)
	{
		cin >> n;
		if (n == 0) break;

		vector <point> p_up(n);
		vector <point> p_down(n);
		through_all = 0;
		max_x = -INC;
		
		for (i = 0; i < n; i++)
		{
			cin >> p_up[i].x >> p_up[i].y;
			p_down[i].x = p_up[i].x;
			p_down[i].y = p_up[i].y - 1;
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
					if (intersect(p_up[i], p_down[j], p_up[k], p_down[k], intersect_x) == 0)
						break;
				if (k == n)	// 全部通过
				{
					through_all = 1;
					break;
				}
				else if (k > max(i, j))
				{
					intersect(p_up[i], p_down[j], p_up[k-1], p_up[k], intersect_x);		// 与上壁求交
					if (intersect_x > max_x) max_x = intersect_x;
					intersect(p_up[i], p_down[j], p_down[k-1], p_down[k], intersect_x); // 与下壁求交
					if (intersect_x > max_x) max_x = intersect_x;
				}
			}
			if (through_all)
				break;
		}

		if (through_all)
			cout << "Through all the pipe." << endl;
		else
			cout << setiosflags(ios::fixed) << setprecision(2) << max_x << endl;
	}

	return 0;
}