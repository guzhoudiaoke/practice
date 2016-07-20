/*
 * poj 1013
 * guzhoudiaoke
 * 2011-10-18
 */

#include <stdio.h>
#include <string.h>

#define NOTWEIGHT	0
#define EVEN		100

int coin[12], wue;

void judge(char *left, char *right, char *result)
{
	int i, len = strlen(left);
	if (strcmp(result, "even") == 0)
	{
		for (i = 0; i < len; i++)
			coin[left[i] - 'A'] = EVEN;
		for (i = 0; i < len; i++)
			coin[right[i] - 'A'] = EVEN;
	}
	else if (strcmp(result, "up") == 0)
	{
		for (i = 0; i < len; i++)
		{
			int index = left[i] - 'A';
			if (coin[index] == EVEN) continue;
			if (coin[index] != NOTWEIGHT && coin[index] < EVEN)
			{
				coin[index] = EVEN;
				continue;
			}
			if (coin[index] == NOTWEIGHT)
				coin[index] = EVEN;
			coin[index]++;
		}
		for (i = 0; i < len; i++)
		{
			int index = right[i] - 'A';
			if (coin[index] == EVEN) continue;
			if (coin[index] != NOTWEIGHT && coin[index] > EVEN)
			{
				coin[index] = EVEN;
				continue;
			}
			if (coin[index] == NOTWEIGHT)
				coin[index] = EVEN;
			coin[index]--;
		}
		wue++;
	}
	else if (strcmp(result, "down") == 0)
	{
		for (i = 0; i < len; i++)
		{
			int index = left[i] - 'A';
			if (coin[index] == EVEN) continue;
			if (coin[index] != NOTWEIGHT && coin[index] > EVEN)
			{
				coin[index] = EVEN;
				continue;
			}
			if (coin[index] == NOTWEIGHT)
				coin[index] = EVEN;
			coin[index]--;
		}
		for (i = 0; i < len; i++)
		{
			int index = right[i] - 'A';
			if (coin[index] == EVEN) continue;
			if (coin[index] != NOTWEIGHT && coin[index] < EVEN)
			{
				coin[index] = EVEN;
				continue;
			}
			if (coin[index] == NOTWEIGHT)
				coin[index] = EVEN;
			coin[index]++;
		}
		wue++;
	}
}

int solve(int &counterfeit)
{
	int re = 0, i, num;

	num = 0;
	for (i = 0; i < 12; i++)
		if (coin[i] != NOTWEIGHT && (coin[i] == EVEN-wue || coin[i] == EVEN + wue))
		{
			num++;
			counterfeit = i;
		}
	if (num == 1)
		return coin[counterfeit];

	num = 0;
	for (i = 0; i < 12; i++)
		if (coin[i] == NOTWEIGHT)
		{
			num++;
			counterfeit = i;
		}
	if (num == 1)
		return coin[counterfeit];
}

int main()
{
	int t, i, counterfeit, r;
	char left[12], right[12], result[5];

	scanf("%d", &t);
	while (t--)
	{
		for (i = 0; i < 12; i++)
			coin[i] = NOTWEIGHT;
		wue = 0;

		for (i = 0; i < 3; i++)
		{
			scanf("%s %s %s", left, right, result);
			judge(left, right, result);
		}

		r = solve(counterfeit);
		if (r < EVEN)
			printf("%c is the counterfeit coin and it is light.\n", counterfeit+'A');
		else
			printf("%c is the counterfeit coin and it is heavy.\n", counterfeit+'A');
	}

	return 0;
}