/*
 * poj 2485
 * guzhoudiaoke@126.com
 * 2011-09-18
 */

#include <stdio.h>

#define INF	1000000

int n, max_road;
int distance[501][501];
int closedge[501];

void mst_prim()
{
	int i, j, k, min;
	for (i = 1; i <= n; i++)
		closedge[i] = distance[1][i];
	closedge[1] = 0;

	for (i = 1; i < n; i++)
	{
		min = INF;
		for (j = 1; j <= n; j++)
			if (closedge[j] && closedge[j] < min)
			{
				k = j;
				min = closedge[j];
			}

		if (min > max_road)
			max_road = min;
		closedge[k] = 0;

		for (j = 1; j <= n; j++)
			if (closedge[j] && distance[k][j] < closedge[j])
				closedge[j] = distance[k][j];
	}
}

int main()
{
	int i, j, t;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &distance[i][j]);

		max_road = 0;
		mst_prim();
		printf("%d\n", max_road);
	}

	return 0;
}
