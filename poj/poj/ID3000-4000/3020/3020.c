/*
 * poj 3020
 * guzhoudiaoke@126.com
 * 2011-09-19
 */

#include <stdio.h>
#include <string.h>

int interest[41][11];
int map[402][402];
int match[402];
int color[402];
int w, h;
int n;

int move[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

int find(int right_i)
{
	int i;
	for (i = 1; i <= n; i++)
		if (color[i] == 0 && map[right_i][i])
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
	int t, i, j, k;
	char ch;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d%d", &h, &w);
		getchar();
		
		n = 0;
		memset(map, 0, sizeof(map));
		memset(match, 0, sizeof(match));
		memset(interest, 0, sizeof(interest));

		for (i = 1; i <= h; i++)
		{
			for (j = 1; j <= w; j++)
			{
				scanf("%c", &ch); 
				if (ch == '*')
					interest[i][j] = ++n;
			}
			getchar();
		}

		for (i = 1; i <= h; i++)
			for (j = 1; j <= w; j++)
				if (interest[i][j])
					for (k = 0; k < 4; k++)
					{
						int r = i + move[k][0];
						int c = j + move[k][1];
						if (interest[r][c])
							map[interest[r][c]][interest[i][j]] = 1;
					}

		printf("%d\n", n - hungary()/2);
	}

	return 0;
}
