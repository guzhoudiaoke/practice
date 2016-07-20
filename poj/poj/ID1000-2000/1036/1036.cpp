/*
 * problem:	poj 1036
 * author:	guzhoudiaoke
 * time:	2011-10-09
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct gangster {
	int t;
	int p;
	int s;
} ganster;

ganster g[101];

/* dp[i] 表示第i 个人能够成功进入时的最大p 和值 */
int n, k, t, dp[101];

int cmp_ganster(const void *a, const void *b)
{
	return ((ganster *)a)->t - ((ganster *)b)->t;
}

int solve()
{
	int i, j, max = 0;
	qsort(g+1, n, sizeof(ganster), cmp_ganster);
	
	dp[0] = 0;
	for (i = 1; i <= n; i++)
		dp[i] = -1;

	for (i = 1; i <= n; i++)
	{
		if (g[i].t > t) break;
		int m = -1;
		for (j = 0; j < i; j++)
		{
			if (dp[j] < 0) continue;
			if (abs(g[j].s - g[i].s) <= abs(g[j].t - g[i].t) && g[i].s <= k)
				if (dp[j] + g[i].p > m)
					m = dp[j] + g[i].p;
		}
		dp[i] = m;
		if (m > max) max = m;
	}

	return max;
}

int main()
{
	int i;
	scanf("%d %d %d", &n, &k, &t);
	
	for (i = 1; i <= n; i++)
		scanf("%d", &g[i].t);
	for (i = 1; i <= n; i++)
		scanf("%d", &g[i].p);
	for (i = 1; i <= n; i++)
		scanf("%d", &g[i].s);

	g[0].t = 0; g[0].s = 0; g[0].p = 0;

	printf("%d\n", solve());

	return 0;
}