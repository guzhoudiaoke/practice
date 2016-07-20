/*
 * poj 2676
 * guzhoudiaoke@126.com
 * 2011-09-11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[9][10];

typedef struct cell_node{
	int row;
	int col;
	int freedom;
	int may_place[10];
} cell_node;

cell_node cells[81];

int get_freedom(int r, int c, int place[10])
{
	int i, j;
	for (i = 0; i < 10; i++)
		place[i] = 1;
	for (i = 0; i < 9; i++)
		place[map[r][i]-'0'] = 0;
	for (i = 0; i < 9; i++)
		place[map[i][c]-'0'] = 0;
	
	c /= 3; c *= 3;
	r /= 3; r *= 3;
	for (i = r; i < r+3; i++)
		for (j = c; j < c+3; j++)
			place[map[i][j]-'0'] = 0;
	j = 0;
	for (i = 1; i < 10; i++)
		if (place[i])
			j++;

	return j;
}

int cmp_cell(const void *a, const void *b)
{
	return ((cell_node *)a)->freedom - ((cell_node *)b)->freedom;
}

void fill_freedom_1()
{
	int i = 0;
	while (cells[i].freedom == 1)
	{
		int r = cells[i].row;
		int c = cells[i].col;
		int j;
		for (j = 1; j <= 9; j++)
			if (cells[i].may_place[j] == 1)
				break;
		map[r][c] = j + '0';

		i++;
	}
}

int finish()
{
	int i, j, k;
	int fill[10];
	
	
	for (i = 0; i < 9; i++)
	{
		for (k = 1; k <= 9; k++)
			fill[k] = 0;
		for (j = 0; j < 9; j++)
			fill[map[i][j]-'0'] ++;
		for (k = 1; k <= 9; k++)
			if (fill[k] != 1)
				return 0;
		
		for (k = 1; k <= 9; k++)
			fill[k] = 0;
		for (j = 0; j < 9; j++)
			fill[map[j][i]-'0'] ++;
		for (k = 1; k <= 9; k++)
			if (fill[k] != 1)
				return 0;
	}
	
	int r, c;
	for (r = 0; r < 9; r += 3)
		for (c = 0; c < 9; c += 3)
		{
			for (k = 1; k <= 9; k++)
				fill[k] = 0;
			for (i = r; i < r+3; i++)
				for (j = c; j < c+3; j++)
					fill[map[j][i]-'0'] ++;
			for (k = 1; k <= 9; k++)
				if (fill[k] != 1)
					return 0;
		}
		
	return 1;
}

int finished = 0;
void dfs(int start, int to)
{
	int i, j;
	if (start > to)
		return;

	int r = cells[start].row;
	int c = cells[start].col;
	int place[10];
	int n = get_freedom(r, c, place);

	for (j = 1; j <= 9; j++)
	{
		if (place[j])
		{
			map[r][c] = j + '0';
			dfs(start+1, to);
			if (finish())
				return;
			else
				map[r][c] = '0';
		}
	}
}

int main()
{
	int n, i, j;
	scanf("%d", &n);

	while (n--)
	{
		for (i = 0; i < 9; i++)
			scanf("%s", map[i]);
			
		
		int cells_size;
		while (1)
		{
			memset(cells, 0, sizeof(cells));
			int k = 0;
			finished = 0;
			for (i = 0; i < 9; i++)
				for (j = 0; j < 9; j++)
				{
					if (map[i][j] == '0')
					{
						cells[k].row = i;
						cells[k].col = j;
						cells[k].freedom = get_freedom(i, j, cells[k].may_place);
						k++;
					}
				}
			
			cells_size = k - 1;	
			qsort(cells, k, sizeof(cell_node), cmp_cell);	
			if (cells[0].freedom != 1)
				break;
			fill_freedom_1();
		}
		
		dfs(0, cells_size);
	
		for (i = 0; i < 9; i++)
		{
			printf("%s\n", map[i]);
		}
	}

	return 0;
}
