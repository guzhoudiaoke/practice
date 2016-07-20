/*
 * problem:	poj	1141
 * author:	guzhoudiaoke
 * time:	2011-10-06
 */

#include <stdio.h>
#include <cstring>

#define INF	1000000

char brackets[102];
int dp[101][101], path[101][101];

void display(int i, int j)
{
	if (i > j)
		return;
	if (i == j)
	{
		if (brackets[i]=='[' || brackets[i]==']')
			printf("[]");
		else
			printf("()");
	}
	else if (path[i][j] == 0)	// 如果是0 表示i，j匹配递归输出
	{
		printf("%c", brackets[i]);
		display(i+1, j-1);
		printf("%c", brackets[j]);
	}
	else						// 否则i 到k，k+1到j，而k = path[i][j]
	{
		display(i, path[i][j]);
		display(path[i][j]+1, j);
	}
}

void solve(int n)
{
	int i, j, k, m;

	for (i = 1; i <= n; i++)
	{
		dp[i][i-1] = 0;
		dp[i][i] = 1;
	}

	for (k = 1; k <= n-1; k++)
		for (i = 1; i <= n-k; i++)
		{
			j = i+k;
			dp[i][j] = INF;
			
			if ((brackets[i] == '(' && brackets[j] == ')') || (brackets[i] == '[' && brackets[j] == ']'))
				if (dp[i+1][j-1] < dp[i][j])
				{
					dp[i][j] = dp[i+1][j-1];
					path[i][j] = 0;
				}

			for (m = i; m <= j-1; m++)
				if (dp[i][m] + dp[m+1][j] < dp[i][j])
				{
					dp[i][j] = dp[i][m] + dp[m+1][j];
					path[i][j] = m;
				}
		}
}

int main()
{	
	while (gets(brackets+1))
	{
		int n = strlen(brackets+1);

		solve(n);
		display(1, n);

		printf("\n");
	}

	return 0;
}