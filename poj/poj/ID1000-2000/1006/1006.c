/*
 * poj 1006
 * guzhoudiaoke@126.com
 * 2011-08-30
 */

#include <stdio.h>

int main()
{
	int p, e, i, d, day;
	int count = 0;
	
	scanf("%d%d%d%d", &p, &e, &i, &d);
	while (p != -1)
	{
		count ++;
		
		p = p % 23;
		e = e % 28;
		i = i % 33;
		
		day = i;
		while (day <= d)
			day += 33;
		
		while (1)
		{
			if (day%23 != p || day%28 != e)
				day += 33;
			else
			{
				printf("Case %d: the next triple peak occurs in %d days.\n", count, day-d);
				break;
			}
		}
		
		scanf("%d%d%d%d", &p, &e, &i, &d);
	}
	
	return 0;
}

