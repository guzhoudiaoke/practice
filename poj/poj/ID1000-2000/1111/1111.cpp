/*
 * poj 1111
 * guzhoudiaoke@126.com
 * 2011-11-11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[21][21];
int m, n, r, c, ans;
bool visited[21][21];

const int move[8][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1},
	{-1,-1}, {-1,1}, {1, 1}, {1, -1},
};

bool out_of_map(int r, int c)
{
	if (r < 0 || c < 0 || r >= m || c >= n)
		return true;

	return false;
}

void dfs(int r, int c)
{
	visited[r][c] = true;
	
	ans += 4;
	for (int i = 0; i < 4; i++)
	{
		int rn = r + move[i][0];
		int cn = c + move[i][1];
		if (! out_of_map(rn, cn) && map[rn][cn] == 'X')
			ans--;
	}

	for (int i = 0; i < 8; i++)
	{
		int rn = r + move[i][0];
		int cn = c + move[i][1];
		if (! out_of_map(rn, cn) && !visited[rn][cn] && map[rn][cn] == 'X')
			dfs(rn, cn);
	}
}

int main()
{
	while (1)
	{
		scanf("%d %d %d %d", &m, &n, &r, &c);
		if (m == 0 && n == 0 && r == 0 && c == 0) break;

		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		ans = 0;

		for (int i = 0; i < m; i++)
			scanf("%s", map[i]);

		dfs(r-1, c-1);

		printf("%d\n", ans);
	}
}
