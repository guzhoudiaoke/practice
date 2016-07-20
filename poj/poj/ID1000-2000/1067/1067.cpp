/*
 * poj 1067
 * guzhoudiaoke
 * 2011-10-24
 */

/*
 * 输入a和b，假设a < b(如果b > a交换a、b的值),如果（b-a）乘上黄金分割率（根号下5加1的和除以2），
 * 取整后等于a，则必输。否则必赢。
 */

#include <stdio.h>
#include <math.h>

#define swap(a, b) { long long t = a; a = b; b = t; }

bool win(long long a, long long b)
{
	double gold_split = (sqrt(5.0) + 1) / 2.0;
	if (a == (int)((b-a)*gold_split))
		return false;
	
	return true;
}

int main()
{
	long long a, b;
	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		if (a > b) swap(a, b);
		if (win(a, b)) printf("1\n");
		else printf("0\n");
	}

	return 0;
}