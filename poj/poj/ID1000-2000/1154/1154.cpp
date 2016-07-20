/*
 * poj 1154
 * guzhoudiaoke
 * 2011-10-26
 */

#include <stdio.h>
#include <string.h>

char board[21][21];
int r, c, step;
bool visited[26];
const int move[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool out_map(int row, int col)
{
	if (row < 0 || col < 0 || row >= r || col >= c)
		return true;

	return false;
}

void dfs(int r0, int c0, int s0)
{
	for (int i = 0; i < 4; i++)
	{
		int row = r0 + move[i][0];
		int col = c0 + move[i][1];
		if (!out_map(row, col) && !visited[board[row][col] - 'A'])
		{
			visited[board[row][col] - 'A'] = true;
			if (s0+1 > step) step = s0+1;
			dfs(row, col, s0+1);
			visited[board[row][col] - 'A'] = false;
		}
	}
}

int main()
{
	int i;
	scanf("%d %d", &r, &c);

	for (i = 0; i < r; i++)
		scanf("%s", board[i]);

	step = 1;
	memset(visited, false, sizeof(visited));
	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	printf("%d\n", step);

	return 0;
}