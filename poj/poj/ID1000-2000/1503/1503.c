/*
 * poj 1503
 * guzhoudiaoke@126.com
 * 2011-09-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN	100

int main()
{
	char num_str[LEN+1];
	int sum[LEN+2];
	int i;
	
	for (i = 0; i < LEN+2; i++)
		sum[i] = 0;
		
	while (1)
	{
		scanf("%s", num_str);
		if (strcmp(num_str, "0") == 0)
			break;
		
		int len = strlen(num_str);
		for (i = len-1; i >= 0; i--)
			sum[len-1-i] += (num_str[i]-'0');
	}
	
	for (i = 0; i < LEN; i++)
	{
		if (sum[i] >= 100)
		{
			int carry1, carry2;
			carry1 = sum[i] / 100;
			carry2 = (sum[i] % 100) / 10;
			sum[i+2] += carry1;
			sum[i+1] += carry2;
			sum[i] = sum[i] % 10;
		}
		else if (sum[i] >= 10)
		{
			sum[i+1] += sum[i] / 10;
			sum[i] = sum[i] % 10;
		}
	}
	
	for (i = LEN+1; i >= 0; i--)
	{
		if (sum[i] != 0)
			break;
	}
	while (i >= 0)
	{
		printf("%d", sum[i]);
		i--;
	}
	
	return 0;
}
