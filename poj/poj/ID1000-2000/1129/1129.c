/*
 * poj 1129
 * guzhoudiaoke@126.com
 * 2011-09-12
 */

#include <stdio.h>
#include <string.h>

int n;
int map[27][27];
int x[27];

void get_map()
{
	char str[29];
	int i, j;
	memset(map, 0, sizeof(map));

	for (i = 1; i <= n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);
		for (j = 2; j < len; j++)
		{
			map[i][str[j] - 'A' + 1] = 1;
		}
	}
}

int can_color(int k)
{
	int i;
	for (i = 1; i <= n; i++)
		if (map[i][k] == 1 && x[i] == x[k])
			return 0;
	return 1;
}

int back_track(int depth, int color_num)
{
	if (depth > n)
		return 1;
	else
	{
		int i;
		for (i = 1; i <= color_num; i++)
		{
			x[depth] = i;
			if (can_color(depth))
				if (back_track(depth + 1, color_num))
					return 1;
		}
	}

	return 0;
}

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		get_map();
		
		memset(x, 0, sizeof(x));

		int i;
		for (i = 1; i <= n; i++)
		{
			if (back_track(0, i))
				break;
		}

		if (i == 1)
			printf("1 channel needed.\n");
		else
			printf("%d channels needed.\n", i);
	}
	return 0;
}
