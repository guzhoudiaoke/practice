#include <stdio.h>

int t, n, num[12], ans[12];
bool flag;

void dfs(int num_pos, int left, int ans_pos)
{
	if (left == 0)
	{
		flag = true;
		printf("%d", ans[0]);
		for (int i = 1; i < ans_pos; i++)
			printf("+%d", ans[i]);
		printf("\n");
	}
	else
	{
		int pre = -1;
		for (int i = num_pos; i < n; i++)
			if (left >= num[i] && num[i] != pre)
			{
				pre = num[i];
				ans[ans_pos] = num[i];
				dfs(i+1, left-num[i], ans_pos+1);
			}
	}
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d %d", &t, &n);
		if (t == 0 && n == 0) break;

		for (i = 0; i < n; i++)
			scanf("%d", &num[i]);
		
		flag = false;	
		printf("Sums of %d:\n", t);
		
		dfs(0, t, 0);
		if (flag == false) 
			printf("NONE\n");
	}

	return 0;
}

