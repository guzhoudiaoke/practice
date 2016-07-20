/*
 * poj 2395
 * guzhoudiaoke@126.com
 * 2011-11-19
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 1000000001

typedef struct edge {
	int start;
	int end;
	int length;
} edge;

edge *e;
int *rank;	// rank[x] 表示x的高度
int *parent;	// 父节点
int m, n;

void init_set()
{
	rank = new int[n+1];
	parent = new int[n+1];

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int find_set(int x)
{
	if (x != parent[x])
		parent[x] = find_set(parent[x]);
	
	return parent[x];
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	
	if (x == y) return;
	
	if (rank[x] > rank[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}
}

int cmp_edge(const void *a, const void *b)
{
	return ((edge *)a)->length - ((edge *)b)->length;
}

int kruskal()
{
	int min_max = 0;
	int k = 0;
	qsort(e, m, sizeof(edge), cmp_edge);

	for (int i = 0; i < m; i++) {
		if (find_set(e[i].start) != find_set(e[i].end)) {
			union_set(e[i].start, e[i].end);
			if (min_max < e[i].length)
				min_max = e[i].length;
			k++;
		}
		if (k == n-1)
			return min_max;
	}
}

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	e = new edge[m+1];
	init_set();

	for (i = 0; i < m; i++)
		scanf("%d %d %d", &e[i].start, &e[i].end, &e[i].length);

	printf("%d\n", kruskal());

	delete []e;
	delete []rank;
	delete []parent;

	return 0;
}

