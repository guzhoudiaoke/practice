/*
 * poj1046
 * guzhoudiaoke@126.com
 * 2011-08-31
 */

#include <stdio.h>

int main()
{
	int tar_corlor[16][3];
	int min_dis;
	int min_dis_index;
	int i;
	
	for (i = 0; i < 16; i++)
		scanf("%d%d%d", &tar_corlor[i][0], &tar_corlor[i][1], &tar_corlor[i][2]);
	
	int map_corlor[3];
	while (1)
	{
		scanf("%d%d%d", &map_corlor[0], &map_corlor[1], &map_corlor[2]);
		if (map_corlor[0] == -1)
			break;
		
		min_dis_index = 0;
		min_dis = 255 * 255 * 3;
		for (i = 0; i < 16; i++)
		{
			int dis = (map_corlor[0]-tar_corlor[i][0])*(map_corlor[0]-tar_corlor[i][0]) + 
				(map_corlor[1]-tar_corlor[i][1])*(map_corlor[1]-tar_corlor[i][1]) + 
				(map_corlor[2]-tar_corlor[i][2])*(map_corlor[2]-tar_corlor[i][2]);
			
			if (dis < min_dis)
			{
				min_dis = dis;
				min_dis_index = i;
			}
		}
		
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", map_corlor[0], map_corlor[1], map_corlor[2],
			tar_corlor[min_dis_index][0], tar_corlor[min_dis_index][1], tar_corlor[min_dis_index][2]);
	}
	
	return 0;
}
