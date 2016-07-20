/*
 * poj 2545
 * guzhoudiaoke@126.com
 * 2011-11-16
 */

#include <stdio.h>

long long *hams;

long long min_3(long long x1, long long x2, long long x3)
{
	long long ret = x1;
	if (x2 < ret) ret = x2;
	if (x3 < ret) ret = x3;

	return ret;
}

long long get_ham(int p1, int p2, int p3, int index)
{
	long long i = 1, i1 = 0, i2 = 0, i3 = 0;
	hams[0] = 1;

	while (i <= index)
	{
		hams[i] = min_3(hams[i1]*p1, hams[i2]*p2, hams[i3]*p3);
		if (hams[i] == hams[i1]*p1) i1++;
		if (hams[i] == hams[i2]*p2) i2++;
		if (hams[i] == hams[i3]*p3) i3++;

		i++;
	}

	return hams[index];
}

int main()
{
	int p1, p2, p3, index;
	scanf("%d %d %d %d", &p1, &p2, &p3, &index);
	hams = new long long[index +1];

	printf("%lld\n", get_ham(p1, p2, p3, index));

	return 0;
}