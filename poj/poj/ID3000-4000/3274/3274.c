/*
 * poj 3274
 * guzhoudiaoke@126.com
 * 2011-09-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct delt_list {
	int num[30];
	int no;
	struct delt_list *next;
} delt_list;

int is_same(int a[], int b[], int k)
{
	int i;
	for (i = 1; i < k; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}

int main()
{
	int n, k, i, j, feature, pre_feature, max_same, max_range;
	int s[30];
	delt_list list[15000];
	for (i = 0; i < 15000; i++)
		list[i].next = NULL;
	delt_list *zero = (delt_list *)malloc(sizeof(delt_list));;
	zero->next = NULL; zero->no = -1;
	memset(zero->num, 0, 30 * sizeof(int));
	list[0].next = zero;
	
	scanf("%d %d", &n, &k);
	memset(s, 0, sizeof(s));
	
	long long sum;
	int all_feature = 0;
	max_range = 0;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		delt_list *node = (delt_list *)malloc(sizeof(delt_list));
		memset(node->num, 0, sizeof(int) * 30);
		node->no = i; node->next = NULL;
		delt_list *q;
		
		scanf("%d", &feature);
		if (feature == (pow(2, k)-1) || feature == 0)
			all_feature = 1;
		s[0] += (feature & 1);
		for (j = 1; j < k; j++)
		{
			s[j] += ((feature >> j) & 1);
			node->num[j] = s[j] - s[0];
			sum += node->num[j] * node->num[j];
		}
		
		sum %= 14997;
		
		if (list[sum].next)
		{
			q = list[sum].next;
			while (q) 
			{
				if (is_same(q->num, node->num, k)) 
				{
					int range = node->no - q->no;
					if (range > max_range)
						max_range = range;
				}
				q = q->next;
			}
		}
		
		q = list[sum].next;
		list[sum].next = node;
		node->next = q;
	}
	
	printf("%d\n", max_range);
	
	for (i = 0; i < 15000; i++)
		if (list[i].next != NULL) 
		{
			delt_list *q = list[i].next;
			delt_list *p = q;
			while (p) 
			{
				q = q->next;
				free(p);
				p = q;
			}
			list[i].next = NULL;
		}
	
	return 0;
}
