/*
 * poj 1276
 * guzhoudiaoke@126.com
 * 2011-09-12
 */

#include <stdio.h>
#include <string.h>

#define MAX	100000

int dp[MAX+1];

int main()
{
	int cash, N, i, j, k, nk[11], dk[11];
	
	while (scanf("%d%d", &cash, &N) != EOF)
	{
		for (i = 1; i <= N; i++)
			scanf("%d%d", &nk[i], &dk[i]);
		
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		
		int found = 0;
		for (i = 1; i <= N && !found; i++)
			for (j = cash; j >= 0 && !found; j--)
				if (dp[j] == 1)
					for (k = 1; k <= nk[i]; k++)
					{
						int w = dk[i] * k;
						
						if (j+w < cash)
							dp[j + w] = 1;
						else if (j+w == cash)
						{
							found = 1;
							dp[cash] = 1;
						}
						else
							break;
					}
		
		int i = cash;
		while (dp[i] == 0)
			i--;

		printf("%d\n", i);
	}
	
	return 0;
}
