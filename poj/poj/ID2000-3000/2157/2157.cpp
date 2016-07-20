#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef struct position {
	int row;
	int col;
} position;

int m, n, total_key[5], hold_key[5];
char map[20][20];
position start_pos;
bool open_door;

const int move[4][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

bool out_map(int r, int c)
{
	if (r < 0 || c < 0 || r >= m || c >= n)
		return true;
	return false;
}

void open_gate(char type)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (map[i][j] == type)
				map[i][j] = '.';
}

bool bfs_get_key()
{
	queue<position> q;
	position p, temp;
	bool flag = false;
	bool visited[20][20];
	memset(visited, false, sizeof(visited));

	q.push(start_pos);
	visited[start_pos.row][start_pos.col] = true;

	while (! q.empty())
	{
		p.row = q.front().row;
		p.col = q.front().col;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			temp.row = p.row + move[i][0];
			temp.col = p.col + move[i][1];
			char c = map[temp.row][temp.col];
			if (!out_map(temp.row, temp.col) && !visited[temp.row][temp.col])
			{
				if (c == '.' || (c >= 'a' && c <= 'e'))
				{
					visited[temp.row][temp.col] = true;
					q.push(temp);
					if (c != '.')
					{
						hold_key[c - 'a']++;
						map[temp.row][temp.col] = '.';
						flag = true;
						if (hold_key[c - 'a'] == total_key[c - 'a'])
						{
							open_gate(c);
							open_door = true;
						}
					}
				}
			}
		}
	}

	return flag;
}

bool bfs_get_goal()
{
	queue<position> q;
	position p, temp;
	bool visited[20][20];
	memset(visited, false, sizeof(visited));

	q.push(start_pos);
	visited[start_pos.row][start_pos.col] = true;

	while (! q.empty())
	{
		p.row = q.front().row;
		p.col = q.front().col;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			temp.row = p.row + move[i][0];
			temp.col = p.col + move[i][1];
			char c = map[temp.row][temp.col];
			if (!out_map(temp.row, temp.col) && c != 'X' && !visited[temp.row][temp.col])
			{
				if ( c >= 'A' && c <= 'E' &&
					(hold_key[c - 'A'] == 0 || hold_key[c - 'A'] != total_key[c - 'A']))
					continue;
				if (c == 'G')
					return true;
				if (c >= 'a' && c <= 'e')
				{
					hold_key[c - 'a']++;
					map[temp.row][temp.col] = '.';
					if (hold_key[c - 'a'] == total_key[c - 'a'])
					{
						open_gate(c);
						open_door = true;
					}
				}
				q.push(temp);
				visited[temp.row][temp.col] = true;
			}
		}
	}

	return false;
}

int main()
{
	int i, j;

	while (1)
	{
		cin >> m >> n;
		if (m == 0) break;
		
		for (i = 0; i < 5; i++)
		{
			total_key[i] = 0;
			hold_key[i] = 0;
		}

		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] >= 'a' && map[i][j] <= 'e')
					total_key[map[i][j]-'a']++;
				else if (map[i][j] == 'S')
				{
					start_pos.row = i;
					start_pos.col = j;
				}
			}
		}
		
		bool get_goal = false;
		do {
			open_door = false;
			if (bfs_get_goal())
				get_goal = true;
			bfs_get_key();
		} while (open_door && !get_goal);

		if (get_goal)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
