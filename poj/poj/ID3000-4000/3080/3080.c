/*
 * poj 3080
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUM	20
#define MAX_LEN	70

int main()
{
	int n, m;
	char str[MAX_NUM][MAX_LEN+1];
	char max_sub_str[MAX_LEN+1];
	
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		int j;
		for (j = 0; j < m; j++)
			scanf("%s", str[j]);
		
		int max_len = 0;
		for (j = 0; j <= strlen(str[0])-3; j++)
		{
			int len = 0;
			char sub_str[MAX_LEN+1];
			sub_str[0] = str[0][j+0]; sub_str[1] = str[0][j+1]; sub_str[2] = str[0][j+2]; sub_str[3] = '\0';
			int k;
			for (k = 1; k < m; k++)
				if (strstr(str[k], sub_str) == 0) break;
			if (k == m)			// m 个串都含有长为3 的串sub_str
			{
				len = 3;
				int p;
				for (p = j+3; p < strlen(str[0]); p++)
				{
					sub_str[len] = str[0][p]; sub_str[len+1] = '\0';
					int q;
					for (q = 1; q < m; q++)
						if (strstr(str[q], sub_str) == 0) break;
					if (q == m)	// m 个串都含有长为len+1 的串sub_str
						len += 1;
					else
					{
						sub_str[len] = '\0';
						break;
					}
				}
				
				if (len > max_len)
				{
					strcpy(max_sub_str, sub_str);
					max_len = len;
				}
				else if (len == max_len && strcmp(sub_str, max_sub_str) < 0)
					strcpy(max_sub_str, sub_str);
			}
		}
		
		if (max_len > 0)
			printf("%s\n", max_sub_str);
		else
			printf("no significant commonalities\n");
	}
	
	return 0;
}
