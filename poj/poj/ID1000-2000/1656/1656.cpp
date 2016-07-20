/*
 * problem:	poj	1656
 * author:	guzhoudiaoke
 * time:	2011-10-07
 */

#include <iostream>
#include <string>

using namespace std;

const int BLACK = 1;
const int WHITE = 0;

int board[101][101];

void run(string cmd, int x, int y, int L)
{
	int i, j, count;
	if (cmd == "BLACK")
	{
		for (i = x; i <= x+L-1; i++)
			for (j = y; j <= y+L-1; j++)
				board[i][j] = BLACK;
	}
	else if (cmd == "WHITE")
	{
		for (i = x; i <= x+L-1; i++)
			for (j = y; j <= y+L-1; j++)
				board[i][j] = WHITE;
	}
	else if (cmd == "TEST")
	{
		count = 0;
		for (i = x; i <= x+L-1; i++)
			for (j = y; j <= y+L-1; j++)
				if (board[i][j] == BLACK)
					count ++;
		cout << count << endl;
	}
}

int main()
{
	string cmd;
	int t, x, y, L;

	for (x = 1; x <= 100; x++)
		for (y = 1; y <= 100; y++)
			board[x][y] = WHITE;

	cin >> t;
	while (t--)
	{
		cin >> cmd >> x >> y >> L;
		run(cmd, x, y, L);
	}

	return 0;
}