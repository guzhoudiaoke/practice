/*
 * problem:	poj	1029
 * author:	guzhoudiaoke
 * time:	2011-10-08
 */

/*
 * ��n ����ң�����֮һ�Ǽٵģ��������죬��k �Σ��ҳ�������
 * 1.�ڵ�ʽ���߳��ֹ��Ŀ϶����Ǽٵ�
 * 2.��A < B����A��B ���߶����ֹ��Ŀ϶����Ǽٵ�
 * 3.��coin[i]��A �߳���һ�Σ������1��B �߳���һ�Σ���1������ʽ��wue ����
 * ��coin[i] == BALANCE-wue �� == BALANCE+wue �߿����Ǽٵ�
 * 4.�����湤��û�ҳ��ٵ�����������һ��û�г�����ʽ�����ߣ������Ǽٵ�
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
				if (coin[weight[i]] == BALANCE)		// �϶�����bad icon
					continue;
				if (coin[weight[i]] && coin[weight[i]] > BALANCE)		// �ڲ��Ⱥ����߶����ֹ����϶�����bad icon
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
				if (coin[weight[i]] && coin[weight[i]] < BALANCE)		// �ڲ��Ⱥ����߶����ֹ����϶�����bad icon
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
				if (coin[weight[i]] && coin[weight[i]] < BALANCE)		// �ڲ��Ⱥ����߶����ֹ����϶�����bad icon
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
				if (coin[weight[i]] && coin[weight[i]] > BALANCE)		// �ڲ��Ⱥ����߶����ֹ����϶�����bad icon
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