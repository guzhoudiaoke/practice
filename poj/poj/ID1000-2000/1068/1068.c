/*
 * poj 1068
 * guzhoudiaoke@126.com
 * 2011-09-03
 */

#include <stdio.h>

int main()
{
	char parentheses[40];
	int t, n, i;
	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
	{
		int num, pre, j, k, m;
		scanf("%d", &n);
		
		pre = 0;
		m = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &num);
			for (k = 0; k < num-pre; k++)
				parentheses[m++] = '(';
			parentheses[m++] = ')';
			pre = num;
		}
		
		for (j = 0; j < m; j++)
		{
			if (parentheses[j] == ')')
			{
				int right = 1;
				for (k = j-1; k >= 0; k--)
				{
					if (parentheses[k] == '(')
						right --;
					else if (parentheses[k] == ')')
						right ++;
					if (right == 0)
					{
						printf("%d ", (j-k+1)/2);
						break;
					}
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}
