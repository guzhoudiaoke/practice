#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct face {
	int pre;
	int next;
} face;

int n, face_id[101];
face x[101][4];
int cord[101][4];
bool visited[101];
int max_cord[4], min_cord[4];

int get_index(int id)
{
	int i;
	if (id == 0)
		return 0;
	for (i = 1; i <= n; i++)
		if (face_id[i] == id)
			break;
	return i;
}

int get_len()
{
	max_cord[0] = max_cord[1] = max_cord[2] = max_cord[3] = 0;
	min_cord[0] = min_cord[1] = min_cord[2] = min_cord[3] = 0;
	queue<int> q;
	int p = 1;
	int left = n;
	cord[1][0] = cord[1][1] = cord[1][2] = cord[1][3] = 0;
	q.push(p);
	visited[1] = true;
	left--;

	while (! q.empty() && left > 0)
	{
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int m = x[p][i].pre;
			if (m && ! visited[m])
			{
				if (x[m][i].next != p)
					return -1;
				
				for (int j = 0; j < 4; j++)
					cord[m][j] = cord[p][j];
				cord[m][i]++;
				
				if (max_cord[i] < cord[m][i])
					max_cord[i] = cord[m][i];
				
				visited[m] = true;
				left--;
				if (left == 0)
					return 0;
				q.push(m);
			}

			m = x[p][i].next;
			if (m && ! visited[m])
			{
				if (x[m][i].pre != p)
					return -1;
				for (int j = 0; j < 4; j++)
					cord[m][j] = cord[p][j];
				cord[m][i]--;
				if (min_cord[i] > cord[m][i])
					min_cord[i] = cord[m][i];
				visited[m] = true;
				left--;
				if (left == 0)
					return 0;
				q.push(m);
			}
		}
	}

	return left;
}

void translate()
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 4; j++)
		{
			x[i][j].pre = get_index(x[i][j].pre);
			x[i][j].next = get_index(x[i][j].next);
		}
}

int main()
{
	int t, i, j, id, pre, next;
	cin >> t;

	while (t--)
	{
		cin >> n;
		memset(x, 0, sizeof(x));

		for (i = 0; i <= n; i++)
			visited[i] = false;

		for (i = 1; i <= n; i++)
		{
			cin >> id;
			face_id[i] = id;
			for (j = 0; j < 4; j++)
			{
				cin >> pre >> next;
				x[i][j].pre = pre;
				x[i][j].next = next;
			}
		}

		translate();

		int t = get_len();
		if (t != 0)
			cout << "Inconsistent" << endl;
		else
		{
			int result = 1;
			for (i = 0; i < 4; i++)
				result *= (max_cord[i]-min_cord[i]+1);
			
			cout << result << endl;
		}
	}

	return 0;
}
