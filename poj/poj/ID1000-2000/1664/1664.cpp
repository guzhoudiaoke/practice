/*
 * problem:	poj	1664
 * author:	guzhoudiaoke
 * time:	2011-10-15
 */

#include <stdio.h>

int t, m, n, ans;

void dfs(int depth, int num, int left)
{
	if (depth == n-1)
	{
		if (left >= num)
			ans++;
	}
	else
	{
		for (int i = num; i <= m/(n-depth); i++)
			dfs(depth+1, i, left-i);
	}
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &m, &n);
		ans = 0;
		if (n == 1)
			ans = 1;
		else
		{
			for (int i = 0; i <= m/n; i++)
				dfs(1, i, m-i);
		}
		printf("%d\n", ans);
	}

	return 0;
}