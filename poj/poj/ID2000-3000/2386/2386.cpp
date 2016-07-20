#include <stdio.h>
#include <string.h>

int n, m, ans;
char map[101][101];
bool visited[101][101];

int move[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
	{1, 1}, {1, 0}, {1, -1}, {0, -1},
};

bool out_map(int r, int c)
{
	if (r < 0 || c < 0 || r >= n || c >= m)
		return true;
	return false;
}

void dfs(int r, int c)
{
	int i, row, col;
	visited[r][c] = true;
	for (i = 0; i < 8; i++)
	{
		row = r + move[i][0];
		col = c + move[i][1];
		if (!out_map(row, col) && map[row][col] == 'W' && !visited[row][col])
		{
			visited[row][col] = true;
			dfs(row, col);
		}
	}
}

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", map[i]);

	memset(visited, false, sizeof(visited));
	ans = 0;
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'W' && !visited[i][j]) {
				dfs(i, j);
				ans++;
			}
	
	printf("%d\n", ans);

	return 0;
}
