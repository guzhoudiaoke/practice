/*
 * poj 1408
 * guzhoudiaoke@126.com
 * 2011-09-21
 */

#include <stdio.h>

#define MAX	35

typedef struct point {
	double x;
	double y;
} point;

typedef struct line {
	double a;
	double b;
	double c;
} line;

// 下，上，左，右的顺序，每个边上n 个点
double p[4][MAX];
point points[MAX][MAX];
int n;

line make_line(point p1, point p2)
{
	line re;
	re.a = p1.y - p2.y;
	re.b = p2.x - p1.x;
	re.c = p1.x*p2.y - p2.x*p1.y;

	return re;
}

point get_intersect(line l1, line l2)
{
	point re;
	re.x = (l1.b*l2.c - l2.b*l1.c) / (l1.a*l2.b - l2.a*l1.b);
	re.y = (l1.c*l2.a - l2.c*l1.a) / (l1.a*l2.b - l2.a*l1.b);

	return re;
}

void calc_points()
{
	line l1, l2;
	point p1, p2;
	int i, j;
	for (i = 0; i <= n+1; i++)
	{
		p1.x = p[0][i];
		p1.y = 0;
		p2.x = p[1][i];
		p2.y = 1;
		l1 = make_line(p1, p2);
		for (j = 0; j <= n+1; j++)
		{
			p1.x = 0;
			p1.y = p[2][j];
			p2.x = 1;
			p2.y = p[3][j];
			l2 = make_line(p1, p2);
			points[j][i] = get_intersect(l1, l2);
		}
	}
}

double calc_area(point p1, point p2, point p3, point p4)
{
	double re = 0;
	/*re += p1.y * (p4.x - p2.x);
	re += p2.y * (p1.x - p3.x);
	re += p3.y * (p2.x - p4.x);
	re += p4.y * (p3.x - p1.x);
	*/

	re -= (p3.y-p1.y) * (p4.x-p2.x);
	re += (p3.x-p1.x) * (p4.y-p2.y);
	return re/2;
}

int main()
{
	int i, j;
	double area, max_area;
	point p1, p2, p3, p4;

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 0; i < 4; i++)
		{
			p[i][0] = 0;
			for (j = 1; j <= n; j++)
				scanf("%lf", &p[i][j]);
			p[i][n+1] = 1;
		}

		calc_points();

		max_area = 0;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n; j++)
			{
				p1.x = points[i][j].x; 
				p1.y = points[i][j].y;
				p2.x = points[i][j+1].x;
				p2.y = points[i][j+1].y;
				p3.x = points[i+1][j+1].x;
				p3.y = points[i+1][j+1].y;
				p4.x = points[i+1][j].x;
				p4.y = points[i+1][j].y;

				area = calc_area(p1, p2, p3, p4);
				if (area > max_area)
					max_area = area;
			}

		printf("%.6lf\n", max_area);
	}

	return 0;
}

