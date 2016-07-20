/*
 * problem:	poj 1042
 * author:	guzhoudiaoke
 * time:	2011-10-04
 */

#include <stdio.h>

int n, interval, f[26], d[26], t[25], dp[26][193], path[26][193], time[26];

void solve()
{
	int i, j, k, fish, temp;

	for (i = 0; i < 26; i++)
		for (j = 0; j < 193; j++)
		{
			dp[i][j] = -1;
			path[i][j] = -1;
		}
	dp[0][0] = 0;

	for (i = 0; i < 26; i++)
		time[i] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < interval; j++)
			if (dp[i][j] != -1)
			{
 				temp = dp[i][j];
				fish = f[i+1];
				for (k = j+t[i]; k <= interval; k++)
				{
					if (temp >= dp[i+1][k])
					{
						dp[i+1][k] = temp;
						path[i+1][k] = j;
					}
					temp += fish;
					fish -= d[i+1];
					if (fish < 0) fish = 0;
				}
			}

	int max = -1;
	for (i = 1; i <= n; i++)
		if (dp[i][interval] > max)
		{
			max = dp[i][interval];
			k = i;
		}
	
	j = interval;
	for (i = k; i >= 1; i--)
	{
		time[i] = (j - path[i][j] - t[i-1]) * 5;
		j = path[i][j];
	}

	for (i = 1; i < n; i++)
		printf("%d, ", time[i]);
	printf("%d\n", time[n]);
	printf("Number of fish expected: %d\n\n", max);
}

int main()
{
	int i, h;

	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		scanf("%d", &h);
		interval = h * 12;
		
		for (i = 1; i <= n; i++)
			scanf("%d", &f[i]);
		
		for (i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		
		for (i = 1; i < n; i++)
			scanf("%d", &t[i]);
		t[0] = 0;

		solve();
	}

	return 0;
}
