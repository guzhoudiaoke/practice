/*
 * poj 1260
 * guzhoudiaoke@126.com
 * 2011-09-14
 */

#include <stdio.h>

int sum(int *a, int s, int e)
{
	int re = 0, i;
	for (i = s; i <= e; i++)
		re += a[i];
	return re;
}

int main()
{
	int n, c, i, j, k, a[1001], p[1001];
	int dp[101];	// 买前i 种的最小花费
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &c);
		for (i = 0; i < c; i++)
			scanf("%d%d", &a[i], &p[i]);
		
		k = 0;
		for (i = 0; i < c; i++)
		{
			k += a[i];
			dp[i] = (k+10) * p[i];
		}
		for (i = 1; i < c; i++)
			for (j = 0; j < i; j++)
			{
				k = sum(a, j+1, i);
				int price = (k + 10) * p[i] + dp[j];
				if (price < dp[i])
					dp[i] = price;
			}
		printf("%d\n", dp[c-1]);
	}

	return 0;
}
