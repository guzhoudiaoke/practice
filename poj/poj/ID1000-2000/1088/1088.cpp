/*
 * poj 1088
 * guzhoudiaoke
 * 2011-10-13
 */

#include <stdio.h>
#include <string.h>

int height[101][101], length[101][101], r, c;
int move[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int max(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int row, int col)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		int new_row = row + move[i][0];
		int new_col = col + move[i][1];
		if (new_row >= 1 && new_row <= r && new_col >= 1 && new_col <= c)
		{
			if (height[row][col] > height[new_row][new_col])
			{
				if (length[new_row][new_col])
					length[row][col] = max(length[row][col], 1 + length[new_row][new_col]);
				else
					length[row][col] = max(length[row][col], 1 + dfs(new_row, new_col));
			}
		}
		length[row][col] = max(1, length[row][col]);
	}

	return length[row][col];
}

int main()
{
	int i, j;
	scanf("%d %d", &r, &c);
	
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
		{
			scanf("%d", &height[i][j]);
			length[i][j] = 0;
		}

	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			dfs(i, j);

	int max = 0;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			if (length[i][j] > max)
				max = length[i][j];

	printf("%d\n", max);

	return 0;
}