/*
 * poj 2632
 * guzhoudiaoke@126.com
 * 2011-09-03
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct robot {
	int x;
	int y;
	int dir;
} robot;

int main()
{
	int k, a, b, n, m;
	robot *robots;
	
	scanf("%d", &k);
	
	int i;
	for (i = 0; i < k; i++)
	{
		scanf("%d%d%d%d", &a, &b, &n, &m);
		//printf("a = %d, b = %d, n = %d, m = %d\n", a, b, n, m);
		
		robots = (robot *)malloc(sizeof(robot) * n);
		if (!robots) { 
			return -1;
			printf("no mem\n");
		}
		
		int j;
		for (j = 0; j < n; j++)
		{
			char ch;
			scanf("%d%d", &robots[j].x, &robots[j].y);
			getchar();
			scanf("%c", &ch);
			
			if (ch == 'N')
				robots[j].dir = 0;
			else if (ch == 'E')
				robots[j].dir = 1;
			else if (ch == 'S')
				robots[j].dir = 2;
			else if (ch == 'W')
				robots[j].dir = 3;
			
			//printf("j = %d, x = %d, y = %d, dir = %d\n", j, robots[j].x, robots[j].y, robots[j].dir);
		}
		
		int crash = 0;
		for (j = 0; j < m; j++)
		{
			int no, repeat;
			char action;
			scanf("%d", &no);
			getchar();
			scanf("%c%d", &action, &repeat);
			//printf("j = %d, no = %d, action = %c, repeat = %d\n", j, no, action, repeat);
			
			int k;
			for (k = 0; k < repeat && !crash; k++)
			{
				if (action == 'L')
					robots[no-1].dir = (robots[no-1].dir + 3) % 4;
				else if (action == 'R')
					robots[no-1].dir = (robots[no-1].dir + 1) % 4;
				else if (action == 'F')
				{
					//printf("no = %d, x = %d, y = %d\n", no, robots[no-1].x, robots[no-1].y);
					if (robots[no-1].dir == 0)
						robots[no-1].y ++;
					else if (robots[no-1].dir == 1)
						robots[no-1].x ++;
					else if (robots[no-1].dir == 2)
						robots[no-1].y --;
					else if (robots[no-1].dir == 3)
						robots[no-1].x --;
						
					if (robots[no-1].x == 0 || robots[no-1].x == a+1 || 
						robots[no-1].y == 0 || robots[no-1].y == b+1)
					{
						crash = 1;
						printf("Robot %d crashes into the wall\n", no);
						break;
					}
					int l;
					for (l = 0; l < n; l++)
					{
						if (l != no-1 && robots[l].x == robots[no-1].x && robots[l].y == robots[no-1].y)
						{
							crash = 1;
							printf("Robot %d crashes into robot %d\n", no, l+1);
							break;
						}
					}
				}
			}
			
		}
		
		if (!crash)
				printf("OK\n");
		free (robots);
	}
	
	return 0;
}
