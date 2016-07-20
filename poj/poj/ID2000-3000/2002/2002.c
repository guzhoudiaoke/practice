/*
 * poj 2002
 * guzhoudiaoke@126.com
 * 2011-09-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD	199997

typedef struct point_list {
	int x;
	int y;
	struct point_list *next;
} point_list;

int points[1001][2];
point_list list[MOD];

void insert(int x, int y)
{
	int key = (x*x + y*y) % MOD;
	point_list *p = list[key].next;
	point_list *node = (point_list *)malloc(sizeof(point_list));
	node->x = x;
	node->y = y;
	list[key].next = node;
	node->next = p;
}

int find_square(int x, int y)
{
	int key = (x*x + y*y) % MOD;
	point_list *p = list[key].next;
	while (p)
	{
		if (p->x == x && p->y == y)
			return 1;
		p = p->next;
	}
	
	return 0;
}

int main()
{
	int n, i, j, square_num;
	
	while (1)
	{
		memset(list, 0, sizeof(list));
		
		square_num = 0;
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &points[i][0], &points[i][1]);
			insert(points[i][0], points[i][1]);
		}

		for (i = 0; i < n; i++)
		{
			for (j = i+1; j < n; j++)
			{
				int x3, y3, x4, y4, dx, dy;
				dx = points[j][0] - points[i][0];
				dy = points[j][1] - points[i][1];
				
				x3 = points[j][0] + dy;
				y3 = points[j][1] - dx;
				x4 = points[i][0] + dy;
				y4 = points[i][1] - dx;
				
				if (find_square(x3, y3) && find_square(x4, y4))
					square_num ++;
				
				x3 = points[j][0] - dy;
				y3 = points[j][1] + dx;
				x4 = points[i][0] - dy;
				y4 = points[i][1] + dx;
				
				if (find_square(x3, y3) && find_square(x4, y4))
					square_num ++;
			}
		}
		
		printf("%d\n", square_num/4);
	}	
	
	return 0;
}
