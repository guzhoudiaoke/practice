/*
 * poj 1665
 * guzhoudiaoke@126.com
 * 2011-09-21
 */

#include <stdio.h>

#define pi	3.1415927

int main()
{
	int n = 1;
	float diameter, revolutions, time, distance, mph;
	
	while (1)
	{
		scanf("%f%f%f", &diameter, &revolutions, &time);
		if (revolutions == 0)
			break;
		distance = pi * diameter / 5280 / 12 * revolutions;
		mph = distance / time * 3600;
		printf("Trip #%d: %.2f %.2f\n", n, distance, mph);
		n++;
	}

	return 0;
}
