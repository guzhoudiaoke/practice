/*
 * poj 1003
 * guzhoudiaoke@126.com
 * 2011-08-29
 */

#include <stdio.h>

int main()
{
	float length[274];
	int i;
	float len = 0.0;
	
	for (i = 2; i < 276; i++)
	{
		len += 1.0 / i;
		length[i-2] = len;
	}
	
	while (1)
	{
		scanf("%f", &len);
		if (len == 0.00)
			break;
		for (i = 0; i < 274; i++)
		{
			if (length[i] >= len)
				break;
		}
		printf("%d card(s)\n", i+1);
	}
	
	return 0;
}
