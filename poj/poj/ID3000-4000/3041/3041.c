/*
 * poj 3041
 * guzhoudiaoke@126.com
 * 2011-09-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[501][501];
int color[501];
int match[501];
int n, k;

int find(int right_i)
{
	int i;
	for (i = 1; i <= n; i++)
		if (!color[i] && map[right_i][i])
		{
			color[i] = 1;
			if (match[i] == 0 || find(match[i]))
			{
				match[i] = right_i;
				return 1;
			}
		}

	return 0;
}

int hungary()
{
	int i, re = 0;
	
	for (i = 1; i <= n; i++)
	{
		memset(color, 0, sizeof(color));
		if (find(i))
			re++;
	}

	return re;
}

int main()
{
	int i, r, c;
	scanf("%d%d", &n, &k);
	
	memset(map, 0, sizeof(map));
	memset(match, 0, sizeof(match));

	for (i = 1; i <= k; i++)
	{
		scanf("%d%d", &r, &c);
		map[r][c] = 1;
	}

	printf("%d\n", hungary());

	return 0;
}

