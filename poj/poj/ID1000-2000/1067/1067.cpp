/*
 * poj 1067
 * guzhoudiaoke
 * 2011-10-24
 */

/*
 * ����a��b������a < b(���b > a����a��b��ֵ),�����b-a�����ϻƽ�ָ��ʣ�������5��1�ĺͳ���2����
 * ȡ�������a������䡣�����Ӯ��
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