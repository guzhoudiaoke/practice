/*
 * poj 2151
 * guzhoudiaoke@126.com
 * 2011-09-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRO_NUM		30

int main()
{
	int m, t, n;		// m：问题数，t：队伍数，n：冠军队至少解出问题数
	
	// 前i 道题中能解出j 道的概率solve[i][j]
	double solve[PRO_NUM+1][PRO_NUM+1];
	double p_more_1;	// 解出不少于1 个题的概率
	double p_less_n;	// 解出小于n 个题的概率
	
	while (1)
	{
		scanf("%d%d%d", &m, &t, &n);
		if (m == 0) break;
		
		int i, j, k;
		double p[PRO_NUM+1];
		double p_more_1_all = 1.0, p_less_n_all = 1.0;
		
		for (i = 0; i < t; i++)
		{
			for (j = 1; j <=m; j++)
				for (k = 0; k <= j; k++)
					solve[j][k] = 1.0;
			
			for (j = 1; j <= m; j++)
				scanf("%lf", &p[j]);
			
			for (j = 1; j <= m; j++)
			{
				for (k = 1; k <=j; k++)
				{
					solve[j][0] *= (1-p[k]);
					solve[j][j] *= p[k];
				}
			}
			
			for (j = 2; j <= m; j++)
				for (k = 1; k < j; k++)
					solve[j][k] = solve[j-1][k] * (1-p[j]) + solve[j-1][k-1] * p[j];
			
			p_more_1 = 1 - solve[m][0];
			
			p_less_n = 0;
			for (j = 1; j < n; j++)
				p_less_n += solve[m][j];
			
			p_more_1_all *= p_more_1;
			p_less_n_all *= p_less_n;
		}
		
		printf("%.3lf\n", p_more_1_all - p_less_n_all);
	}
	
	return 0;
}
