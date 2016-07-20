/*
 * poj 2533
 * guzhoudiaoke@126.com
 * 2011-09-14
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *dp, N, *num, i, j, k, max;

	scanf("%d", &N);
	num = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	dp = (int *)malloc(sizeof(int) * N);
	//dp[0] = 1;
	for (i = 0; i < N; i++)
		dp[i] = 1;

	for (i = 1; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (num[i] > num[j] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	
	max = 0;
	for (i = 0; i < N; i++)
		if (dp[i] > max)
			max = dp[i];

	printf("%d\n", max);
	
	return 0;
}
