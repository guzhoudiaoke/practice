/*
 * poj 2299
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long swap_num;
long long *temp;

void merge(long long c[], long long d[], long l, long m, long r)
{
	long i = l, j = m+1, k = l;
	long q;
	while ((i <= m) && (j <= r)) {
		if (c[i] <= c[j]) d[k++] = c[i++];
		else {
			d[k++] = c[j++];
			swap_num += (j-k);
		}
	}
	if (i > m)
		for (q = j; q <= r; q++)
			d[k++] = c[q];
	else
		for (q = i; q <= m; q++)
			d[k++] = c[q];
}

void copy(long long a[], long long b[], long l, long r)
{
	long i;
	for (i = l; i <= r; i++)
		a[i] = b[i];
}

void merge_sort(long long a[], long left, long right)
{
	if (left < right) {
		long i = (left + right) / 2;
		merge_sort(a, left, i);
		merge_sort(a, i+1, right);
		merge(a, temp, left, i, right);
		copy(a, temp, left, right);
	}
}

int main()
{
	long n;
	long long *num;
	
	while (1)
	{
		scanf("%ld", &n);
		if (n == 0)
			break;
		
		swap_num = 0;
		num = (long long *)malloc(sizeof(long long) * n);
		temp = (long long *)malloc(sizeof(long long) * n);
	
		int i;
		for (i = 0; i < n; i++)
			scanf("%lld", &num[i]);
		
		merge_sort(num, 0, n-1);
		printf("%lld\n", swap_num);
		
		free(num);
		free(temp);
	}

	return 0;
}
