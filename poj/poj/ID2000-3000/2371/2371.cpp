/*
 * poj 2371
 * guzhoudiaoke@126.com
 * 2011-11-02
 */

#include <stdio.h>
#include <stdlib.h>

int nums[100000];

int cmp(const void *a, const void *b)
{
	return (*(int *)a) - (*(int *)b);
}

int main()
{
	int n, k, index;
	char str[4];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	
	getchar();
	gets(str);
	
	qsort(nums, n, sizeof(int), cmp);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &index);
		printf("%d\n", nums[index-1]);
	}

	return 0;
}
