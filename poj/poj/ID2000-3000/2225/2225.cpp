#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct position {
	int x;
	int y;
	int z;
} position;

const int move[6][3] = {
	{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, 
	{0, -1, 0}, {0, 0, 1}, {0, 0, -1}
};

char space[10][10][10];
int visited[10][10][10];
int n;
position start, target;

bool position_equal(position a, position b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z)
		return true;
	return false;
}

bool out_of_space(position p)
{
	if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= n || p.z < 0 || p.z >= n)
		return true;
	return false;
}

int bfs()
{
	if (position_equal(start, target))
		return 0;
	
	memset(visited, 0, sizeof(visited));
	queue<position> q;
	position p, temp;
	q.push(start);
	visited[start.z][start.y][start.x] = 1;

	while (!q.empty())
	{
		p.x = q.front().x; p.y = q.front().y; p.z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			temp.x = p.x + move[i][0];
			temp.y = p.y + move[i][1];
			temp.z = p.z + move[i][2];

			if (!out_of_space(temp) && !visited[temp.z][temp.y][temp.x] 
				&& space[temp.z][temp.y][temp.x] != 'X')
			{
				if (position_equal(temp, target))
					return visited[p.z][p.y][p.x];
				visited[temp.z][temp.y][temp.x] = visited[p.z][p.y][p.x] + 1;
				q.push(temp);
			}
		}
	}

	return -1;
}

int main()
{
	char cmd[16];

	while (scanf("%s %d", cmd, &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%s", space[i][j]);

		scanf("%d %d %d", &start.x, &start.y, &start.z);
		scanf("%d %d %d", &target.x, &target.y, &target.z);
		scanf("%s", cmd);

		int result = bfs();
		if (result == -1)
			printf("NO ROUTE\n");
		else
			printf("%d %d\n", n, result);
	}

	return 0;
}

