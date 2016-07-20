/*
 * poj 3253
 * guzhoudiaoke@126.com
 * 2011-09-07
 */

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) a = a+b; b = a-b; a = a-b

void heap_adjust(int *list, int s, int m)
{
	int j;
	list[0] = list[s];

	for (j = 2*s; j <= m; j *= 2)
	{
		if (j < m && list[j] > list[j+1]) ++j;
		if (list[0] <= list[j]) break;
		list[s] = list[j];
		s = j;
	}

	list[s] = list[0];
}

long long min_cost(int *list, int n)
{
	int i;
	for (i = n / 2; i > 0; --i)
		heap_adjust(list, i, n);
	
	long long sum = 0;
	for (i = n; i > 1; --i)
	{
		int temp = list[1];
		swap(list[1], list[i]);
		heap_adjust(list, 1, i-1);
		temp += list[1];
		list[1] = temp;
		heap_adjust(list, 1, i-1);

		sum += temp;
	}
	
	return sum;
}

int main()
{
	int *len_list;
	int n, i;
	scanf("%d", &n);
	len_list = (int *)malloc(sizeof(int) * (n+1));

	for (i = 1; i <= n; i++)
	{
		scanf("%d", len_list+i);
	}

	long long cost = min_cost(len_list, n);
	printf("%lld\n", cost);

	return 0;
}
