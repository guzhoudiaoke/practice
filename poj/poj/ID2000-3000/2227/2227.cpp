/*
 * poj 2227
 * guzhoudiaoke@126.com
 * 2011-11-12
 */

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int height[301][301], w, h;
bool visited[301][301];

typedef struct square {
	int row;
	int col;
	int hei;
} square;

const int move[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1},
};

bool operator < (const square s1, const square s2)
{
	return s1.hei > s2.hei;
}

priority_queue<square, vector<square> > q;

bool out_of_bowl(square s)
{
	if (s.row <= 1 || s.row >= h || s.col <= 1 || s.col >= w)
		return true;

	return false;
}

int bfs()
{
	square s, p;
	int ans = 0;

	while (!q.empty())
	{
		s.row = q.top().row;
		s.col = q.top().col;
		s.hei = q.top().hei;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			p.row = s.row + move[i][0];
			p.col = s.col + move[i][1];

			if (!out_of_bowl(p) && !visited[p.row][p.col])
			{
				if (height[p.row][p.col] < s.hei)
				{
					ans += s.hei - height[p.row][p.col];
					p.hei = s.hei;
				}
				else
				{
					p.hei = height[p.row][p.col];
				}

				visited[p.row][p.col] = true;
				q.push(p);
			}
		}
	}

	return ans;
}

int main()
{
	int i, j;
	square s;
	
	memset(visited, false, sizeof(visited));

	scanf("%d %d", &w, &h);
	for (i = 1; i <= h; i++)
		for (j = 1; j <= w; j++)
		{
			scanf("%d", &height[i][j]);
			if (i == 1 || i == h || j == 1 || j == w) {
				s.row = i;
				s.col = j;
				s.hei = height[i][j];
				q.push(s);
				visited[i][j] = true;
			}
		}
	
	printf("%d\n", bfs());

	return 0;
}

