/*
 * poj 2105
 * guzhoudiaoke@126.com
 * 2011-09-22
 */

#include <stdio.h>

int weight[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };

int main()
{
	int n, i, j;
	char ip[33];
	int address[4];
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", ip);
		for (i = 0; i < 4; i++)
			address[i] = 0;
		
		for (i = 0; i < 4; i++)
			for (j = 0; j < 8; j++)
				address[i] += (ip[j+i*8] - '0') * weight[j];

		for (i = 0; i < 4; i++)
		{
			printf("%d", address[i]);
			if (i != 3)
				printf(".");
			else
				printf("\n");
		}
	}

	return 0;
}
