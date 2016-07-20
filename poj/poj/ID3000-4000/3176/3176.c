/*
 * poj 3176
 * guzhoudiaoke@126.com
 * 2011-09-14
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int dp[351][351], n, i, j;
	char num[351][351];
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			scanf("%d", &num[i][j]);
	
	//memset(dp, 0, sizeof(dp));
	dp[0][0] = num[0][0];

	for (i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + num[i][0];
		for (j = 1; j < i; j++)
		{
			if (dp[i-1][j-1] > dp[i-1][j])
				dp[i][j] = dp[i-1][j-1] + num[i][j];
			else
				dp[i][j] = dp[i-1][j] + num[i][j];
		}
		dp[i][i] = dp[i-1][i-1] + num[i][i];	
	}

	int max = dp[n-1][0];
	for (i = 1; i < n; i++)
		if (dp[n-1][i] > max)
			max = dp[n-1][i];
	
	printf("%d\n", max);
	
	return 0;
}
