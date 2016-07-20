/*
 * poj 1005
 * guzhoudiaoke@126.com
 * 2011-08-30
 */

#include <stdio.h>

#define pi 3.14159

int main()
{
	float x, y;
	int n, i, year;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%f%f", &x, &y);
		year = (int)(pi*(x*x + y*y)/100 + 1);
		printf("Property %d: This property will begin eroding in year %d.\n", i, year);
	}
	
	printf("END OF OUTPUT.");
	
	return 0;
}

