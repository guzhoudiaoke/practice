/*
 * poj 1308
 * guzhoudiaoke@126.com
 * 2011-11-09
 */

#include <stdio.h>
#include <string.h>

int map[20][20], out[20], in[20], n;
bool visited[20], is_tree;

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < 20; i++)
	{
		if (map[start][i])
		{
			if (visited[i])
			{
				is_tree = false;
				return;
			}

			dfs(i);
		}
	}
}

bool get_result()
{
	if (n == 0)
	{
		is_tree = true;
		return true;
	}
	int start = -1;
	for (int i = 0; i < 20; i++)
	{
		if (in[i] > 1)
		{	
			is_tree = false;
			return false;
		}
		if (out[i] && in[i] == 0)
		{
			if (start != -1)
			{
				is_tree = false;
				return false;
			}
			start = i;
		}
	}
	
	if (start == -1) { 
		is_tree = false;
		return false;
	}

	dfs(start);
	if (!is_tree)
		return false;
	
	for (int i = 0; i < 20; i++)
		if ((in[i] || out[i]) && !visited[i])
		{
			is_tree = false;
			return false;
		}
	
	return true;
}

int main()
{
	int a, b, solve, t = 1;
	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		memset(visited, false, sizeof(visited));
		is_tree = true;
	
		scanf("%d %d", &a, &b);
		if (a < 0 && b < 0) break;
		n = 0;

		while (1)
		{
			if (a == 0 && b == 0)
			{
				get_result();
				if (is_tree)
					printf("Case %d is a tree.\n", t);
				else
					printf("Case %d is not a tree.\n", t);
				break;
			}
			else
			{
				map[a][b] = true;
				out[a]++;
				in[b]++;
				scanf("%d %d", &a, &b);
				n++;
			}
		}
		t++;
	}

	return 0;
}
