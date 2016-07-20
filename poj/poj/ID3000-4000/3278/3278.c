/*
 * poj 3278
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	100000

int n, k;
int visited[MAX+1];

typedef struct queue_node {
	int point;
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
	p->point = node.point;
	p->next = NULL;

	q->rear->next = p;
	q->rear = p;

	return 1;
}

int de_queue(link_queue *q, queue_node *node)
{
	if (q->front == q->rear)
		return 0;

	queue_node *p = q->front->next;
	node->point = p->point;

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

int bfs()
{
	if (n == k)
		return 0;
	link_queue q;
	init_queue(&q);
	queue_node p, node;
	memset(visited, 0, sizeof(visited));

	p.point = n;
	en_queue(&q, p);
	visited[p.point] = 1;
	while (!is_empty_queue(q))
	{
		de_queue(&q, &p);
		int next = p.point + 1;
		if (next >= 0 && next <= MAX && visited[next] == 0)
		{
			if (next == k)
				return visited[p.point];
			node.point = next;
			en_queue(&q, node);
			visited[next] = visited[p.point] + 1;
		}
		next = p.point - 1;
		if (next >= 0 && next <= MAX && visited[next] == 0)
		{
			if (next == k)
				return visited[p.point];
			node.point = next;
			en_queue(&q, node);
			visited[next] = visited[p.point] + 1;
		}
		next = p.point * 2;
		if (next >= 0 && next <= MAX && visited[next] == 0)
		{
			if (next == k)
				return visited[p.point];
			node.point = next;
			en_queue(&q, node);
			visited[next] = visited[p.point] + 1;
		}
	}

	destroy_queue(&q);
	return 0;
}

int main()
{
	scanf("%d%d", &n, &k);
	printf("%d\n", bfs());

	return 0;
}
