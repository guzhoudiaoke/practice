/*
 * problem:	poj 2479
 * author:	guzhoudiaoke
 * time:	2011-10-02
 */

#include <stdio.h>

int t, n, a[50001], dp_positive[50001], dp_negative[50001];

void positive_sub_max()
{
	int i, temp;
	dp_positive[0] = temp = a[0];
	for (i = 1; i < n; i++)
	{
		if (temp > 0)
			temp += a[i];
		else
			temp = a[i];
		if (temp > dp_positive[i-1])
			dp_positive[i] = temp;
		else
			dp_positive[i] = dp_positive[i-1];
	}
}

void negative_sub_max()
{
	int i, temp;
	dp_negative[n-1] = temp = a[n-1];
	for (i = n-2; i >= 0; i--)
	{
		if (temp > 0)
			temp += a[i];
		else
			temp = a[i];
		if (temp > dp_negative[i+1])
			dp_negative[i] = temp;
		else
			dp_negative[i] = dp_negative[i+1];
	}
}

int get_max_sum()
{
	int max = dp_positive[0] + dp_negative[1], temp;
	for (int i = 2; i < n; i++)
	{
		temp = dp_positive[i-1] + dp_negative[i];
		if (temp > max)
			max = temp;
	}

	return max;
}

int main()
{
	int i;
	scanf("%d\n", &t);

	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		negative_sub_max();
		positive_sub_max();

		printf("%d\n", get_max_sum());
	}

	return 0;
}