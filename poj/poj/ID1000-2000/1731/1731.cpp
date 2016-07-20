/*
 * problem:	poj	1731
 * author:	guzhoudiaoke
 * time:	2011-10-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[201], ans[201];
bool visited[201];
int len;

int cmp_char(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

void dfs(int depth)
{
	if (depth == len)
		printf("%s\n", ans);
	for (int i = 0; i < len; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		ans[depth] = str[i];
		dfs(depth + 1);
		visited[i] = false;
		while (i+1 < len && str[i+1] == str[i]) i++;
	}
}

int main()
{
	scanf("%s", str);
	
	len = strlen(str);
	qsort(str, len, sizeof(char), cmp_char);
	ans[len] = '\0';
	dfs(0);

	return 0;
}