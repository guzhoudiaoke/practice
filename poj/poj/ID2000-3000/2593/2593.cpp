/*
 * problem:	poj 2593
 * author:	guzhoudiaoke
 * time:	2011-10-02
 */

#include <stdio.h>

int n, a[100000], sum1[100000], sum2[100000];

void get_sum1()
{
	int i, temp;
	sum1[0] = temp = a[0];
	for (i = 1; i < n; i++)
	{
		if (temp > 0) temp += a[i];
		else temp = a[i];

		if (temp > sum1[i-1]) sum1[i] = temp;
		else sum1[i] = sum1[i-1];
	}
}

void get_sum2()
{
	int i, temp;
	sum2[n-1] = temp = a[n-1];
	for (i = n-2; i >= 0; i--)
	{
		if (temp > 0) temp += a[i];
		else temp = a[i];

		if (temp > sum2[i+1]) sum2[i] = temp;
		else sum2[i] = sum2[i+1];
	}
}

int get_max()
{
	int max = sum1[0] + sum2[1];
	for (int i = 2; i < n; i++)
		if (sum1[i-1] + sum2[i] > max)
			max = sum1[i-1] + sum2[i];
	return max;
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		get_sum1();
		get_sum2();
		printf("%d\n", get_max());
	}

	return 0;
}