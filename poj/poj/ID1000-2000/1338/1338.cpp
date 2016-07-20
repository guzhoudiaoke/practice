/*
 * poj 1338
 * guzhoudiaoke@126.com
 * 2011-11-15
 */

#include <stdio.h>

int ugly[1501];

int min_3(int f2, int f3, int f5)
{
	int ret = f2;
	if (f3 < ret) ret = f3;
	if (f5 < ret) ret = f5;

	return ret;
}

void get_ugly()
{
	ugly[1] = 1;
	int f2 = 1, f3 = 1, f5 = 1, index = 2;

	while (index < 1501) {
		ugly[index] = min_3(ugly[f2]*2, ugly[f3]*3, ugly[f5]*5);
		if (ugly[index] == ugly[f2]*2) f2++;
		if (ugly[index] == ugly[f3]*3) f3++;
		if (ugly[index] == ugly[f5]*5) f5++;
		index++;
	}
}

int main()
{
	int n;
	get_ugly();

	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		printf("%d\n", ugly[n]);
	}

	return 0;
}