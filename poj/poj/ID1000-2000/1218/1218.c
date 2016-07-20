/*
 * poj 1218
 * guzhoudiaoke@126.com
 * 2011-09-15
 */

#include <stdio.h>

int main()
{
	int cell[101], i, j, n, t, x;
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d", &n);
		x = 0;
		for (i = 1; i <= 10; i++)
		{
			if (i*i > n)
				break;
			x++;
		}

		printf("%d\n", x);
	}

	return 0;
}
