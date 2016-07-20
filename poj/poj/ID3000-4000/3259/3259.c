/*
 * poj 3259
 * guzhoudiaoke@126.com
 * 2011-09-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 	25000001
#define LONGEST	10000

int way[501][501];
int d[501];

int bellman_ford(int start, int n)
{
	int u, v, i;
	for (i = 1; i <= n; i++)
		d[i] = INF;
	d[start] = 0;

	for (i = 1; i < n; i++)
		for (u = 1; u <= n; u++)
			for (v = 1; v <= n; v++)
				if (way[u][v] < LONGEST && d[u] < INF && d[v] > d[u]+way[u][v])
				{
					d[v] = d[u] + way[u][v];
					if (d[start] < 0)
						return 1;
				}
	
	for (u = 1; u <= n; u++)
		for (v = 1; v <= n; v++)
			if (way[u][v] < LONGEST && d[u] < INF && d[v] > d[u]+way[u][v])
				return 1;

	if (d[start] < 0)
		return 1;

	return 0;
}



typedef struct queue_node {
	int no;
	struct queue_node *next;
} queue_node;

typedef struct link_queue {
	queue_node *front;
	queue_node *rear;
} link_queue;

int init_queue(link_queue *q)
{
	q->front = q->rear = (queue_node *)malloc(sizeof(queue_node));
	if (!q->front) return 0;

	q->front->next = NULL;
	return 1;
}

int destroy_queue(link_queue *q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}

	return 1;
}

int en_queue(link_queue *q, queue_node node)
{
	queue_node *p = (queue_node *)malloc(sizeof(queue_node));
	if (!p) return 0;

	p->no = node.no;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;

	return 1;
}

int de_queue(link_queue *q, queue_node *node)
{
	if (q->front == q->rear) return 0;

	queue_node *p = q->front->next;
	node->no = p->no;
	
	q->front->next = p->next;
	if (q->rear == p)
		q->rear = q->front;
	
	free(p);
	return 1;
}

int is_empty_queue(link_queue q)
{
	return (q.front == q.rear);
}


int visited[501];
int count[501];
link_queue q;
queue_node node, p;

int spfa(int s, int n)
{
	int u, v, i, temp;
	for (i = 1; i <= n; i++)
	{
		d[i] = INF;
		visited[i] = 0;
		count[i] = 0;
	}
	d[s] = 0;
	visited[s] = 1;
	count[s] = 1;
	
	init_queue(&q);
	node.no = s;
	en_queue(&q, node);
	
	while (!is_empty_queue(q))
	{
		de_queue(&q, &p);
		u = p.no;
		visited[u] = 0;		// 表示不在队列中
		for (v = 1; v <= n; v++)
			if (way[u][v] < LONGEST)
			{	
				if (d[v] > d[u]+way[u][v])
				{
					d[v] = d[u] + way[u][v];;
					if (visited[v] == 0)
					{
						visited[v] = 1;
						count[v]++;
						if (count[v] >= n)
							return 1;
						node.no = v;
						en_queue(&q, node);
					}
				}
			}
	}
	
	destroy_queue(&q);
	
	if (d[s] < 0)
		return 1;
	
	return 0;
}

int main()
{
	int f, n, m, w, i, j, from, to, dist;
	scanf("%d", &f);

	while (f--)
	{
		scanf("%d%d%d", &n, &m, &w);

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				way[i][j] = LONGEST;

		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &from, &to, &dist);
			if (dist < way[from][to])
				way[from][to] = way[to][from] = dist;
		}

		for (i = 1; i <= w; i++)
		{
			scanf("%d%d%d", &from, &to, &dist);
			way[from][to] = -dist;
		}

		int test = 1, find = 0;;
		while (!find)
		{
			for (i = 1; i <= n; i++)
				if (way[test][i] < LONGEST)
				{
					find = 1;
					break;
				}
			test++;
		}
		if (spfa(test, n))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

