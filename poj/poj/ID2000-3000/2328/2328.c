/*
 * poj 2328
 * guzhoudiaoke
 * 2011-09-24
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char request[10];
	int guess, min = 0, max = 11;
	
	while (1)
	{
		scanf("%d", &guess);
		getchar();
		if (guess == 0)
			break;
		
		gets(request);
		
		if (strcmp(request, "too high") == 0 && guess < max)
			max = guess;
		else if (strcmp(request, "too low") == 0 && guess > min)
			min = guess;
		else if (strcmp(request, "right on") == 0)
		{
			if (guess > min && guess < max)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			min = 0;
			max = 11;
		}
	}
	
	return 0;
}
