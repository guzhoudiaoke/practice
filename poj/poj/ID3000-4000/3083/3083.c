/*
 * poj 3083
 * guzhoudiaoke@126.com
 * 2011-09-08
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int move[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

char map[40][41];
int width, height;

void find_start(int *row, int *col, int *dir)
{
	int i;
	for (i = 1; i < height-1; i++)
	{
		if (map[i][0] == 'S')
		{
			*row = i;
			*col = 0;
			*dir = 0;
			return;
		}
		else if (map[i][width-1] == 'S')
		{
			*row = i;
			*col = width - 1;
			*dir = 2;
			return;
		}
	}
	for (i = 1; i < width-1; i++)
	{
		if (map[0][i] == 'S')
		{
			*row = 0;
			*col = i;
			*dir = 1;
			return;
		}
		if (map[height-1][i] == 'S')
		{
			*row = height - 1;
			*col = i;
			*dir = 3;
			return;
		}
	}
}

int step;

int left_dir(int dir)
{
	return (dir + 3) % 4;
}

int right_dir(int dir)
{
	return (dir + 1) % 4;
}

int DFS_left(int row, int col, int dir)
{
	if (map[row][col] == 'E')
		return 1;
	int new_row, new_col, new_dir, i;
	
	new_dir = left_dir(dir);
	// 按左，上，右，下的顺序搜索遍历
	for (i = 0; i < 4; i++)
	{
		new_row = row + move[new_dir][0];
		new_col = col + move[new_dir][1];
		if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width && map[new_row][new_col] != '#')
		{
			return 1 + DFS_left(new_row, new_col, new_dir);
		}
		new_dir = right_dir(new_dir);
	}
	
	return 0;
}

int DFS_right(int row, int col, int dir)
{
	if (map[row][col] == 'E')
		return 1;
	int new_row, new_col, new_dir, i;
	
	new_dir = right_dir(dir);
	// 按右，上，左，下的顺序遍历
	for (i = 0; i < 4; i++)
	{
		new_row = row + move[new_dir][0];
		new_col = col + move[new_dir][1];
		if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width && map[new_row][new_col] != '#')
		{
			return 1 + DFS_right(new_row, new_col, new_dir);
		}
		new_dir = left_dir(new_dir);
	}
	
	return 0;
}

int visited[40][40];
typedef struct queue_node {
	int row;
	int col;
	int depth;
	struct queue_node *next;
} queue_node;

typedef struct link_queue {
	struct queue_node *front;
	struct queue_node *rear;
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
	
	p->row = node.row;
	p->col = node.col;
	p->depth = node.depth;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	
	return 1;
}

int de_queue(link_queue *q, queue_node *node)
{
	if (q->front == q->rear) return 0;
	queue_node *p = q->front->next;
	node->row = p->row;
	node->col = p->col;
	node->depth = p->depth;
	q->front->next = p->next;
	if (q->rear == p) q->rear = q->front;
	free(p);
	
	return 1;
}

int empty_queue(link_queue q)
{
	return (q.front == NULL);
}
/*
int BFS(int sx,int sy)
{
	int i, depth;
	memset(visited,0,sizeof(visited));
	link_queue q;
	init_queue(&q);
	queue_node p;
	p.row = sx; p.col = sy; p.depth = 1;
	visited[sx][sy]=1;
	en_queue(&q, p);
	while(!empty_queue(q))
	{
		de_queue(&q, &p);
		sx = p.row; sy = p.col; depth = p.depth;
		if(map[sx][sy]=='E')
			return depth;
		for(i=0;i<4;i++)
		{
			int x1=sx+move[i][0];
			int y1=sy+move[i][1];
			if(x1>=0&&x1<height&&y1>=0&&y1<width&&map[x1][y1]!='#'&&!visited[x1][y1])
			{
				visited[x1][y1]=1;
				p.row = x1; p.col = y1; p.depth = depth + 1;
				en_queue(&q, p);
			}
		}
	}
	return 0;
}*/
int BFS(int row, int col)
{
	int i, r, c, d;
	link_queue q;
	queue_node p;
	int j;
	memset(visited, 0, sizeof(visited));
	
	init_queue(&q);
	p.row = row; p.col = col; p.depth = 1;
	en_queue(&q, p);
	
	while (!empty_queue(q))
	{
		de_queue(&q, &p);
		r = p.row; c = p.col; d = p.depth+1;
		for (i = 0; i < 4; i++)
		{
			int new_row = r + move[i][0];
			int new_col = c + move[i][1];
			if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width)
			{
				if (map[new_row][new_col] == 'E')
					return d;
				if (map[new_row][new_col] == '.' && (!visited[new_row][new_col]))
				{
					visited[new_row][new_col] = 1;
					p.row = new_row; p.col = new_col; p.depth = d;
					en_queue(&q, p);
				}
			}
		}
	}
	
	destroy_queue(&q);
	return 0;
}

