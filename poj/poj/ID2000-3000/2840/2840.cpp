/*
 * poj 2840
 * guzhoudiaoke@126.com
 * 2011-11-30
 */

#include <stdio.h>

int main()
{
	int t, h, m, ans, i;

	scanf("%d", &t);
	while (t--) {
		scanf("%d:%d", &h, &m);
		if (m) ans = 0;
		else ans = h <= 12 ? h+12 : h-12;

		printf("%d\n", ans);
	}

	return 0;
}
