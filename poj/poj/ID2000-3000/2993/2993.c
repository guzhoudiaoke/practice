/*
 * poj 2993
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>
#include <string.h>

#define ROW	17
#define COLUMN	33

int main()
{
	char map[ROW][COLUMN+1] = {
		"+---+---+---+---+---+---+---+---+\0",
		"|...|:::|...|:::|...|:::|...|:::|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|:::|...|:::|...|:::|...|:::|...|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|...|:::|...|:::|...|:::|...|:::|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|:::|...|:::|...|:::|...|:::|...|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|...|:::|...|:::|...|:::|...|:::|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|:::|...|:::|...|:::|...|:::|...|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|...|:::|...|:::|...|:::|...|:::|\0",
		"+---+---+---+---+---+---+---+---+\0",
		"|:::|...|:::|...|:::|...|:::|...|\0",
		"+---+---+---+---+---+---+---+---+\0",
	};

	int i, j;
	char str_white[100];
	char str_black[100];
	
	scanf("%s", str_white);
	scanf("%s", str_white);
	scanf("%s", str_black);
	scanf("%s", str_black);
	
	char str[4];
	i = 0;
	j = 0;
	while (1)
	{
		if (str_white[i] != ',' && str_white[i] != '\0')
			str[j++] = str_white[i];
		else
		{
			str[j++] = '\0';
			j = 0;
		
			int row, col;
			if (strlen(str) == 2)
			{
				int c = str[0] - 'a' + 1;
				col = c*4 - 2;
				row = (9 - str[1] + '0')*2 - 1;
				map[row][col] = 'P';
			}
			else
			{
				int c = str[1] - 'a' + 1;
				col = c*4 - 2;
				row = (9 - str[2] + '0')*2 - 1;
				map[row][col] = str[0];
			}
			
			if (str_white[i] == '\0')
				break;
		}
		
		i++;
	}
	
	i = 0;
	j = 0;
	while (1)
	{
		if (str_black[i] != ',' && str_black[i] != '\0')
			str[j++] = str_black[i];
		else
		{
			str[j++] = '\0';
			j = 0;

			int row, col;
			if (strlen(str) == 2)
			{
				int c = str[0] - 'a' + 1;
				col = c*4 - 2;
				row = (9 - str[1] + '0')*2 - 1;
				map[row][col] = 'p';
			}
			else
			{
				int c = str[1] - 'a' + 1;
				col = c*4 - 2;
				row = (9 - str[2] + '0')*2 - 1;
				map[row][col] = str[0] + 32;
			}
			
			if (str_black[i] == '\0')
				break;
		}
		
		i++;
	}

	for (i = 0; i < ROW; i++)
		printf("%s\n", map[i]);
	

	return 0;
}
