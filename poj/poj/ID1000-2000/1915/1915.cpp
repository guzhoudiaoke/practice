/*
 * poj 1915
 * guzhoudiaoke
 * 2011-10-20
 */

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef struct position {
	int x;
	int y;
} position;

int len, visited[300][300];
position from, to;

int move[8][2] = {
	{-1, 2}, {1, 2}, {-2, 1}, {2, 1},
	{1, -2}, {-1, -2}, {-2, -1}, {2, -1},
};

bool position_equal(position p1, position p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	return false;
}

int bfs()
{
	queue<position> q;	
	position p, pos_next;
	int i;

	if (position_equal(from, to))
		return 0;

	memset(visited, 0, sizeof(visited));
	q.push(from);
	visited[from.x][from.y] = 1;

	while (! q.empty())
	{
		p.x = q.front().x; 
		p.y = q.front().y;
		q.pop();

		for (i = 0; i < 8; i++)
		{
			pos_next.x = p.x + move[i][0];
			pos_next.y = p.y + move[i][1];

			if (pos_next.x < 0 || pos_next.y < 0 || pos_next.x >= len || pos_next.y >= len)
				continue;
			if (!visited[pos_next.x][pos_next.y])
			{
				if (position_equal(pos_next, to))
					return visited[p.x][p.y];

				visited[pos_next.x][pos_next.y] = visited[p.x][p.y] + 1;
				q.push(pos_next);
			}
		}
	}

	return -1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &len);
		scanf("%d %d", &from.x, &from.y);
		scanf("%d %d", &to.x, &to.y);

		printf("%d\n", bfs());
	}

	return 0;
}

