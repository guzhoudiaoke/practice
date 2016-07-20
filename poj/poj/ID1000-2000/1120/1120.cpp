/*
 * poj 1120
 * guzhoudiaoke
 * 2011-10-25
 */

#include <stdio.h>
#include <string.h>

int dna[16], days;
int map[22][22], ans[22][22];
const char character[4] = { '.', '!', 'X', '#' };

void simulation()
{
	int i, j, sum;
	for (i = 1; i <= 20; i++)
		for (j = 1; j <= 20; j++)
		{
			sum = map[i][j] + map[i-1][j] + map[i][j-1] + map[i+1][j] + map[i][j+1];
			ans[i][j] = map[i][j] + dna[sum];
			if (ans[i][j] > 3) ans[i][j] = 3;
			if (ans[i][j] < 0) ans[i][j] = 0;
		}

	for (i = 1; i <= 20; i++)
		for (j = 1; j <= 20; j++)
			map[i][j] = ans[i][j];
}

void solve()
{
	int i;
	for (i = 0; i < days; i++)
		simulation();
}

void disp_ans()
{
	int i, j;
	for (i = 1; i <= 20; i++)
	{
		for (j = 1; j <= 20; j++)
			printf("%c", character[ans[i][j]]);
		
		printf("\n");
	}
}

int main()
{
	int i, j;
	scanf("%d", &days);

	for (i = 0; i < 16; i++)
		scanf("%d", &dna[i]);
	
	memset(map, 0, sizeof(map));
	memset(ans, 0, sizeof(ans));

	for (i = 1; i <= 20; i++)
		for (j = 1; j <= 20; j++)
			scanf("%d", &map[i][j]);

	solve();
	disp_ans();

	return 0;
}