#include <stdio.h>

typedef struct point {
	int x;
	int y;
} point;

point points[700];

int main()
{
	int n, i, j, k, max, temp;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 0; i < n; i++)
			scanf("%d %d", &points[i].x, &points[i].y);
	
		max = 0;
		for (i = 0; i < n; i++)
			for (j = i+1; j < n; j++)
			{
				temp = 0;
				for (k = j+1; k < n; k++)
					if ((points[k].x-points[i].x) * (points[j].y-points[i].y) == 
						(points[j].x-points[i].x) * (points[k].y-points[i].y))
						temp++;
				if (temp > max)
					max = temp;
			}
		printf("%d\n", max+2);
	}

	return 0;
}
