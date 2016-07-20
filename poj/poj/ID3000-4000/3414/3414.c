/*
 * poj 3414
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_node {
	int pot1;
	int pot2;
	int operate;
	int pre;
	struct queue_node *next;
} queue_node;

typedef struct link_queue {
	queue_node *front;
	queue_node *rear;
} link_queue;

int visited[101][101];
queue_node path[101*101];
link_queue q;

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

	p->pot1 = node.pot1; p->pot2 = node.pot2; p->operate = node.operate; p->pre = node.pre;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;

	return 1;
}

int de_queue(link_queue *q, queue_node *node)
{
	if (q->front == q->rear) return 0;

	queue_node *p = q->front->next;
	node->pot1 = p->pot1; node->pot2 = p->pot2; node->operate = p->operate; node->pre = p->pre;
	
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

int x = 0;

int bfs(int a, int b, int c)
{
	memset(visited, 0, sizeof(visited));
	memset(path, 0, sizeof(path));
	
	queue_node p, node;
	node.pot1 = 0; node.pot2 = 0; node.operate = 0;
	en_queue(&q, node);
	visited[0][0] = 1;
	
	while (!is_empty_queue(q))
	{
		de_queue(&q, &p);
		int p1, p2;
		
		path[x].operate = p.operate;
		path[x].pre = p.pre;
		if (p.pot1 == c || p.pot2 == c)
		{
			return visited[p.pot1][p.pot2] - 1;
		}
		
		// FILL(1)
		p1 = p.pot1; 
		p2 = p.pot2;
		if (p1 != a)
		{
			p1 = a;
			if (visited[p1][p2] == 0)
			{
				visited[p1][p2] = visited[p.pot1][p.pot2] + 1;
				node.pot1 = p1; node.pot2 = p2; node.operate = 1; node.pre = x;
				en_queue(&q, node);
			}
		}
		
		// FILL(2)
		p1 = p.pot1;
		p2 = p.pot2;
		if (p2 != b)
		{
			p2 = b;
			if (visited[p1][p2] == 0)
			{
				visited[p1][p2] = visited[p.pot1][p.pot2] + 1;
				node.pot1 = p1; node.pot2 = p2; node.operate = 2;  node.pre = x;
				en_queue(&q, node);
			}
		}
		
		// DROP(1)
		p1 = p.pot1; 
		p2 = p.pot2;
		if (p1 != 0)
		{
			p1 = 0;
			if (visited[p1][p2] == 0)
			{
				visited[p1][p2] = visited[p.pot1][p.pot2] + 1;
				node.pot1 = p1; node.pot2 = p2; node.operate = 3;  node.pre = x;
				en_queue(&q, node);
			}
		}
		
		// DROP(2)
		p1 = p.pot1; 
		p2 = p.pot2;
		if (p2 != 0)
		{
			p2 = 0;
			if (visited[p1][p2] == 0)
			{
				visited[p1][p2] = visited[p.pot1][p.pot2] + 1;
				node.pot1 = p1; node.pot2 = p2; node.operate = 4;  node.pre = x;
				en_queue(&q, node);
			}
		}
		
		// POUR(1,2)
		p1 = p.pot1; 
		p2 = p.pot2;
		if (p1 != 0 && p2 != b)
		{
			if (p1 + p2 >= b)
			{
				p1 = p1 + p2 - b;
				p2 = b;
			}
			else
			{
				p2 = p1 + p2;
				p1 = 0;
			}
			if (visited[p1][p2] == 0)
			{
				visited[p1][p2] = visited[p.pot1][p.pot2] + 1;
				node.pot1 = p1; node.pot2 = p2; node.operate = 5;  node.pre = x;
				en_queue(&q, node);
			}
		}
		
		// POUR(2,1)
		p1 = p.pot1; 
		p2 = p.pot2;
		if (p2 != 0 && p1 != a)
		{
			if (p1 + p2 >= a)
			{
				p2 = p1 + p2 - a;
				p1 = a;
			}
			else
			{
				p1 = p1 + p2;
				p2 = 0;
			}
			if (visited[p1][p2] == 0)
			{
				visited[p1][p2] = visited[p.pot1][p.pot2] + 1;
				node.pot1 = p1; node.pot2 = p2; node.operate = 6;  node.pre = x;
				en_queue(&q, node);
			}
		}
		
		x++;
	}
	
	return 0;
}

int main()
{
	int a, b, c, i;
	scanf("%d%d%d", &a, &b, &c);
	init_queue(&q);
	
	int step = bfs(a, b, c);
	int pp[101*101];
	if (step)
	{
		printf("%d\n", step);
		for (i = 0; i < step; i++)
		{
			pp[i] = path[x].operate;
			x = path[x].pre;
		}
		
		for (i = step-1; i >= 0; i--)
		{
			switch (pp[i])
			{
				case 1:
					printf("FILL(1)\n");
					break;
				case 2:
					printf("FILL(2)\n");
					break;
				case 3:
					printf("DROP(1)\n");
					break;
				case 4:	
					printf("DROP(2)\n");
					break;
				case 5:
					printf("POUR(1,2)\n");
					break;
				case 6:
					printf("POUR(2,1)\n");
					break;
			}
		}
	}
	else
		printf("impossible\n");
		
	destroy_queue(&q);
	
	return 0;
}

