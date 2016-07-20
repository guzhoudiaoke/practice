/*
 * poj 3009
 * guzhoudiaoke@126.com
 * 2011-09-08
 */

#include <stdio.h>

#define VACANT	0
#define BLOCK	1
#define START	2
#define GOAL	3

int move[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int width, height;
int map[20][20];

int out_map(int row, int col)
{
	if (row < 0 || col < 0 || row >= height || col >= width)
		return 1;
	return 0;
}

int min_step;

int DFS(int st_row, int st_col, int step)
{
	if (step >= 10)
		return;
	
	int next_row, next_col, i;
	for (i = 0; i < 4; i++)
	{
		next_row = st_row + move[i][0];			// 前进
		next_col = st_col + move[i][1];
		
		if (out_map(next_row, next_col))		// 第一步就出界
			continue;
		
		if (map[next_row][next_col] == BLOCK)		// 向前第一步就是墙，该情况不允许
			continue;

		while (map[next_row][next_col] == VACANT)	// 前方可行
		{
			next_row += move[i][0];			// 前进
			next_col += move[i][1];
			if (out_map(next_row, next_col))	// 出界
				break;
		}
		
		if (!out_map(next_row, next_col))		// 没出界
		{
			if (map[next_row][next_col] == GOAL)	// 到达目标点
			{
				if (step + 1 < min_step)
					min_step = step + 1;
			}
		
			if (map[next_row][next_col] == BLOCK)	// 到达障碍块
			{
				map[next_row][next_col] = VACANT;
				DFS(next_row-move[i][0], next_col-move[i][1], step+1);
				map[next_row][next_col] = BLOCK;
			}
		}
	}
}

int main()
{
	int start_row, start_col;
	while (1)
	{
		scanf("%d%d", &width, &height);
		if (width == 0 && height == 0)
			break;
		
		int i, j;
		for (i = 0; i < height; i++)
			for (j = 0; j < width; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == START)
				{
					start_row = i; 
					start_col = j;
					map[i][j] = VACANT;
				}
			}
		
		min_step = 11;
		DFS(start_row, start_col, 0);
		if (min_step <= 10)
			printf("%d\n", min_step);
		else
			printf("-1\n");
	}
	
	return 0;
}
