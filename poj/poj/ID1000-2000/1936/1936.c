/*
 * poj 1936
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN	100000

int main()
{
	char str_s[MAX_LEN+1];
	char str_t[MAX_LEN+1];
	
	while (scanf("%s%s", str_s, str_t) == 2)
	{
		int i, j;
		j = 0;
		for (i = 0; i < strlen(str_t); i++)
		{
			if (str_t[i] == str_s[j])
				j++;
			if (j == strlen(str_s))
				break;
		}
		if (j == strlen(str_s))
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
