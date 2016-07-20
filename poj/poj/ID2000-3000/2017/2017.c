/*
 * poj 2017
 * guzhoudiaoke@126.com
 * 2011-09-22
 */

#include <stdio.h>

int main()
{
	int n, speed, time, pre_time, sum;
	while (1)
	{
		scanf("%d", &n);
		if (n == -1)
			break;

		sum = 0;
		pre_time = 0;
		while (n--)
		{
			scanf("%d%d", &speed, &time);
			sum += speed * (time - pre_time);
			pre_time = time;
		}

		printf("%d miles\n", sum);
	}

	return 0;
}
