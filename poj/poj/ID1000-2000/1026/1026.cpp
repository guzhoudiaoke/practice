/*
 * poj 1026
 * guzhoudiaoke
 * 2011-10-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sequence[201], n, k, cycle[201];
char message[201], ans[201];

void encode_char(int index)
{
	int i = index, len = 0;
	while (len < k%cycle[index])
	{
		i = sequence[i];
		len++;
	}

	ans[i] = message[index];
}

void encode()
{
	int i;
	memset(ans, 0, sizeof(ans));
	for (i = 1; i <= n; i++)
		encode_char(i);

	for (i = n; i > 0; i--)
		if (ans[i] != ' ')
		{
			ans[i+1] = '\0';
			break;
		}
}

void get_per_cylce(int index)
{
	bool visited[201];
	int len, i = index;
	memset(visited, false, sizeof(visited));

	visited[i] = true;
	len = 0;
	while (1)
	{
		len++;
		i = sequence[i];
		if (!visited[i])
			visited[i] = true;
		else
			break;
	}

	for (i = 1; i <= n; i++)
		if (visited[i])
			cycle[i] = len;
}

void get_cycle()
{
	memset(cycle, 0, sizeof(cycle));

	for (int i = 1; i <= n; i++)
		if (cycle[i] == 0)
			get_per_cylce(i);
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 1; i <= n; i++)
			scanf("%d", &sequence[i]);
		get_cycle();

		while (1)
		{
			scanf("%d", &k);
			if (k == 0) break;

			gets(message);
			int len = strlen(message);
			for (i = len; i <= n; i++)
				message[i] = ' ';
			
			encode();

			i = 1;
			while (ans[i])
				printf("%c", ans[i++]);
			printf("\n");
		}

		printf("\n");
	}
	return 0;
}
