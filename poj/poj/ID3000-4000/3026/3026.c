/*
 * poj 3026
 * guzhoudiaoke@126.com
 * 2011-09-18
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF	100000

typedef struct point {
	int row;
	int col;
} point;

typedef struct queue_node {
	int row;
	int col;
	struct queue_node *next;
} queue_node;

typedef struct link_queue {
	queue_node *front;
	queue_node *rear;
} link_queue;

char maze[61][61];
point p_A_S[112];
int alien_num;
int dist[112][112];
int closedge[112];

int move[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

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

	p->row = node.row; p->col = node.col;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;

	return 1;
}

int de_queue(link_queue *q, queue_node *node)
{
	if (q->front == q->rear) return 0;

	queue_node *p = q->front->next;
	node->row = p->row; node->col = p->col;
	
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

void bfs(int no)
{
	link_queue q;
	queue_node node, p;
	init_queue(&q);
	
	int i, j;
	int visited[51][51];
	memset(visited, 0, sizeof(visited));
	
	node.row = p_A_S[no].row;
	node.col = p_A_S[no].col;
	en_queue(&q, node);
	visited[node.row][node.col] = 1;
	
	while (! is_empty_queue(q))
	{
		de_queue(&q, &p);
		for (i = 0; i < 4; i++)
		{
			int r = p.row + move[i][0];
			int c = p.col + move[i][1];
			if (maze[r][c] != '#' && visited[r][c] == 0)
			{
				if (maze[r][c] == 'S' || maze[r][c] == 'A')
					for (j = no+1; j < alien_num; j++)
						if (r == p_A_S[j].row && c == p_A_S[j].col && dist[no][j] == 0)
						{
							dist[j][no] = dist[no][j] = visited[p.row][p.col];
							break;
						}
				node.row = r;
				node.col = c;
				en_queue(&q, node);
				visited[r][c] = visited[p.row][p.col] + 1;
			}
		}
	}
	
	destroy_queue(&q);
}

int mst_prim()
{
	int i, j, k, min, sum;
	for (i = 0; i < alien_num; i++)
		closedge[i] = dist[0][i];
	closedge[0] = 0;
	
	sum = 0;
	for (i = 1; i < alien_num; i++)
	{
		min = INF;
		for (j = 0; j < alien_num; j++)
			if (closedge[j] && closedge[j] < min)
			{
				min = closedge[j];
				k = j;
			}
		
		sum += min;
		closedge[k] = 0;
		
		for (j = 0; j < alien_num; j++)
			if (closedge[j] && dist[k][j] < closedge[j])
				closedge[j] = dist[k][j];
	}
	
	return sum;
}

int main()
{
	int t, i, j, x, y;
	char buf[100];
	scanf("%d", &t);
	getchar();

	while (t--)
	{
		gets(buf);
		sscanf(buf, "%d%d", &x, &y);
		
		alien_num = 0;
		for (i = 0; i < y; i++)
		{
			gets(buf);
			for (j = 0; j < x; j++)
			{
				maze[i][j] = buf[j];
				if (maze[i][j] == 'A' || maze[i][j] == 'S')
				{
					p_A_S[alien_num].row = i;
					p_A_S[alien_num].col = j;
					alien_num++;
				}
			}
		}

		memset(dist, 0, sizeof(dist));
		for (i = 0; i < alien_num; i++)
			bfs(i);
		
		printf("%d\n", mst_prim());
	}

	return 0;
}

