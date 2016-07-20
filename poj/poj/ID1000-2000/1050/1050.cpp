/*
 * problem:	poj 1050
 * describe:max sub matrix
 * author:	guzhoudiaoke 
 * time:	2011-10-05
 */

#include <stdio.h>
#include <stdlib.h>

#define INC	100000

int a[101][101], n;

int max_sum(int n, int *d)
{
	int sum = 0, b = 0, i;
	for (i = 1; i <= n; i++)
	{
		if (b > 0) 
			b += d[i];
		else 
			b = d[i];
		if (b > sum)
			sum = b;
	}

	return sum;
}

int max_sum_two_dimensional()
{
	int sum = 0, i, j, k, max;
	int *b = new int[n+1];

	for (i = 1; i <= n; i++)
	{
		for (k = 1; k <= n; k++)
			b[k] = 0;
		for (j = i; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
				b[k] += a[j][k];
			max = max_sum(n, b);
			if (max > sum)
				sum = max;
		}
	}

	delete []b;
	return sum;
}

int main()
{
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	printf("%d\n", max_sum_two_dimensional());

	return 0;
}