/*
 * poj 2028
 * guzhoudiaoke
 * 2011-10-19
 */

#include <stdio.h>
#include <string.h>

int n, q, date[101];

int main()
{
	int i, j, m, d, best;
	while (1)
	{
		scanf("%d %d", &n, &q);
		if (n == 0 && q == 0) break;
		
		memset(date, 0, sizeof(date));
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			for (j = 0; j < m; j++)
			{
				scanf("%d", &d);
				date[d]++;
			}
		}

		best = 0;
		for (i = 1; i <= 100; i++)
			if (date[best] < date[i] && date[i] >= q)
				best = i;

		printf("%d\n", best);
	}

	return 0;
}