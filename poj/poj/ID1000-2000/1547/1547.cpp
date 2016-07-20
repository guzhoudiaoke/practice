/*
 * poj 1547
 * guzhoudiaoke@126.com
 * 2011-11-27
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int n, a, b, c, v, min, max;
	char min_name[10], max_name[10], name[10];

	while (1) {
		scanf("%d", &n);
		if (n == -1) break;

		min = 250;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d %s", &a, &b, &c, name);
			v = a*b*c;
			if (v < min) {
				min = v;
				strcpy(min_name, name);
			}
			if (v > max) {
				max = v;
				strcpy(max_name, name);
			}
		}

		printf("%s took clay from %s.\n", max_name, min_name);
	}

	return 0;
}
