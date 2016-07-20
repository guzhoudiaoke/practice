/*
 * poj 1004
 * guzhoudiaoke@126.com
 * 2011-08-29
 */

#include <stdio.h>

int main()
{
	double sum, per_month;
	int i;
	
	sum = 0;
	for (i = 0; i < 12; i++)
	{
		scanf("%lf", &per_month);
		sum += per_month;
	}
	
	printf("$%.2f", sum / 12);
}
