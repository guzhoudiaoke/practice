#include <stdio.h>

int main()
{
	int n, sum, abs_diff, score1, score2;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d%d", &sum, &abs_diff);
		if (sum < abs_diff || (sum%2 + abs_diff%2 == 1))
			printf("impossible\n");
		else
		{
			score1 = (sum + abs_diff) / 2;
			score2 = score1 - abs_diff;
			printf("%d %d\n", score1, score2);
		}
	}

	return 1;
}
