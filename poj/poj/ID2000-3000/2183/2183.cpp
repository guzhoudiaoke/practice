#include <stdio.h>
#include <string.h>

int visited[1000000], num;

int main()
{
	int n, square, cnt;
	scanf("%d", &num);
	memset(visited, 0, sizeof(visited));
	visited[num] = 1;
	cnt = 1;
	while (1)
	{
		n = num % 100000 / 10;
		square = n * n;
		num = square % 1000000;
		//printf("%d %d %d\n", n, square, num);
		if (! visited[num])
			visited[num] = (++cnt);
		else
		{
			printf("%d %d %d\n", num, cnt-visited[num]+1, cnt);
			break;
		}
	}

	return 0;
}
