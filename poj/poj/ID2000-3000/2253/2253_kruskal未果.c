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

typedef struct edge {
	int u;
	int v;
	int w;
} edge;

point stones[201];
edge paths[20000];
int n, edge_num;
int *root;
int *parent;
int mst[201];


int cmp_edge(const void *a, const void *b)
{
	return ((edge *)a)->w - ((edge *)b)->w;
}

void init_set()
{
	root = (int *)malloc(sizeof(int) * (n+1));
	parent = (int *)malloc(sizeof(int) * (n+1));
	int i;
	for (i = 1; i <= n; i++)
	{
		parent[i] = 1;
		root[i] = 1;
	}
}

int find_set(int e)
{
	int i = e;
	while (!root[i]) i = parent[i];
	int j = e;
	while (j != i)
	{
		int pj = parent[j];
		parent[j] = i;
		j = pj;
	}

	return i;
}

int union_set(int x, int y)
{
	int px = find_set(x);
	int py = find_set(y);
	if (px == py) return 0;

	if (parent[px] < parent[py])
	{
		parent[py] += parent[px];
		root[px] = 0;
		parent[px] = py;
	}
	else
	{
		parent[px] += parent[py];
		root[py] = 0;
		parent[py] = px;
	}

	return 1;
}

void free_set()
{
	free(parent);
	free(root);
}

void kruskal()
{
	qsort(paths, edge_num, sizeof(edge), cmp_edge);
	init_set();
	
	int min = 0, k = 0, i;
	for (i = 0; i < edge_num; i++)
	{
		if (union_set(paths[i].u, paths[i].v))
		{
			min += paths[i].w;
			mst[k++] = i;
		}
		if (k == n-1)
			break;
	}

	free_set();
}

int get_result()
{
	int i = 0;
	int max = 0;
	int dist;

	return max;
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

		k = 0;
		for (i = 1; i <= n; i++)
			for (j = i+1; j <= n; j++)
			{
				paths[k].u = i;
				paths[k].v = j;
				paths[k].w = (stones[i].x-stones[j].x)*(stones[i].x-stones[j].x) + 
					(stones[i].y-stones[j].y)*(stones[i].y-stones[j].y);
				k++;
			}

		edge_num = k;
		kruskal();
		t++;
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", t, sqrt(get_result()));
	}

	return 0;
}
