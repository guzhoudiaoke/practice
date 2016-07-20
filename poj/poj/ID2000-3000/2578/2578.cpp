/*
 * poj 2578
 * guzhoudiaoke@126.com
 * 2011-11-28 19:29
 */

#include <stdio.h>

int main()
{
	int h1, h2, h3;
	scanf("%d %d %d", &h1, &h2, &h3);

	if (h1 <= 168)
		printf("CRASH %d\n", h1);
	else if (h2 <= 168)
		printf("CRASH %d\n", h2);
	else if (h3 <= 168)
		printf("CRASH %d\n", h3);
	else
		printf("NO CRASH\n");

	return 0;
}
