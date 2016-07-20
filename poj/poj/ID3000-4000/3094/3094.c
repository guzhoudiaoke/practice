/*
 * poj 3094
 * guzhoudiaoke@126.com
 * 2011-09-02
 */

#include <stdio.h>
#include <string.h>

#define MAX	255

int main()
{
	char str[MAX+1];
	int num;
	
	while (1)
	{
		gets(str);
		if (strcmp(str, "#") == 0)
			break;
		
		num = 0;
		int len = strlen(str);
		int i;
		for (i = 0; i < len; i++)
		{
			if (str[i] != ' ')
				num += (i+1) * (str[i] - 'A' + 1);
		}
			
		printf("%d\n", num);
	}
	
	return 0;
}
