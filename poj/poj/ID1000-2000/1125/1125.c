/*
 * poj 1125
 * guzhoudiaoke@126.com
 * 2011-09-17
 */

#include <stdio.h>

#define INF	100000

int n, graph[101][101], dist[101][101], max[101];

void shortest_path_floyd()
{
	int i, u, v, w;
	for (v = 1; v <= n; v++)
		for (w = 1; w <= n; w++)
		{
			dist[v][w] = graph[v][w];
		}

	for (u = 1; u <= n; u++)
		for (v = 1; v <= n; v++)
			for (w = 1; w <= n; w++)
				if (dist[v][u] + dist[u][w] < dist[v][w])
					dist[v][w] = dist[v][u] + dist[u][w];
}

int get_result()
{
	int i, j, m, re;
	for (i = 1; i <= n; i++)
	{
		m = -1;
		for (j = 1; j <= n; j++)
			if (i != j && dist[i][j] > m)
				m = dist[i][j];
		max[i] = m;
	}

	m = INF;
	for (i = 1; i <= n; i++)
		if (max[i] < m)
		{
			m = max[i];
			re = i;
		}
	
	return re;
}

int main()
{
	int i, j, m, no, time;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				graph[i][j] = INF;
				
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			for (j = 1; j <= m; j++)
			{
				scanf("%d%d", &no, &time);
				graph[i][no] = time;
			}
		}

		shortest_path_floyd();
		int index = get_result();
		printf("%d %d\n", index, max[index]);
	}

	return 0;
}
