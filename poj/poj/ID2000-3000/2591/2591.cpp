/*
 * poj 2591
 * guzhoudiaoke@126.com
 * 2011-11-17
 */

#include <stdio.h>

long s[10000001];

long min_2(long x1, long x2)
{
	return (x1 < x2) ? x1 : x2;
}

void get_s()
{
	s[1] = 1;
	int index = 2, f2 = 1, f3 = 1;
	while (index < 10000001)
	{
		s[index] = min_2(s[f2]*2 + 1, s[f3]*3 + 1);
		if (s[index] == s[f2]*2 + 1) f2++;
		if (s[index] == s[f3]*3 + 1) f3++;
		index++;
	}
}

int main()
{
	int n;
	get_s();

	while (scanf("%d", &n) != EOF)
	{
		printf("%ld\n", s[n]);
	}

	return 0;
}
