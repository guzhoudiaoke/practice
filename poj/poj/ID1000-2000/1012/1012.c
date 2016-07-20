/*
 * poj 1012
 * guzhoudiaoke
 * 2011-09-24
 */

#include <stdio.h>

int main()
{
	int k, m, left, kill, i;
	int ans[14];
	for (i = 1; i < 14; i++)
		ans[i] = 0;
	while (1)
	{
		scanf("%d", &k);
		if (k == 0)
			break;
		if (ans[k])
		{
			printf("%d\n", ans[k]);
			continue;
		}
		
		m = k+1;
		i = 0;
		while (1)
		{
			left = 2*k;
			kill = 2*k;
			while (1)
			{
				kill = (kill+m-1) % left + 1;
				if (kill <= k)
					break;

				left--;
				kill--;
			}
			if (left == k)
			{
				printf("%d\n", m);
				ans[k] = m;
				break;
			}
			else
			{
				if (i % 2 == 0)
					m++;
				else
					m += k;
			}
			i++;
		}
	}
}
