/*
 * poj 1062
 * guzhoudiaoke@126.com
 * 2011-09-16
 */

#include <stdio.h>

#define INF	100000000

typedef struct object {
	int price;
	int level;
} object;

int price[101][101];
object objects[101];
int dist[101];
int final[101];
int no;
int change;
int pri;
int m;

int shortest_path_dij(int s, int n)
{
	int i, v, w, min;
	int level_min, level_max;
	
	level_min = objects[s].level-m;
	level_max = objects[s].level+m;
	
	for (v = 1; v <= n; v++)
	{
		final[v] = 0;
		dist[v] = price[s][v] + objects[v].price;
	}
	dist[s] = pri;
	final[s] = 1;

	for (i = 1; i < n; i++)
	{
		min = INF;
		for (w = 1; w <= n; w++)
			if (!final[w] && dist[w] < min && objects[w].level > level_min && objects[w].level < level_max)
			{
				v = w;
				min = dist[w];
			}
		
		final[v] = 1;
		if (objects[v].level-m > level_min)
			level_min = objects[v].level-m;
		if (objects[v].level+m < level_max)
			level_max = objects[v].level+m;
			
		for (w = 1; w <= n; w++)
			if (!final[w] && min + price[v][w] - objects[v].price + objects[w].price < dist[w])
				dist[w] = min + price[v][w] - objects[v].price + objects[w].price;
	}

	min = INF;
	for (i = 1; i <= n; i++)
		if (dist[i] < min)
			min = dist[i];

	return min;
}

int main()
{
	int n, i, j, level, x, cur;
	
	scanf("%d%d", &m, &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			price[i][j] = INF;

	scanf("%d%d%d", &objects[1].price, &objects[1].level, &x);
	for (i = 1; i <= x; i++)
	{
		scanf("%d%d", &no, &change);
		price[1][no] = change;
	}
	level = objects[1].level;
	cur = 1;
	pri = objects[1].price;

	for (i = 2; i <= n; i++)
	{
		scanf("%d%d%d", &objects[i].price, &objects[i].level, &x);
		cur = i;
		for (j = 1; j <= x; j++)
		{
			scanf("%d%d", &no, &change);
			price[cur][no] = change;
		}
	}

	printf("%d\n", shortest_path_dij(1, n));

	return 0;
}
