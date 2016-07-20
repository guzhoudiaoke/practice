/*
 * problem: poj 2031
 * author:  guzhoudiaoke
 * time:    2011-09-25
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define INF	100000000

typedef struct cell {
	double x;
	double y;
	double z;
	double r;
} cell;

cell cells[101];
double w[101][101];
double closedge[101];
int n;

void get_distance()
{
	int i, j;
	double dis;
	for (i = 1; i < n; i++)
			for (j = i+1; j <= n; j++)
			{
				dis = sqrt((cells[i].x - cells[j].x)*(cells[i].x-cells[j].x) + 
						   (cells[i].y - cells[j].y)*(cells[i].y-cells[j].y) + 
						   (cells[i].z - cells[j].z)*(cells[i].z-cells[j].z));
				
				dis -= (cells[i].r + cells[j].r);
				if (dis < 1e-8)
					w[j][i] = w[i][j] = 0.0;
				else
					w[j][i] = w[i][j] = dis;
			}
}

double mst_prim()
{
	int i, j, k;
	double total = 0.0;
	for (i = 1; i <= n; i++)
		closedge[i] = w[1][i];
	closedge[1] = -1;

	for (i = 1; i < n; i++)
	{
		double min = INF;
		for (j = 1; j <= n; j++)
			if (closedge[j] >= 0 && closedge[j] < min)
			{
				k = j;
				min = closedge[j];
			}

		total += min;
		closedge[k] = -1;

		for (j = 1; j <= n; j++)
			if (closedge[j] >= 0 && closedge[j] > w[k][j])
				closedge[j] = w[k][j];
	}

	return total;
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		
		for (i = 1; i <= n; i++)
			scanf("%lf %lf %lf %lf", &cells[i].x, &cells[i].y, &cells[i].z, &cells[i].r);

		get_distance();
		printf("%.3lf\n", mst_prim());
	}

	return 0;
}