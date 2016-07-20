/*
 * poj 2272
 * guzhoudiaoke@126.com
 * 2011-09-22
 */

#include <stdio.h>
#include <math.h>

int get_score(double point[6])
{
	int i, re = 0;
	for (i = 0; i < 6; i+=2)
	{
		double rr = point[i]*point[i] + point[i+1]*point[i+1];
		if (rr <= 225 && rr > 144)
			re += 20;
		else if (rr <= 144 && rr > 81)
			re += 40;
		else if (rr <= 81 && rr > 36)
			re += 60;
		else if (rr <= 36 && rr > 9)
			re += 80;
		else if (rr <= 9 && rr >= 0)
			re += 100;
	}

	return re;
}


int main()
{
	int i, sum1, sum2;
	double point1[6], point2[6];
	while (1)
	{
		for (i = 0; i < 6; i++)
			scanf("%lf", &point1[i]);
		for (i = 0; i < 6; i++)
			scanf("%lf", &point2[i]);

		if (point1[0] == -100)
			break;

		sum1 = get_score(point1);
		sum2 = get_score(point2);
		
		if (sum1 == sum2)
			printf("SCORE: %d to %d, TIE.\n", sum1, sum2);
		else
			printf("SCORE: %d to %d, PLAYER %d WINS.\n", sum1, sum2, sum1 > sum2 ? 1 : 2);
	}

	return 0;
}

