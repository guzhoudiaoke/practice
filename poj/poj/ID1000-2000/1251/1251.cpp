/*
 * poj 1251
 * guzhoudiaoke@126.com
 * 2011-11-20
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define INF 0x7ffffff

typedef struct edge {
	int start;
	int end;
	int len;
} edge;

edge e[200];
int n, parent[30], rank[30];

void init_set()
{
	for (int i = 1; i < 30; i++)
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
	return ((edge *)a)->len - ((edge *)b)->len;
}

int kruskal(int num)
{
	int min = 0;
	int k = 0;
	qsort(e, num, sizeof(edge), cmp_edge);

	for (int i = 0; i < num; i++)
	{
		if (find_set(e[i].start) != find_set(e[i].end))
		{
			union_set(e[i].start, e[i].end);
			min += e[i].len;
			k++;
		}
		if (k == n-1)
			return min;
	}

	return min;
}

int main()
{
	int i, j, r, k, dis;
	char st, en;
	while (1)
	{
		init_set();
		k = 0;
		cin >> n;
		if (n == 0) break;

		for (i = 1; i < n; i++)
		{
			cin >> st >> r;
			for (j = 0; j < r; j++)
			{
				cin >> en >> dis;
				e[k].start = (int)(st-'A'+1);
				e[k].end = (int)(en-'A'+1);
				e[k].len = dis;
				k++;
			}
		}

		cout << kruskal(k) << endl;
	}

	return 0;
}