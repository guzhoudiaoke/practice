/*
 * poj 2078
 * guzhoudiaoke@126.com
 * 2011-10-31
 */

#include <stdio.h>

#define INF	0x7ffffff

int n, num[7][7], c[7], min_sum_max, sum_max;

void dfs(int depth)
{
	if (depth == n)
	{
		sum_max = -INF;
		for (int i = 0; i < n; i++)
			if (sum_max < c[i])
				sum_max = c[i];
		if (min_sum_max > sum_max)
			min_sum_max = sum_max;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				c[j] += num[depth][(i+j) %n];

			dfs(depth+1);

			for (int j = 0; j < n; j++)
				c[j] -= num[depth][(i+j) %n];
		}
	}
}

int main()
{
	int i, j;

	while (1)
	{
		scanf("%d", &n);
		if (n == -1) break;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				scanf("%d", &num[i][j]);
			c[i] = num[0][i];
		}

		min_sum_max = INF;
		dfs(1);

		printf("%d\n", min_sum_max);
	}
	

	return 0;
}
