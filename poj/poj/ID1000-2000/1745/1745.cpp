/*
 * poj 1745
 * guzhoudiaoke
 * 2011-10-19
 */

#include <stdio.h>
#include <string.h>

#define BALANCE	100

int n, k, num[10001];
bool dp[10001][201]; // dp[i][j]：前i 个数运算结果，模k 能否得到j

bool solve()
{
	int i, j;
	dp[0][BALANCE] = 1;

	for (i = 1; i <= n; i++)
		for (j = BALANCE-k; j < k+BALANCE; j++)
			if (dp[i-1][j] == true)
			{
				dp[i][(j - BALANCE + num[i]%k) % k + BALANCE] = true;
				dp[i][(j - BALANCE + (-num[i])%k) % k + BALANCE] = true;
			}

	return dp[n][BALANCE];
}

int main()
{
	int i;
	memset(dp, false, sizeof(dp));

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	if (solve())
		printf("Divisible\n");
	else
		printf("Not divisible\n");

	return 0;
}
