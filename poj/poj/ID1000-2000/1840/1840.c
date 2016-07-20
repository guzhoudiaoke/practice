/*
 * poj 1840
 * guzhoudiaoke@126.com
 * 2011-09-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	18750000

unsigned char positive_table[MAX+1];

int main()
{
	int a1, a2, a3, a4, a5, n;	
	scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	
	memset(positive_table, 0, sizeof(positive_table));
	
	int i, j, k;
	int sum;
	
	for (i = -50; i <= 50; i++)
		for (j = -50; j <= 50; j++)
		{
			if (!i || !j)
				continue;
			sum = a4*i*i*i + a5*j*j*j;
			if (sum >= 0)
				positive_table[sum]++;
				
		}

	n = 0;
	for (i = -50; i <= 50; i++)
		for (j = -50; j <= 50; j++)
			for (k = -50; k <= 50; k++)
			{
				if (!i || !j || !k)
					continue;
				sum = a1*i*i*i + a2*j*j*j + a3*k*k*k;
				if (sum <= 0)
					n += positive_table[-sum];
			}
		
	printf("%d\n", 2*n);
		
	return 0;
}
