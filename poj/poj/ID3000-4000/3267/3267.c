/*
 * poj 3267
 * guzhoudiaoke@126.com
 * 2011-09-13
 */

#include <stdio.h>
#include <string.h>

char dic[601][26];
char message[301];
int dp[301];	// dp[i] 表示匹配第i 个字母，需要删除的字母数
int W, L;

int solve()
{
	int i, j, k, p, m, len, del;
	for (i = 0; i <= L; i++)
		dp[i] = i;
	
	for (i = 1; i <= L; i++)
	{
		for (j = 0; j < W; j++)
		{
			len = strlen(dic[j]);
			k = 0;
			p = i-1;
			del = 0;
			while (k < len && p < L)
			{
				if (message[p] != dic[j][k])
					del++;
				else
					k++;
				p++;
			}
			if (k == len && dp[i-1]+del < dp[p])
			{
				dp[p] = dp[i-1] + del;
				for (m = p+1; m <= L; m++)
					if (dp[p]+m-p < dp[m])
						dp[m] = dp[p]+m-p;
			}
		}
	}
	return dp[L];
}

int main()
{
	int i;
	scanf("%d%d%s", &W, &L, message);
	for (i = 0; i < W; i++)
		scanf("%s", dic[i]);
	
	printf("%d\n", solve());

	return 0;
}
