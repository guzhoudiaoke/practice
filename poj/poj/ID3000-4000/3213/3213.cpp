/*
 * problem:	poj 3213
 * author:	guzhoudiaoke
 * time:	2011-10-05
 */

#include <stdio.h>

int a[1001][1001], b[1001][1001], c[1001][1001];
int n, p, m;
int sum_rb[1001], sum_rc[1001];
int wrong_r, wrong_c;

int main()
{
	int i, j, sum;
	scanf("%d%d%d", &n, &p, &m);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= p; j++)
			scanf("%d", &a[i][j]);

	for (i = 1; i <= p; i++)
	{
		sum_rb[i] = 0;
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &b[i][j]);
			sum_rb[i] += b[i][j];
		}
	}

	for (i = 1; i <= n; i++)
	{
		sum_rc[i] = 0;
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &c[i][j]);
			sum_rc[i] += c[i][j];
		}
	}

	wrong_r = wrong_c = 0;

	for (i = 1; i <= n; i++)
	{
		sum = 0;
		for (j = 1; j <= p; j++)
			sum += (a[i][j] * sum_rb[j]);
		if (sum != sum_rc[i])
		{
			wrong_r = i;
			break;
		}
	}

	if (wrong_r)
	{
		for (j = 1; j <= m; j++)
		{
			sum = 0;
			for (i = 1; i <= p; i++)
				sum += a[wrong_r][i] * b[i][j];
			
			if (sum != c[wrong_r][j])
			{
				wrong_c = j;
				break;
			}
		}
	}

	if (wrong_r == 0)
		printf("Yes\n");
	else
		printf("No\n%d %d\n%d\n", wrong_r, wrong_c, sum);

	return 0;
}