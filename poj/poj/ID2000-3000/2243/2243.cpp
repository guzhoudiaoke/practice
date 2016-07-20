#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct position {
	int row;
	int col;
} position;

position start, target;
int visited[9][9];

const int move[8][2] = {
	{-2, 1}, {-1, 2}, {1, 2}, {2, 1},
	{2, -1}, {1, -2}, {-1, -2}, {-2, -1},
};

bool equal_position(position a, position b)
{
	if (a.row == b.row && a.col == b.col)
		return true;
	return false;
}

bool out_of_board(position p)
{
	if (p.row <= 0 || p.row > 8 || p.col <= 0 || p.col > 8)
		return true;
	return false;
}

int bfs()
{
	if (equal_position(start, target))
		return 0;

	queue<position> q;
	position p, tmp;
	memset(visited, 0, sizeof(visited));

	visited[start.row][start.col] = 1;
	q.push(start);

	while (!q.empty())
	{
		tmp.row = q.front().row; tmp.col = q.front().col;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int r = tmp.row + move[i][0];
			int c = tmp.col + move[i][1];
			p.row = r; p.col = c;

			if (!out_of_board(p) && !visited[r][c])
			{
				if (equal_position(p, target))
					return visited[tmp.row][tmp.col];
				
				visited[r][c] = visited[tmp.row][tmp.col] + 1;
				q.push(p);
			}
		}
	}

	return -1;
}

int main()
{
	char rs, rt;
	int cs, ct;

	while (scanf("%c%d %c%d\n", &rs, &cs, &rt, &ct) != EOF)
	{
		start.row = rs-'a'+1; start.col = cs;
		target.row = rt-'a'+1; target.col = ct;

		printf("To get from %c%d to %c%d takes %d knight moves.\n", 
			rs, cs, rt, ct, bfs());
	}

	return 0;
}
