/*
 * poj 2388
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int p, int r)
{
	int i = p, j = r+1;
	int x = a[p];
	
	// 将小于x 的交换到左边，大于的换到右边
	while (1) {
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j) break;
		swap(&a[i], &a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	
	return j;
}

void quick_sort(int a[], int p, int r)
{
	if (p < r) {
		int q = partition(a, p, r);
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}

int main()
{
	int n;
	int *milk;
	scanf("%d", &n);
	milk = (int *)malloc(sizeof(int) * n);
	
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &milk[i]);
		
	quick_sort(milk, 0, n-1);
	
	printf("%d", milk[(n-1)/2]);
	
	return 0;
}
