/*
 * poj 2485
 * guzhoudiaoke@126.com
 * 2011-11-20
 */

#include <stdio.h>

#define INF	0x7ffffff

int distance[501][501], n, closedge[501];

int prim()
{
	int i, j, k;
	int max_min = 0;

	for (i = 1; i <= n; i++)
		closedge[i] = distance[1][i];
	closedge[1] = 0;

	for (j = 1; j < n; j++)
	{
		int min = INF;
		for (i = 1; i <= n; i++)
			if (closedge[i] && closedge[i] < min)
			{
				k = i;
				min = closedge[i];
			}

		if (max_min < closedge[k])
			max_min = closedge[k];
		closedge[k] = 0;
		for (i = 1; i <= n; i++)
			if (closedge[i] && distance[k][i] < closedge[i])
				closedge[i] = distance[k][i];
	}

	return max_min;
}

int main()
{
	int t, i, j;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &distance[i][j]);

		printf("%d\n", prim());
	}

	return 0;
}