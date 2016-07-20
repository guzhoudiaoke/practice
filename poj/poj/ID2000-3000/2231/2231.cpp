/*
 * poj 2231
 * guzhoudiaoke@126.com
 * 2011-11-24 20:41
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	long long pos[10001], ans;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &pos[i]);

	ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			ans += abs(pos[i] - pos[j]);

	printf("%lld\n", ans*2);

	return 0;
}
