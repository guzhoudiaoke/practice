/*
 * poj 1159
 * guzhoudiaoke@126.com
 * 2011-09-14
 */

#include <stdio.h>
#include <string.h>

short dp[5001][5001];	// dp[i][j] 正序前i 个字符和逆序前j 个字符，最长子序列

int solve(int len, char *str)
{
	int i, j;
	memset(dp, 0, sizeof(dp));

	for (i = 1; i <= len; i++)
		for (j = 1; j <= len; j++)
		{
			if (str[i-1] == str[len-j])
				dp[i][j] = dp[i-1][j-1] + 1;
				
			else if(dp[i-1][j] > dp[i][j-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i][j-1];
		}
	
	return len - dp[len][len];
}

int main()
{
	int len;
	char str[5001];
	
	scanf("%d%s", &len, str);
	printf("%d\n", solve(len, str));

	return 0;
}
