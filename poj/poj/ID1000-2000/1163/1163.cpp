/*
 * poj 1163
 * guzhoudiaoke@126.com
 * 2011-11-21
 */

#include <stdio.h>
#include <string.h>

int triangle[101][101], row;
int dp[101][101];

int max_2(int a, int b)
{
	return a > b ? a : b;
}

int solve()
{
	int max = 0, i, j;
	for (i = 1; i <= row; i++)
		for (j = 1; j <= i; j++)
			dp[i][j] = max_2(dp[i-1][j] + triangle[i][j], dp[i-1][j-1] + triangle[i][j]);

	for (i = 1; i <= row; i++) {
		if (max < dp[row][i]) 
			max = dp[row][i];
	}
	
	return max;
}

int main()
{
	int i, j;
	scanf("%d", &row);

	for (i = 1; i <= row; i++)
		for (j = 1; j <= i; j++)
			scanf("%d", &triangle[i][j]);

	memset(dp, 0, sizeof(dp));
	printf("%d\n", solve());

	return 0;
}

