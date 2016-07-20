/*
* poj 3349
* guzhoudiaoke@126.com
* 2011-09-05
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 149997
#define MAX 149998

typedef struct snowflake {
	int len[6];
} snowflake;

typedef struct snowflake_list {
	snowflake sf;
	struct snowflake_list *next;
} snowflake_list;

int is_twins(snowflake a, snowflake b)
{
	int i, j, k;
	for (j = 0; j < 6; j++) 
	{
		if (b.len[j] == a.len[0]) 
		{
			i = 0;
			for (k = j+1; k < 6; k++) 
				if (b.len[k] != a.len[++i])
					break;

			if (k == 6) 
				for (k = 0; k < j; k++)
					if (b.len[k] != a.len[++i])
						break;

			if (i == 5)
				return 1;

			i = 0;
			for (k = j-1; k >= 0; k--)
				if (b.len[k] != a.len[++i])
					break;
			if (k == -1) 
				for (k = 5; k > j; k--)
					if (b.len[k] != a.len[++i])
						break;

			if (i == 5)
				return 1;
		}
	}

	return 0;
}

int main()
{
	snowflake_list sf_list[MAX+1];
	int i, n, j, find_same;
	unsigned int sum;
	
	for (i = 0; i < MAX+1; i++)
		sf_list[i].next = NULL;

	find_same = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		snowflake_list *p = (snowflake_list *)malloc(sizeof(snowflake_list));
		p->next = NULL;
		snowflake_list *q;

		sum = 1;
		for (j = 0; j < 6; j++) 
		{
			scanf("%d", &((p->sf).len[j]));
			sum *= (p->sf).len[j];
		}

		sum %= MOD;
		if (sf_list[sum].next != NULL) 
		{
			q = sf_list[sum].next;
			while (q) 
			{
				if (is_twins(q->sf, p->sf)) 
				{
					find_same = 1;
					break;
				}
				q = q->next;
			}
		}
		if (find_same)
			break;
		else 
		{
			q = sf_list[sum].next;
			sf_list[sum].next = p;
			p->next = q;
		}
	}

	if (find_same)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");

	for (i = 0; i < MAX+1; i++)
		if (sf_list[i].next != NULL) 
		{
			snowflake_list *q = sf_list[i].next;
			snowflake_list *p = q;
			while (p) 
			{
				q = q->next;
				free(p);
				p = q;
			}
			sf_list[i].next = NULL;
		}

	return 0;
}
