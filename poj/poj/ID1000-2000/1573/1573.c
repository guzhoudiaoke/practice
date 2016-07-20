/*
 * poj 1573
 * guzhoudiaoke@126.com
 * 2011-09-03
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, column, enter_column;
	
	while (1)
	{
		scanf("%d%d%d", &row, &column, &enter_column);
		if (row == 0 && column == 0 && enter_column == 0)
			break;
		
		char *map;
		int *is_pass_by;
		
		map = (char *)malloc(sizeof(char) * row * column);
		is_pass_by = (int *)malloc(sizeof(int) * row * column);
		if (!map || !is_pass_by) return -1;
		
		int i = 0;
		while (i < row * column)
		{
			char ch;
			scanf("%c", &ch);
			if (ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
			{
				map[i++] = ch;
				is_pass_by[i] = 0;
			}
		}
		
		int pos = enter_column - 1;
		int num = 0;
		is_pass_by[0] = pos;
		while (1)
		{
			int r = pos / column;
			int c = pos % column;
			
			if (map[pos] == 'N')
				r -= 1;
			else if (map[pos] == 'S')
				r += 1;
			else if (map[pos] == 'W')
				c -= 1;
			else if (map[pos] == 'E')
				c += 1;
				
			num++;
			pos = r*column + c;
			is_pass_by[num] = pos;
			
			if (r < 0 || r >= row || c < 0 || c >= column)
			{
				printf("%d step(s) to exit\n", num);
				break;
			}
			
			int j;
			for (j = 0; j < num-1; j++)
			{
				if (is_pass_by[j] == pos)
					break;
			}
			if (j < num-1)
			{
				printf("%d step(s) before a loop of %d step(s)\n", j, num-j);
				break;
			}
		}
		
		free(map);
		free(is_pass_by);
	}
}
