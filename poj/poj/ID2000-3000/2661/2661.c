/*
 * poj 2661
 * guzhoudiaoke@126.com
 * 2011-08-31
 */
 
#include <stdio.h>
#include <math.h>

int two_pow_n(int n)
{
	int re = 1;
	int i;
	
	for (i = 0; i < n; i++)
		re *= 2;
	
	return re;
}

int main()
{
	int data[21];
	
	// 求 n! < pow(2, pow(2, 2+i))
	// 转换成求log(n!) < pow(2, 2+i), log(1)+log(2)+...+log(n) < pow(2, 2+i)
	int n = 1;
	int i, j;
	double k = 0;
	
	j = 1;
	for (i = 0; i < 21; i++)
	{
		int temp = two_pow_n(i+2);
		while (k <= temp)
		{
			k += log((double)(j++)) / log(2.0);
		}
		
		data[i] = j-2;
	} 
	
	int year;
	while (scanf("%d", &year) && year != 0)
	{
		printf("%d\n", data[(year-1960) / 10]);
	}
	
	return 0;
}
