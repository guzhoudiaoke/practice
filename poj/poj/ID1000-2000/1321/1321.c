/*
 * poj 1321
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>

char map[8][9];
int visited[8];
int n, k, c;

int DFS(int row, int placed)
{
	if (placed == k)
	{
		c++;
		return;
	}
	if (row >= n)
		return;
	int i;
	for (i = 0; i < n; i++)
		if (map[row][i] == '#' && visited[i] == 0)
		{
			visited[i] = 1;
			DFS(row+1, placed+1);
			visited[i] = 0;
		}
	DFS(row+1, placed);
}


int main()
{
	int i, j;
	while (1)
	{
		scanf("%d%d", &n, &k);
		if (n == -1 && k == -1)
			break;

		for (i = 0; i < n; i++)
			scanf("%s", map[i]);
		
		for (i = 0; i < n; i++)
			visited[i] = 0;
		c = 0;
		DFS(0, 0);
		printf("%d\n", c);
	}

	return 0;
}
