/*
 * problem: poj 2390
 * author:  guzhoudiaoke
 * time:    2011-09-25
 */

#include <stdio.h>

int main()
{
	int r, m, y, i;
	double rate, money;
	
	scanf("%d %d %d", &r, &m, &y);
	rate = 1 + (double)(r) / 100;
	money = m;

	for (i = 0; i < y; i++)
		money = money * rate;
		
	printf("%d\n", (int)money);

	return 0;
}