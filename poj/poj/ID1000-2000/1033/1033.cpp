/*
 * poj 1088
 * guzhoudiaoke
 * 2011-10-13
 */

#include <stdio.h>
#include <string.h>

int position[10001];
bool visited[10001];
int n, flag, free_c;

int find_free()
{
	int i;
	for (i = n; i >= 1; i--)
		if (position[i] == 0)
			break;
	return i;
}

void move(int from, int to)
{
	position[to] = position[from];
	position[from] = 0;
	printf("%d %d\n", from, to);
}

void dfs(int from, int to)
{
	if (position[to] != 0)
	{
		if (visited[to] == false)
		{
			visited[from] = true;
			dfs(to, position[to]);
		}
		else
		{
			flag = to;
			free_c = find_free();
			move(to, free_c);
		}
	}

	if (from != flag)
		move(from, to);
	else
		move(free_c, to);
}

void solve()
{
	int i, move = 0;
	for (i = 1; i <= n; i++)
	{
		if (position[i] == 0 || position[i] == i)
			continue;
		dfs(i, position[i]);
		move++;
	}

	if (! move)
		printf("No optimization needed\n");
}

int main()
{
	int k, num_cluster, cluster, i, j, cur = 1;
	scanf("%d %d", &n, &k);
	memset(position, 0, sizeof(position));
	memset(visited, false, sizeof(visited));
	flag = 0;

	for (i = 1; i <= k; i++)
	{
		scanf("%d", &num_cluster);
		for (j = 1; j <= num_cluster; j++)
		{
			scanf("%d", &cluster);
			position[cluster] = cur++;
		}
	}

	solve();

	return 0;
}
