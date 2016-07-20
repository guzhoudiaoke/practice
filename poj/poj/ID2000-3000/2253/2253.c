/*
 * poj 2253
 * guzhoudiaoke@126.com
 * 2011-09-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
	int x;
	int y;
}point;

typedef struct close_edge {
	int adjvex;
	int cost;
} close_edge;

point stones[201];
int graph[201][201];
close_edge closedge[201];
int n;

int mini_span_tree_prim(int u)
{
	int i, j, k, min, minimax;
	for (i = 1; i <= n; i++)
	{
		closedge[i].adjvex = i;
		closedge[i].cost = graph[u][i];
	}
	closedge[u].cost = 0;
	
	minimax = 0;
	for (i = 1; i <= n; i++)
	{
		min = 1000000;
		for (j = 1; j <= n; j++)
			if (closedge[j].cost && closedge[j].cost < min)
			{
				min = closedge[j].cost;
				k = j;
			}
		
		if (min > minimax)
			minimax = min;
		if (closedge[k].adjvex == 2)
			return minimax;
		
		closedge[k].cost = 0;
		for (j = 1; j <= n; j++)
		{
			if (graph[k][j] < closedge[j].cost)
			{
				closedge[j].adjvex = j;
				closedge[j].cost = graph[k][j];
			}
		}
	}
	
	return minimax;
}

int main()
{
	int i, j, k, t = 0;

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 1; i <= n; i++)
			scanf("%d%d", &stones[i].x, &stones[i].y);

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				graph[i][j] = (stones[i].x-stones[j].x)*(stones[i].x-stones[j].x) + 
					(stones[i].y-stones[j].y)*(stones[i].y-stones[j].y);
			}

		t++;
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", t, sqrt(mini_span_tree_prim(1)));
	}

	return 0;
}
