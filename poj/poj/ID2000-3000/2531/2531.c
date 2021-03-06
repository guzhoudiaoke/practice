/*
 * poj 2531
 * guzhoudiaoke@126.com
 * 2011-09-11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nodes[21][21];	// 数据流量
int divide[21];		// 为1，表示在1组，为0 表示在0组
int n;			// 节点个数
int max;		// 最大流量

// 在当前子网间流量为data 的情况下，将no 分到子网1
void dfs(int no, int data)
{
	int i, t = data;
	
	divide[no] = 1;
	for (i = 1; i <= n; i++)
	{
		if (divide[i] == 0)
			t += nodes[i][no];
		else
			t -= nodes[i][no];
	}

	if (t > max)
		max = t;

	for (i = no+1; i <= n; i++)
	{
		if (t > data)
		{
			dfs(i, t);
			divide[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &nodes[i][j]);

	max = 0;
	memset(divide, 0, sizeof(divide));	// 开始全分到组0
	dfs(1, 0);

	printf("%d", max);

	return 0;
}
