/*
 * poj 1083
 * guzhoudiaoke@126.com
 * 2011-09-01
 */

#include <stdio.h>
#include <stdlib.h>

int format(int move[2])
{
	if (move[0] % 2 == 0)
		move[0] = move[0] / 2;
	else
		move[0] = (move[0]+1) / 2;
	
	if (move[1] % 2 == 0)
		move[1] = move[1] / 2;
	else
		move[1] = (move[1]+1) / 2;
		
	if (move[0] > move[1])
	{
		int temp = move[0];
		move[0] = move[1];
		move[1] = temp;
	}
}

int main()
{
	int T, N, s, t, i, j, k;
	int move[200][2];
	int corridor[201];
	
	scanf("%d", &T);
	
	for (i = 0; i < T; i++)
	{
		memset(corridor, 0, sizeof(corridor));
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%d%d", &move[j][0], &move[j][1]);
			format(move[j]);
			for (k = move[j][0]; k <= move[j][1]; k++)
				corridor[k] ++;
		}
		
		int max = 0;
		for (j = 0; j < 201; j++)
		{
			if (corridor[j] > max)
				max = corridor[j];
		}
		
		printf("%d\n", max * 10);
	}
	
	return 0;
}
