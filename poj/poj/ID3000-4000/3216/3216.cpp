/*
 * problem:	poj 3216
 * author:	guzhoudiaoke
 * time:	2011-10-05
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH	10000000

typedef struct task {
	int p;
	int t;
	int d;
} task;

int q, m, dis[21][21], on_time[201][201], color[201], match[201];
task tasks[201];
int ans;

void floyd()
{
	int u, v, w;
	for (u = 1; u <= q; u++)
		for (v = 1; v <= q; v++)
			for (w = 1; w <= q; w++)
				if (dis[v][u] + dis[u][w] < dis[v][w])
					dis[v][w] = dis[v][u] + dis[u][w];
}

void check_on_time()
{
	int i, j;
	for (i = 1; i <= m; i++)
	{
		int finish_i = tasks[i].t + tasks[i].d;
		for (j = 1; j <= m; j++)
		{
			if (finish_i + dis[tasks[i].p][tasks[j].p] <= tasks[j].t)
				on_time[i][j] = 1;
		}
	}
}

int find(int right_i, int n)
{
	int i;
	for (i = 1; i <= m; i++)
		if (! color[i] && on_time[right_i][i])
		{
			color[i] = 1;
			if (match[i] == -1 || find(match[i], m))
			{
				match[i] = right_i;
				return 1;
			}
		}

	return 0;
}

void solve()
{
	int i;
	for (i = 1; i <= m; i++)
		match[i] = -1;
	for (i = 1; i <= m; i++)
	{
		memset(color, 0, sizeof(color));
		if (find(i, m))
			ans++;
	}
}

int main()
{
	int i, j;

	while (1)
	{
		scanf("%d %d", &q, &m);
		if (q == 0) break;

		for (i = 1; i <= q; i++)
			for (j = 1; j <= q; j++)
			{
				scanf("%d", &dis[i][j]);
				if (dis[i][j] == -1)
					dis[i][j] = MAX_LENGTH;
			}

		for (i = 1; i <= m; i++)
			scanf("%d%d%d", &tasks[i].p, &tasks[i].t, &tasks[i].d);

		ans = 0;

		floyd();
		memset(on_time, 0, sizeof(on_time));
		check_on_time();
		solve();

		printf("%d\n", m-ans);
	}

	return 0;
}