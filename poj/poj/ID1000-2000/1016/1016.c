/*
 * poj 1016
 * guzhoudiaoke@126.com
 * 2011-08-30
 */

#include <stdio.h>
#include <string.h>

void get_knumbers_iterative(char knumbers[16][81])
{
	int data[10];
	int i, j;
	
	i = 0;
	while (i < 15)
	{
		for (j = 0; j < 10; j++)
			data[j] = 0;
		
		for (j = 0; j < strlen(knumbers[i]); j++)
		{
			int n = knumbers[i][j] - '0';
			data[n]++;
		}
		
		int k = 0;
		for (j = 0; j < 10; j++)
		{
			if(data[j] == 0)
				continue;
			if (data[j] >= 10)
			{
				knumbers[i+1][k++] = (data[j]/10 + '0');
				knumbers[i+1][k++] = (data[j]%10 + '0');
				knumbers[i+1][k++] = (j + '0');
			}
			else
			{
				knumbers[i+1][k++] = (data[j] + '0');
				knumbers[i+1][k++] = (j + '0');
			}
		}
		
		knumbers[i+1][k++] = '\0';
		
		i++;
	}
}

int main()
{
	char knumbers[16][81];
	int i, j;
	
	while (1)
	{
		scanf("%s", knumbers[0]);
		
		if (strcmp(knumbers[0], "-1") == 0)
			break;
		
		get_knumbers_iterative(knumbers);
		
		int get_it = 0;
		for (i = 1; i < 16; i++)
		{
			get_it = 0;
			for (j = 0; j < i; j++)
			{
				if (strcmp(knumbers[i], knumbers[j]) == 0)
				{
					if (i == 1)
						printf("%s is self-inventorying\n", knumbers[0]);
					
					else if (j == i - 1)
						printf("%s is self-inventorying after %d steps\n", knumbers[0], i-1);
					
					else if (i - j >= 2)
						printf("%s enters an inventory loop of length %d\n", knumbers[0], i-j);
					
					get_it = 1;
				}
			}
			if (get_it)
				break;
		}
		
		if (!get_it)
			printf("%s can not be classified after 15 iterations\n", knumbers[0]);
		
	}
	
	return 0;
}
