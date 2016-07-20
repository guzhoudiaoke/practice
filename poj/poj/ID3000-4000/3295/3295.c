/*
 * poj 3295
 * guzhoudiaoke@126.com
 * 2011-09-03
 */

#include <stdio.h>
#include <string.h>

char str[101];
int l = 0;

int calc(int pqrst)
{
	char ch = str[l++];
	switch (ch)
	{
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
			//printf("%d", pqrst >> (ch - 'p') & 1);
			return (pqrst >> (ch - 'p') & 1);
			break;
		case 'K':
			//printf("K");
			return calc(pqrst) & calc(pqrst);
			break;
		case 'A':
			//printf("A");
			return calc(pqrst) | calc(pqrst);
			break;
		case 'N':
			//printf("N");
			return !calc(pqrst);
			break;
		case 'C':
			//printf("C");
			return !calc(pqrst) | calc(pqrst);
			break;
		case 'E':
			//printf("E");
			return calc(pqrst) == calc(pqrst);
			break;
	}
}

int main()
{
	while (1)
	{
		scanf("%s", str);
		if (strcmp(str, "0") == 0)
			break;
		
		int i;
		int flag = 0;
		for (i = 0; i < 32; i++)
		{
			l = 0;
			if (calc(i) == 0)
			{
				flag = 1;
				break;
			}
			//printf("\n");
		}
		
		if (flag)
			printf("not\n");
		else
			printf("tautology\n");
	}
	
	return 0;
}
