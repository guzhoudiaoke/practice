/*
 * poj 2027.c
 * guzhoudiaoke@126.com
 * 2011-09-22
 */

#include <stdio.h>

int main()
{
	int n, x, y;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &x, &y);
		if (x < y)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}

	return 0;
}
