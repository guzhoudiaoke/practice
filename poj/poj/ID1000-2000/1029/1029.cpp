/*
 * problem:	poj	1029
 * author:	guzhoudiaoke
 * time:	2011-10-08
 */

/*
 * 有n 个金币，其中之一是假的，重量有异，称k 次，找出它来。
 * 1.在等式两边出现过的肯定不是假的
 * 2.设A < B，在A，B 两边都出现过的肯定不是假的
 * 3.若coin[i]在A 边出现一次，让其减1，B 边出现一次，加1，不等式共wue 个，
 * 则coin[i] == BALANCE-wue 或 == BALANCE+wue 者可能是假的
 * 4.若上面工作没找出假的来，若仅有一个没有出现在式子两边，则它是假的
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BALANCE = 1000;

int main()
{
	int *coin, *weight, n, k, p, i, num, bad, wue = 0;
	char result;
	
	scanf("%d %d", &n, &k);
	coin = (int *)malloc(sizeof(int) * (n+1));
	weight = (int *)malloc(sizeof(int) * (n+1));
	
	for (i = 1; i <= n; i++)
		coin[i] = 0;
	
	while (k--)
	{
		scanf("%d", &p);
		for (i = 1; i <= p*2; i++)
			scanf("%d\n", &weight[i]);
		scanf("%c", &result);
		if (result == '<')
		{
			for (i = 1; i <= p; i++)
			{
				if (coin[weight[i]] == BALANCE)		// 肯定不是bad icon
					continue;
				if (coin[weight[i]] && coin[weight[i]] > BALANCE)		// 在不等号两边都出现过，肯定不是bad icon
				{
					coin[weight[i]] = BALANCE;
					continue;
				}
				if (coin[weight[i]] == 0)
					coin[weight[i]] = BALANCE;
				coin[weight[i]]--;
			}
			for (i = p+1; i <= p*2; i++)
			{
				if (coin[weight[i]] == BALANCE)
					continue;
				if (coin[weight[i]] && coin[weight[i]] < BALANCE)		// 在不等号两边都出现过，肯定不是bad icon
				{
					coin[weight[i]] = BALANCE;
					continue;
				}
				if (coin[weight[i]] == 0)
					coin[weight[i]] = BALANCE;
				coin[weight[i]]++;
			}
			wue++;
		}
		else if (result == '=')
		{
			for (i = 1; i <= p*2; i++)
				coin[weight[i]] = BALANCE;
		}
		else if (result == '>')
		{
			for (i = 1; i <= p; i++)
			{
				if (coin[weight[i]] == BALANCE)
					continue;
				if (coin[weight[i]] && coin[weight[i]] < BALANCE)		// 在不等号两边都出现过，肯定不是bad icon
				{
					coin[weight[i]] = BALANCE;
					continue;
				}
				if (coin[weight[i]] == 0)
					coin[weight[i]] = BALANCE;
				coin[weight[i]]++;
			}
			for (i = p+1; i <= p*2; i++)
			{
				if (coin[weight[i]] == BALANCE)
					continue;
				if (coin[weight[i]] && coin[weight[i]] > BALANCE)		// 在不等号两边都出现过，肯定不是bad icon
				{
					coin[weight[i]] = BALANCE;
					continue;
				}
				if (coin[weight[i]] == 0)
					coin[weight[i]] = BALANCE;
				coin[weight[i]]--;
			}
			wue++;
		}
	}

	num = 0;
	bad = 0;
	int noweight = 0;
	int num_noweight = 0;
	for (i = 1; i <= n; i++)
	{
		if (coin[i] && (coin[i] == BALANCE-wue || coin[i] == BALANCE+wue))
		{
			num++;
			bad = i;
		}
		else if (coin[i] == 0)
		{
			num_noweight++;
			noweight = i;
		}
	}

	if (num == 1)
		printf("%d\n", bad);
	else if (num_noweight == 1)
		printf("%d\n", noweight);
	else
		printf("0\n");

	free(coin);
	free(weight);
	return 0;
}