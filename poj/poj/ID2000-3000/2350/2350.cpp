/*
 * problem: poj 2350
 * author:  guzhoudiaoke
 * time:    2011-09-25
 */

#include <stdio.h>

int grade[1001];

int main()
{
	int c, n, sum, ave, m, i;

	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		sum = 0;
		m = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &grade[i]);
			sum += grade[i];
		}

		ave = sum / n;
		for (i = 0; i < n; i++)
			if (grade[i] > ave)
				m++;

		printf("%.3lf%%\n", (double)m/(double)n*100);
	}

	return 0;
}