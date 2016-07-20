/*
 * problem:	poj	1221
 * author:	guzhoudiaoke
 * time:	2011-10-07
 */

#include <stdio.h>

long long dp[251][251] = { 0 };

void calc()
{
	int i, j;
	for (i = 1; i <= 250; i++)
		dp[i][i] = 1;
	
	for (i = 1; i <= 250; i++)
		for (j = i-1; j >= 1; j--)
		{
			if (i - j*2 >= j)
				dp[i][j] = dp[i][j+1] + dp[i - j*2][j];
			else if (i - j*2 == 0)
				dp[i][j] = dp[i][j+1] + 1;
			else
				dp[i][j] = dp[i][j+1];
		}
}

int main()
{
	int n;
	calc();
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		printf("%d %lld\n", n, dp[n][1]);
	}

	return 0;
}