/*
 * poj 1543
 * guzhoudiaoke
 * 2011-10-12
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, k, m, tri;
	scanf("%d", &n);

	for (m = 2; m <= n; m++)
		for (i = 2; i <= n; i++)
			for (j = i; j <= n; j++)
				for (k = j; k <= n; k++)
				{
					tri = i*i*i + j*j*j + k*k*k;
					if (tri > m*m*m)
						break;
					else if (tri == m*m*m)
						printf("Cube = %d, Triple = (%d,%d,%d)\n", m, i, j, k);
				}

	return 0;
}