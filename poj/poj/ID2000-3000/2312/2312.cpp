#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct position {
	int row;
	int col;
	int depth;
} position;

position start;

char map[301][301];
bool visited[301][301];
int m, n;

const int move[4][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1},
};

void get_start()
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (map[i][j] == 'Y')
			{
				start.row = i;
				start.col = j;
				start.depth = 0;
			}
		}
}

bool out_of_map(position p)
{
	if (p.row < 0 || p.row >= m || p.col < 0 || p.col >= n)
		return true;

	return false;
}

int bfs()
{
	queue<position> q;
	position p, tmp;
	memset(visited, false, sizeof(visited));

	q.push(start);
	visited[start.row][start.col] = true;

	while (!q.empty())
	{
		tmp.row = q.front().row;
		tmp.col = q.front().col;
		tmp.depth = q.front().depth;
		q.pop();

		if (map[tmp.row][tmp.col] == 'B')
		{
			tmp.depth++;
			q.push(tmp);
			map[tmp.row][tmp.col] = 'E';
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				p.row = tmp.row + move[i][0];
				p.col = tmp.col + move[i][1];
				p.depth = tmp.depth + 1;

				if (!out_of_map(p) && !visited[p.row][p.col])
				{
					if (map[p.row][p.col] == 'T')
						return p.depth;

					if (map[p.row][p.col] == 'E' || map[p.row][p.col] == 'B')
					{
						visited[p.row][p.col] = true;
						q.push(p);
					}
				}
			}
		}
	}

	return -1;
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;

		for (i = 0; i < m; i++)
			scanf("%s", map[i]);
		
		get_start();
		printf("%d\n", bfs());
	}

	return 0;
}

