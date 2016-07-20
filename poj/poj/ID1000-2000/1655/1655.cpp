#include <stdio.h>
#include <string.h>

#define INF	0x7ffffff

typedef struct arc_node {
	int id;
	arc_node *next;
} arc_node;

arc_node *arc[20001];
bool visited[20001];
int n, dp[20001];

void input()
{
	int i, a, b;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		arc[i] = new arc_node;
		arc[i]->next = NULL;
	}
	
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
			
		arc_node *node = new arc_node;
		node->id = a;
		node->next = arc[b]->next;
		arc[b]->next = node;

		node = new arc_node;
		node->id = b;
		node->next = arc[a]->next;
		arc[a]->next = node;
	}

	for (i = 1; i <= n; i++) dp[i] = INF;
	memset(visited, false, sizeof(visited));
}

int dfs(int index)
{
	int sum_sub, max_sub, num_sub;
	visited[index] = true;

	arc_node *p = arc[index]->next;
	sum_sub = max_sub = num_sub = 0;
	while (p)
	{
		if (!visited[p->id])
		{
			num_sub = dfs(p->id) + 1;
			if (num_sub > max_sub) max_sub = num_sub;
			sum_sub += num_sub;
		}
		p = p->next;
	}

	dp[index] = (n-sum_sub-1);
	if (dp[index] < max_sub) dp[index] = max_sub;

	return sum_sub;
}

void disp_ans()
{
	int ans = INF, index;
	for (int i = 1; i <= n; i++)
		if (dp[i] < ans) {
			ans = dp[i];
			index = i;
		}

	printf("%d %d\n", index, ans);
}

void clear()
{
	for (int i = 1; i <= n; i++)
	{
		arc_node *p = arc[i];
		arc_node *q = p->next;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		input();
		dfs(1);
		disp_ans();
		clear();
	}

	return 0;
}

