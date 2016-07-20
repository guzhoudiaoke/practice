/*
 * poj 2636
 * guzhoudiaoke@126.com
 * 2011-11-29
 */

#include <stdio.h>

int main()
{
	int n, k, t, ans;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		ans = 0;
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &t);
			ans += t;
		}
		ans = ans - k + 1;
		printf("%d\n", ans);
	}

	return 0;
}

