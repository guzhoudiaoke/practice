/*
 * poj 2488
 * guzhoudiaoke@126.com
 * 2011-09-08
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int move[8][2] = {
	{-1,-2}, {1,-2}, {-2,-1}, {2,-1},
	{-2, 1}, {2, 1}, {-1, 2}, {1, 2}
};

int sn, row, col, num;
int *map, *visited, *way;

int DFS(int v)
{
	way[sn++] = v;
	if (sn == num)
		return 1;
	int i;
	for (i = 0; i < 8; i++)
	{
		int new_row = v / col + move[i][0];
		int new_col = v % col + move[i][1];
		int next = -1;
		if (new_row >= 0 && new_row < row && new_col >= 0 && new_col < col)
			next = new_row*col + new_col;
		if (next >= 0 && visited[next] == 0)
		{
			
			visited[v] = 1;
			if (DFS(next)) 
				return 1;
			visited[v] = 0;
			sn--;
		}
	}
	
	return 0;
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Scenario #%d:\n", i);
		scanf("%d%d", &row, &col);
		num = col * row;

		map = (int *)malloc(sizeof(int) * num);
		visited = (int *)malloc(sizeof(int) * num);
		way = (int *)malloc(sizeof(int) * num);

		for (j = 0; j < row*col; j++) map[j] = j;
		memset(visited, 0, sizeof(int)*num);
		memset(way, 0, sizeof(int)*num);

		sn = 0;	
		if (!DFS(0))
			printf("impossible");
		else
			for (j = 0; j < num; j++)
				printf("%c%d", 'A'+way[j]%col, way[j]/col+1);
		
		printf("\n\n");
	}
	return 0;
}
