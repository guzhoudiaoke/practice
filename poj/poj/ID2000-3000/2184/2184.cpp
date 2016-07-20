/*
 * poj 2184
 * guzhoudiaoke@126.com
 * 2011-11-04
 */

#include <stdio.h>
#include <string.h>

#define ZERO	100000

int dp[ZERO*2 + 1];

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, si, fi, i, j;
	memset(dp, 0, sizeof(dp));
	dp[ZERO] = ZERO;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &si, &fi);
		int left = ZERO - i*1000 + si;
		int right = ZERO + i*1000 + si;
		if (si > 0)
		{
			for (j = right; j >= left; j--)
			{
				if (dp[j] || dp[j-si])
					dp[j] = max(dp[j], dp[j-si] + fi);
			}
		}
		else
		{
			
			for (j = left; j <= right; j++)
			{
				if (dp[j] || dp[j-si])
					dp[j] = max(dp[j], dp[j-si] + fi);
			} 
		}
	}

	int ans = 0;
	for (i = ZERO; i < ZERO*2 + 1; i++)
		if (dp[i] && dp[i] >= ZERO && ans < dp[i] + i - ZERO - ZERO)
			ans = dp[i] + i - ZERO - ZERO;
	
	printf("%d\n", ans);

	return 0;
}

