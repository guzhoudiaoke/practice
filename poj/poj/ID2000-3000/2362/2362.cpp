/*
 * poj 2362
 * guzhoudiaoke@126.com
 * 2011-11-08
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, len[20], sum, length;
bool visited[20], find;

int cmp_len(const void *a, const void *b)
{
	return (*(int *)b) - (*(int *)a);
}

int dfs(int start_index, int cur_len, int cur_num)
{
	if (cur_len == length) {
		start_index = 0;
		cur_num++;
		cur_len = 0;
		if (cur_num == 4) return true;
	}

	for (int i = start_index; i < n; i++)
		if (visited[i] == false)
		{
			if (cur_len + len[i] > length) continue;
			if (i > 0 && len[i] == len[i-1] && visited[i-1] == false) continue;
			
			visited[i] = true;
			if (dfs(i+1, cur_len+len[i], cur_num)) return true;
			
			visited[i] = false;
		}

	return false;
}

int solve()
{
	if (sum % 4 != 0)
		return 0;
	
	length = sum / 4;
	if (length < len[0])
		return 0;
	
	memset(visited, false, sizeof(visited));
	
	return dfs(0, 0, 0);
}

int main()
{
	int t;
	
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &len[i]);
			sum += len[i];
		}

		qsort(len, n, sizeof(int), cmp_len);

		if (solve()) printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}

