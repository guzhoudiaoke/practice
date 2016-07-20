/*
 * poj 2013
 * guzhoudiaoke@126.com
 * 2011-09-22
 */

#include <stdio.h>

int main()
{
	int n, i, t = 1;
	char str[15][26];
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		for (i = 0; i < n; i++)
			scanf("%s", str[i]);
		
		printf("SET %d\n", t);
		for (i = 0; i < n; i+=2)
			printf("%s\n", str[i]);
		if (n % 2 == 0)
			n = n - 1;
		else
			n = n - 2;
		for (i = n; i >= 1; i-=2)
			printf("%s\n", str[i]);

		t++;
	}

	return 0;
}
