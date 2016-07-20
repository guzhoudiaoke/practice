/*
 * poj 1658
 * guzhoudiaoke@126.com
 * 2011-09-21
 */

#include <stdio.h>

int main()
{
	int t, num[5], i;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3]);
		if ((num[1]-num[0]) == (num[3]-num[2]))
			num[4] = num[3]+(num[3]-num[2]);
		else
			num[4] = num[3]*(num[3]/num[2]);
		
		for (i = 0; i < 5; i++)
			printf("%d ", num[i]);
		printf("\n");
	}

	return 0;
}
