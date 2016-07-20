/*
 * poj 1837
 * guzhoudiaoke@126.com
 * 2011-09-12
 */

#include <stdio.h>
#include <string.h>

#define BALANCE	7500

// dp[i][j] 表示挂了i 个码，平衡度为j 的挂法
int C, G, c[21], g[21], dp[21][BALANCE*2 + 1];

int main()
{
	int i, j, k;
	scanf("%d%d", &C, &G);
	for (i = 1; i <= C; i++)
		scanf("%d", &c[i]);
	for (i = 1; i <= G; i++)
		scanf("%d", &g[i]);
	
	memset(dp, 0, sizeof(dp));
	dp[0][BALANCE] = 1;	// 挂了0 个砝码，平衡度为BALANCE 的挂法
	
	for (i = 1; i <= G; i++)
		for (j = -BALANCE; j <= BALANCE; j++)
			if (dp[i-1][j+BALANCE] != 0)
				for (k = 1; k <= C; k++)
				{
					int weight = g[i]*c[k];		// 第i个码挂在第k个钩上
					dp[i][j+BALANCE+weight] += dp[i-1][j+BALANCE];
				}
	
	printf("%d\n", dp[G][BALANCE]);
	return 0;
}