/*
int BFS(int row, int col)
{
	int i, j;
	queue <queue_node> q;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			visited[i][j] = 0;
	
	queue_node p;
	p.row = row; p.col = col; p.depth = 1;
	q.push(p);
	
	int new_row, new_col, depth;
	while (!q.empty())
	{
		p = q.front(); 
		q.pop();
		for (i = 0; i < 4; i++)
		{
			new_row = p.row + move[i][0];
			new_col = p.col + move[i][1];
			depth = p.depth + 1;
			if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width)
			{
				if (map[new_row][new_col] == 'E')
					return depth;
				if (map[new_row][new_col] == '.' && (!visited[new_row][new_col]))
				{
					visited[new_row][new_col] = 1;
					p.row = new_row; p.col = new_col; p.depth = depth;
					q.push(p);
				}
			}
		}
	}

	return 0;
}*/
/*
int BFS(int sx,int sy)
{
int i;
 memset(visited,0,sizeof(visited));
 queue< pair<int,int> >q;
 pair<int,int>p=make_pair(sx,sy);
 visited[sx][sy]=1;
 q.push(p);
 while(!q.empty())
 {
  p=q.front();q.pop();
  if(map[p.first][p.second]=='E')
   return visited[p.first][p.second];
  for(i=0;i<4;i++)
  {
   int x1=p.first+move[i][0];
   int y1=p.second+move[i][1];
   if(x1>=0&&x1<height&&y1>=0&&y1<width&&map[x1][y1]!='#'&&!visited[x1][y1])
   {
    visited[x1][y1]=visited[p.first][p.second]+1;
    q.push(make_pair(x1,y1));
   }
  }
 }
 return 0;
}
*/
/*
int BFS(int sx,int sy)
{
 int i;
 memset(visited,0,sizeof(visited));
 queue<int> q;
 int p = sx*width + sy;
 visited[sx][sy]=1;
 q.push(p);
 while(!q.empty())
 {
  p=q.front();q.pop();
  sx = p/width; sy = p%width;
  if(map[sx][sy]=='E')
   return visited[sx][sy];
  for(i=0;i<4;i++)
  {
   int x1=sx+move[i][0];
   int y1=sy+move[i][1];
   if(x1>=0&&x1<height&&y1>=0&&y1<width&&map[x1][y1]!='#'&&!visited[x1][y1])
   {
    visited[x1][y1]=visited[sx][sy]+1;
    q.push(x1*width + y1);
   }
  }
 }
 return 0;
}*/
/*
int BFS(int sx,int sy)
{
 int i;
 memset(visited,0,sizeof(visited));
 queue<queue_node> q;
 queue 
 queue_node p;
 p.row = sx; p.col = sy;
 visited[sx][sy]=1;
 q.push(p);
 while(!q.empty())
 {
  p=q.front();q.pop();
  sx = p.row; sy = p.col;
  if(map[sx][sy]=='E')
   return visited[sx][sy];
  for(i=0;i<4;i++)
  {
   int x1=sx+move[i][0];
   int y1=sy+move[i][1];
   if(x1>=0&&x1<height&&y1>=0&&y1<width&&map[x1][y1]!='#'&&!visited[x1][y1])
   {
    visited[x1][y1]=visited[sx][sy]+1;
    p.row = x1; p.col = y1;
    q.push(p);
   }
  }
 }
 return 0;
}*/

/*
int BFS(int sx,int sy)
{
	int i, depth;
	memset(visited,0,sizeof(visited));
	link_queue q;
	init_queue(&q);
	queue_node p;
	p.row = sx; p.col = sy; p.depth = 1;
	visited[sx][sy]=1;
	en_queue(&q, p);
	while(!empty_queue(q))
	{
		de_queue(&q, &p);
		sx = p.row; sy = p.col; depth = p.depth;
		if(map[sx][sy]=='E')
			return depth;
		for(i=0;i<4;i++)
		{
			int x1=sx+move[i][0];
			int y1=sy+move[i][1];
			if(x1>=0&&x1<height&&y1>=0&&y1<width&&map[x1][y1]!='#'&&!visited[x1][y1])
			{
				visited[x1][y1]=1;
				p.row = x1; p.col = y1; p.depth = depth + 1;
				en_queue(&q, p);
			}
		}
	}
	return 0;
}
*/
int main()
{
	int n, i, start_row, start_col, start_dir;
	scanf("%d", &n);
	while (n--) 
	{
		scanf("%d%d", &width, &height);
		for (i = 0; i < height; i++)
			scanf("%s", map[i]);
	
		find_start(&start_row, &start_col, &start_dir);
		
		step = DFS_left(start_row, start_col, start_dir);
		printf("%d", step);
		
		step = DFS_right(start_row, start_col, start_dir);
		printf(" %d", step);
		
		step = BFS(start_row, start_col);
		printf(" %d\n", step);
	}
	
	return 0;
}

