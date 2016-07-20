/*
 * poj 1258
 * guzhoudiaoke@126.com
 * 2011-09-18
 */

#include <stdio.h>

#define INF	100000000

int distance[101][101];
int closedge[101];
int n, min_sum;

void mst_prim()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		closedge[i] = distance[1][i];
	closedge[1] = 0;

	for (i = 1; i < n; i++)
	{
		int min = INF;
		for (j = 1; j <= n; j++)
			if (closedge[j] && closedge[j] < min)
			{
				k = j;
				min = closedge[j];
			}

		min_sum += min;
		closedge[k] = 0;

		for (j = 1; j <= n; j++)
			if (closedge[j] && distance[k][j] < closedge[j])
				closedge[j] = distance[k][j];
	}
}

int main()
{
	int i, j;
	
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &distance[i][j]);

		min_sum = 0;
		mst_prim();
		printf("%d\n", min_sum);
	}

	return 0;
}
