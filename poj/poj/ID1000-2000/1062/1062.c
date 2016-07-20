/*
 * poj 1062
 * guzhoudiaoke@126.com
 * 2011-09-16
 */

#include <stdio.h>

#define INF	65535

int change[101][101];
int price[101];
int level[101];
int m, n, pri;
int min;

int dfs(int u, int money, int min_lev, int max_lev)
{
	int i, re, min_level, max_level;
	re = money + price[u];
	if (re < min)
		min = re;
		
	if (re > 10000)
		return;
	
	for (i = 1; i <= n; i++)
		if (change[u][i] != INF && level[i] >= min_lev && level[i] <= max_lev)
		{
			min_level = min_lev;
			max_level = max_lev;
			if (level[i]-m > min_lev) min_level = level[i] - m;
			if (level[i]+m < max_lev) max_level = level[i] + m;
			
			dfs(i, re-price[u]+change[u][i], min_level, max_level);
		}
}

int main()
{
	int i, j, x, no, ch;
	scanf("%d%d", &m, &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			change[i][j] = INF;

	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &price[i], &level[i], &x);
		for (j = 1; j <= x; j++)
		{
			scanf("%d%d", &no, &ch);
			change[i][no] = ch;
		}
	}
	
	min = INF;
	dfs(1, 0, level[1]-m, level[1]+m);
	printf("%d\n", min);

	return 0;
}
