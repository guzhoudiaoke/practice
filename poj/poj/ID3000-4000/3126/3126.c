/*
 * poj 3126
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_node {
	int num;
	struct queue_node *next;
} queue_node;

typedef struct link_queue {
	queue_node *front;
	queue_node *rear;
} link_queue;

char is_prime[10000];
unsigned char visited[10000];

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

void get_prime()
{

	memset(is_prime, 1, sizeof(is_prime));
	int i, j;
	for (i = 2; i <= 100; i++)
		if (is_prime[i])
			for (j = i+i; j < 10000; j += i)
				is_prime[j] = 0;
}

int bfs(int from, int to)
{
	if (from == to)
		return 0;
	
	link_queue q;
	init_queue(&q);
	
	memset(visited, 0, sizeof(visited));
	
	queue_node p, node;
	node.num = from;
	visited[from] = 1;
	en_queue(&q, node);

	while (!is_empty_queue(q))
	{
		de_queue(&q, &p);
		int num = p.num;
		int n[4], i;
		for (i = 0; i < 4; i++)
		{
			n[i] = num % 10;
			num /= 10;
		}

		int x = p.num - n[0];
		for (i = x; i < x+10; i++)
		{
			if (i == to)
				return visited[p.num];
			if (is_prime[i] && visited[i] == 0)
			{
				visited[i] = visited[p.num] + 1;
				node.num = i;
				en_queue(&q, node);
			}
		}
		x = p.num - n[1]*10;
		for (i = x; i < x+100; i+=10)
		{
			if (i == to)
				return visited[p.num];
			if (is_prime[i] && visited[i] == 0)
			{
				visited[i] = visited[p.num] + 1;
				node.num = i;
				en_queue(&q, node);
			}
		}
		
		x = p.num - n[2]*100;
		for (i = x; i < x+1000; i+=100)
		{
			if (i == to)
				return visited[p.num];
			if (is_prime[i] && visited[i] == 0)
			{
				visited[i] = visited[p.num] + 1;
				node.num = i;
				en_queue(&q, node);
			}
		}
		
		x = p.num - n[3]*1000;
		for (i = x+1000; i < x+10000; i+=1000)
		{
			if (i == to)
				return visited[p.num];
			if (is_prime[i] && visited[i] == 0)
			{
				visited[i] = visited[p.num] + 1;
				node.num = i;
				en_queue(&q, node);
			}
		}
	}

	destroy_queue(&q);
	return 0;
}

int main()
{
	int n, i, prime_from, prime_to;
	get_prime();
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &prime_from, &prime_to);
		printf("%d\n", bfs(prime_from, prime_to));
	}

	return 0;
}
