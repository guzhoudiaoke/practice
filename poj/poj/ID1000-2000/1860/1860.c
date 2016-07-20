/*
 * poj 1860
 * guzhoudiaoke@126.com
 * 2011-09-15
 */

#include <stdio.h>
#include <string.h>

#define INF	10000

float r[101][101], c[101][101];

// s：开始拥有的货币类型
// v：开始拥有的货币数量
// n: 城市流通货币种类数
int bellman_ford(int s, float v, int n)
{

	int i, j, k;
	float d[101];
	// 初始化
	for (i = 1; i <= n; i++)
		d[i] = -INF;
	d[s] = v;
	
	// 循环n-1 次
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= n; j++)
			for (k  = 1; k <= n; k++)
				if (r[j][k] && d[j] != -INF)
				{
					float change = (d[j] - c[j][k]) * r[j][k];
					if (change >= 0 && d[k] < change)
						d[k] = change;
				}
	}

	for (j = 1; j <= n; j++)
		for (k = 1; k <= n; k++)
			if (r[j][k] && d[j] != -INF)
			{
				float change = (d[j]-c[j][k]) * r[j][k];
				if (change >= 0 && change > d[k])
					return 1;
			}
	
	if (d[s] > v)
		return 1;
	
	return 0;
}

int main()
{
	int n, m, s, i, j, a, b;
	float v;

	scanf("%d%d%d%f", &n, &m, &s, &v);
	memset(r, 0, sizeof(r));

	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		scanf("%f%f%f%f", &r[a][b], &c[a][b], &r[b][a], &c[b][a]);
	}
	
	if (bellman_ford(s, v, n))
		printf("YES");
	else
		printf("NO");
		
	return 0;
}

