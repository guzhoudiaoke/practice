/*
 * poj 1847
 * guzhoudiaoke
 * 2011-10-19
 */

#include <stdio.h>

#define INF	100000

int n, a, b, map[101][101], dis[101];
bool final[101];

// a 到其他各个点最短路径
void shortest_path_dij()
{
	int v, w, i, min;
	for (v = 1; v <= n; v++)
	{
		final[v] = false;
		dis[v] = map[a][v];
	}
	dis[a] = 0;
	final[a] = true;

	for (i = 1; i < n; i++)
	{
		min = INF;
		for (w = 1; w <= n; w++)
			if (!final[w] && dis[w] < min)
			{
				v = w;
				min = dis[w];
			}

		final[v] = true;
		for (w = 1; w <= n; w++)
			if (!final[w] && min + map[v][w] < dis[w])
				dis[w] = min + map[v][w];
	}
}

int main()
{
	int i, j, k;
	scanf("%d %d %d", &n, &a, &b);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			map[i][j] = INF;

	for (i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &k);
		scanf("%d", &t);
		map[i][t] = 0;
		for (j = 1; j < k; j++)
		{
			scanf("%d", &t);
			map[i][t] = 1;
		}
	}

	shortest_path_dij();

	if (dis[b] < INF)
		printf("%d\n", dis[b]);
	else
		printf("-1\n");

	return 0;
}