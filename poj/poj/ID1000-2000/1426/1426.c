/*
 * poj 1426
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int residual[200];

typedef struct queue_node {
	long long num;
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

	p->num = node.num;
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
	node->num = p->num;

	q->front->next = p->next;
	if (p == q->rear)
		q->rear = q->front;

	free(p);
	return 1;
}

int is_empty_queue(link_queue q)
{
	return (q.front == q.rear);
}

long long bfs(int n)
{
	memset(residual, 0, sizeof(residual));
	link_queue q;
	init_queue(&q);
	queue_node p, node;
	p.num = 1;
	en_queue(&q, p);
	while (!is_empty_queue(q))
	{
		de_queue(&q, &p);
		long long num = p.num * 10;
		int r = num % n;
		if (r == 0)
			return num;
		if (residual[r] == 0)
		{
			node.num = num;
			en_queue(&q, node);
			residual[r] = 1;
		}
		
		num = p.num * 10 + 1;
		r = num % n;
		if (r == 0)
			return num;
		if (residual[r] == 0)
		{
			node.num = num;
			en_queue(&q, node);
			residual[r] = 1;
		}
	}
	
	destroy_queue(&q);
	return 0;
}

int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		printf("%lld\n", bfs(n));
	}

	return 0;
}
