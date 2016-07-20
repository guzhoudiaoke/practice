#include <stdio.h>

#define INF	1000000

int n, m, ans, min_v[21], min_s[21];

void dfs(int d, int r, int h, int v, int s)
{
	int i, j, t;
	if (d == 0)
	{
		if (v == n && s < ans)
			ans = s;
	}
	else
	{
		if (v + min_v[d] > n || s + min_s[d] > ans || 2*(n-v)/r + s >= ans)
			return;
		for (i = r-1; i >= d; i--)
		{
			if (d == m)
				s = i*i;
			t = (n-v-min_v[d-1]) / (i*i);
			if (h-1 < t)
				t = h-1;
			for (j = t; j >= d; j--)
				dfs(d-1, i, j, v+i*i*j, s+i*j*2);
		}
	}
}

int main()
{
	int i, j;
	min_s[0] = min_v[0] = 0;

	for (i = 1; i <= 20; i++) 
	{
		min_s[i] = min_s[i-1] + 2*i*i;
		min_v[i] = min_v[i-1] + i*i*i;
	}
	
	scanf("%d %d", &n, &m);
	ans = INF;
	dfs(m, n+1, n+1, 0, 0);

	if (ans != INF)
		printf("%d\n", ans);
	else
		printf("0\n");

	return 0;
}

