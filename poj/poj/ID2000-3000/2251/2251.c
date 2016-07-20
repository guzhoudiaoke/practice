/*
 * poj 2251
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// north, south, east, west, up, down
int move[6][3] = { {0, -1, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0} };

char map[30][30][31];
int visited[30][30][30];
int level, row, col;

typedef struct queue_node {
	int level;
	int row;
	int col;
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

	p->level = node.level; p->row = node.row; p->col = node.col;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;

	return 1;
}

int de_queue(link_queue *q, queue_node *node)
{
	if (q->front == q->rear) return 0;

	queue_node *p = q->front->next;
	node->level = p->level; node->row = p->row; node->col = p->col;
	
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

int out_of_map(int l, int r, int c)
{
	if (l < 0 || l >= level || r < 0 || r >= row || c < 0 || c >= col)
		return 1;
	return 0;
}

int bfs(int start_l, int start_r, int start_c)
{
	int i, j, k;
	memset(visited, 0, sizeof(visited));
	link_queue q;
	queue_node p, node;
	init_queue(&q);

	p.level = start_l; p.row = start_r; p.col = start_c;
	en_queue(&q, p);
	visited[start_l][start_r][start_c] = 1;

	while (!is_empty_queue(q))
	{
		de_queue(&q, &p);
		//printf("%d, %d, %d\n", p.level, p.row, p.col);

		for (i = 0; i < 6; i++)		// 六种走法
		{
			int l = p.level + move[i][0];
			int r = p.row + move[i][1];
			int c = p.col + move[i][2];
			if (!out_of_map(l, r, c) && map[l][r][c] != '#' && visited[l][r][c] == 0)
			{
				if (map[l][r][c] == 'E')
					return visited[p.level][p.row][p.col];
				//printf("%d: (%d, %d, %d)\n", i, l, r, c);
				visited[l][r][c] = visited[p.level][p.row][p.col] + 1;
				node.level = l; node.row = r; node.col = c;
				en_queue(&q, node);
			}
		}
	}

	destroy_queue(&q);
	return 0;
}

void find_s(int *l, int *r, int *c)
{
	int i, j, k;
	for (i = 0; i < level; i++)
		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++)
				if (map[i][j][k] == 'S')
				{
					*l = i;
					*r = j;
					*c = k;
					return;
				}
}


int main()
{
	int start_level, start_row, start_col, i, j, k;
	while (1)
	{
		scanf("%d%d%d", &level, &row, &col);
		if (level == 0 && row == 0 && col == 0)
			break;

		for (i = 0; i < level; i++)
			for (j = 0; j < row; j++)
				scanf("%s", map[i][j]);
		
		find_s(&start_level, &start_row, &start_col);

		int step = bfs(start_level, start_row, start_col);
		if (step)
			printf("Escaped in %d minute(s).\n", step);
		else
			printf("Trapped!\n");
	}

	return 0;
}
