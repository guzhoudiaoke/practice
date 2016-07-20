/*
 * poj 2509
 * guzhoudiaoke@126.com
 * 2011-11-25 20:19
 */

#include <stdio.h>

int solve(int n, int k)
{
	int ret = n;
	while (n >= k)
	{
		ret += n / k;
		n = n/k + n%k;
	}

	return ret;
}

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		printf("%d\n", solve(n, k));
	}

	return 0;
}
