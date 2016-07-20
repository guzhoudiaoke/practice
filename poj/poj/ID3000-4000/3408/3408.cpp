/*
 * problem:	poj 3408
 * author:	guzhoudiaoke
 * time:	2011-10-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>

using namespace std;

typedef struct list {
	int len;
	int *d;
} list;

int n;
list *l;
int *visited;
set<int> ignore;

int bfs(int index)
{
	int i, w, left;
	for (i = 0; i <= n; i++)
		visited[i] = 0;

	queue<int> q;
	int p = index;
	q.push(p);
	visited[p] = 1;
	left = n-1;
	if (left == 0)
		return 0;

	while (! q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 1; i <= l[p].len; i++)
		{
			w = l[p].d[i];
			if (! visited[w])
			{
				visited[w] = visited[p] + 1;
				q.push(w);
				left--;
				if (left == 0)
					return visited[p];
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (visited[i])
			if (ignore.find(i) == ignore.end())
				ignore.insert(i);
	return -1;
}

int main()
{
	int i, j, max, max_i;
	scanf("%d", &n);
	l = (list *)malloc(sizeof(list) * (n+1));
	visited = (int *)malloc(sizeof(int) * (n+1));

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &l[i].len);
		l[i].d = (int *)malloc(sizeof(int) * (l[i].len+1));
		for (j = 1; j <= l[i].len; j++)
			scanf("%d", &l[i].d[j]);
	}

	max = -1;
	max_i = 0;
	for (i = 1; i <= n; i++)
	{
		if (ignore.find(i) != ignore.end())
			continue;
		int t = bfs(i);
		if (t != -1 && t >= max)
		{
			max = t;
			max_i = i;
		}
	}

	if (max == -1)
		printf("impossible\n");
	else
		printf("%d\n%d\n", max, max_i);

	delete []visited;
	for (i = 1; i <= n; i++)
		delete [](l[i].d);
	delete []l;

	return 0;
}