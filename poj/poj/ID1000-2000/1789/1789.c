/*
 * poj 1789
 * guzhoudiaoke@126.com
 * 2011-09-18
 */

#include <stdio.h>

#define INF	100000

char type_code[2001][8];
int distance[2001][2001];
int closedge[2001];
int n, quality;

int get_distance(int x, int y)
{
	int re = 0, i;
	for (i = 0; i < 7; i++)
		if (type_code[x][i] != type_code[y][i])
			re++;
	
	return re;
}

void mst_prim()
{
	int i, j, k;
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

		quality += closedge[k];
		closedge[k] = 0;
		
		for (i = 1; i <= n; i++)
			if (closedge[i] && distance[k][i] < closedge[i])
				closedge[i] = distance[k][i];
	}
}

int main()
{
	int i, j;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 1; i <= n; i++)
			scanf("%s", type_code[i]);

		for (i = 1; i <= n; i++)
			for (j = i; j <= n; j++)
				distance[j][i] = distance[i][j] = get_distance(i, j);
		
		quality = 0;
		mst_prim();
		printf("The highest possible quality is 1/%d.\n", quality);
	}

	return 0;
}

