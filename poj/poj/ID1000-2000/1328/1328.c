/*
 * poj 1328
 * guzhoudiaoke@126.com
 * 2011-09-03
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct range {
	double left;
	double right;
} range;

int comp_range_left(const void *a, const void *b)
{
	double delt = ((range *)a)->right - ((range *)b)->right;
	
	if (delt == 0.0)
		return 0;
	else if (delt < 0.0)
		return -1;
	return 1;
}

int main()
{
	int n, d, x, y;
	range *r;
	
	int c = 0;
	while (1)
	{
		c ++;
		scanf("%d%d", &n, &d);
		if (n == 0 && d == 0)
			return 0;
		
		r = (range *)malloc(sizeof(range) * n);
		if (!r)	return -1;
		
		int i;
		int imposible = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			if (y > d || d <= 0 || y < 0)
			{
				imposible = 1;
			}
			else if (!imposible)
			{
				double delt_x = sqrt((double)(d*d - y*y));
				r[i].left = x - delt_x;
				r[i].right = x + delt_x;
			}
		}
		
		if (imposible)
			printf("Case %d: -1\n", c);
		else
		{
			int j = 0;
			int num = 1;
			
			qsort(r, n, sizeof(range), comp_range_left);
			
			for (i = 1; i < n; i++)
			{
				if (r[i].left > r[j].right)
				{
					num ++;
					j = i;
				}
			}
			
			printf("Case %d: %d\n", c, num);
		}
		
		free (r);
	}
}
