///*
// * problem:	poj 1166
// * author:	guzhoudiaoke
// * time:	2011-10-08
// */
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int move [10][10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//					  0, 1, 1, 0, 1, 1, 0, 0, 0, 0,
//					  0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
//					  0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
//					  0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
//					  0, 0, 1, 0, 1, 1, 1, 0, 1, 0,
//					  0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
//					  0, 0, 0, 0, 1, 1, 0, 1, 1, 0,
//					  0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
//					  0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
//};
//
//const int turn[4] = { 1, 2, 3, 0 };
//
//typedef struct colocks {
//	int clock[10];
//	int mov;
//	int father;
//} clocks;
//
//clocks c;
//vector<clocks> v;
//vector<int> ans;
//int cur, size;
//
//bool finish(clocks c)
//{
//	int i;
//	for (i = 1; i <= 9; i++)
//		if (c.clock[i])
//			return false;
//
//	return true;
//}
//
//void bfs()
//{
//	clocks p, t;
//	int i, j;
//
//	v.push_back(c);
//	cur = 0;
//	size = 0;
//
//	while (cur != v.size())
//	{
//		p = v[cur];
//		for (i = p.mov; i <= 9; i++)
//		{
//			for (j = 1; j <= 9; j++)
//			{
//				if (move[i][j])
//					t.clock[j] = turn[p.clock[j]];
//				else
//					t.clock[j] = p.clock[j];
//			}
//
//			t.mov = i;
//			t.father = cur;
//			v.push_back(t);
//
//			if (finish(t))
//				return;
//		}
//		cur++;
//	}
//}
//
//int main()
//{
//	int i;
//	for (i = 1; i <= 9; i++)
//		cin >> c.clock[i];
//	c.mov = 1;
//	c.father = 0;
//	
//	bfs();
//
//	int t = v.size()-1;
//	while (1)
//	{
//		ans.push_back(v[t].mov);
//		t = v[t].father;
//		if (t == 0)
//			break;
//	}
//
//	vector<int>::reverse_iterator rit = ans.rbegin();
//	while (rit != ans.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//
//	return 0;
//}


///*
// * problem:	poj 1166
// * author:	guzhoudiaoke
// * time:	2011-10-08
// */
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int move [10][10] = 
//{ 
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//	0, 1, 1, 0, 1, 1, 0, 0, 0, 0,
//	0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
//	0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
//	0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
//	0, 0, 1, 0, 1, 1, 1, 0, 1, 0,
//	0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
//	0, 0, 0, 0, 1, 1, 0, 1, 1, 0,
//	0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
//	0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
//};
//
//const int turn[4] = { 1, 2, 3, 0 };
//
//typedef struct path {
//	char mov;
//	long long father;
//} path;
//
//vector<path> v;
//vector<int> ans;
//queue<int> q;
//
//int cur;
//
//void bfs(int clock)
//{
//	path p, t;
//	int i, j;
//	int c, temc;
//
//	p.father = 0;
//	p.mov = 0;
//	v.push_back(p);
//	cur = 0;
//	q.push(clock);
//
//	while (! q.empty())
//	{
//		c = q.front();
//		q.pop();
//		for (i = p.mov; i <= 9; i++)
//		{
//			temc = 0;
//			for (j = 1; j <= 9; j++)
//			{
//				int tur = (c >> j*2) & 0x3;
//				if (move[i][j])
//					temc |= (turn[tur] << j*2);
//				else
//					temc |= (tur << j*2);
//			}
//
//			t.mov = i;
//			t.father = cur;
//			v.push_back(t);
//			q.push(temc);
//
//			if (temc == 0)
//				return;
//		}
//		cur++;
//	}
//}
//
//int main()
//{
//	int i, m, clo, c;
//	m = 2;
//	c = 0x0;
//	for (i = 1; i <= 9; i++)
//	{
//		cin >> clo;
//		c |= (clo << m);
//		m += 2;
//	}
//	
//	bfs(c);
//
//	int t = v.size()-1;
//	while (1)
//	{
//		ans.push_back(v[t].mov);
//		t = v[t].father;
//		if (t == 0)
//			break;
//	}
//
//	vector<int>::reverse_iterator rit = ans.rbegin();
//	while (rit != ans.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//
//	return 0;
//}


///*
// * problem:	poj 1166
// * author:	guzhoudiaoke
// * time:	2011-10-08
// */
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int move [9][9] = 
//{ 
//	1, 1, 0, 1, 1, 0, 0, 0, 0,
//	1, 1, 1, 0, 0, 0, 0, 0, 0,
//	0, 1, 1, 0, 1, 1, 0, 0, 0,
//	1, 0, 0, 1, 0, 0, 1, 0, 0,
//	0, 1, 0, 1, 1, 1, 0, 1, 0,
//	0, 0, 1, 0, 0, 1, 0, 0, 1,
//	0, 0, 0, 1, 1, 0, 1, 1, 0,
//	0, 0, 0, 0, 0, 0, 1, 1, 1,
//	0, 0, 0, 0, 1, 1, 0, 1, 1,
//};
//
//const int turn[4] = { 1, 2, 3, 0 };
//
//typedef struct path {
//	char mov;
//	int father;
//} path;
//
//vector<path> v;
//queue<int> q;
//vector<int> ans;
//
//int cur;
//bool visited[262145] = { false };
//
//void bfs(int clock)
//{
//	path p, t;
//	int i, j, c, temc;
//
//	p.father = 0;
//	p.mov = 0;
//	v.push_back(p);
//	cur = 0;
//	
//	q.push(clock);
//	visited[clock] = true;
//
//	while (! q.empty())
//	{
//		p.father = v[cur].father;
//		p.mov = v[cur].mov;
//		
//		c = q.front();
//		q.pop();
//		
//		for (i = p.mov; i < 9; i++)
//		{
//			temc = 0;
//			for (j = 0; j < 9; j++)
//			{
//				int tur = (c >> j*2) & 0x03;
//				if (move[i][j])
//					temc |= (turn[tur] << j*2);
//				else
//					temc |= (tur << j*2);
//			}
//
//			t.mov = i;
//			t.father = cur;
//			
//			if (! visited[temc])
//			{
//				v.push_back(t);
//				q.push(temc);
//				visited[temc] = true;
//			}
//
//			if (temc == 0)
//				return;
//		}
//		cur++;
//	}
//}
//
//int main()
//{
//	int i, m, clo, c;
//	m = 0;
//	c = 0x0;
//	for (i = 1; i <= 9; i++)
//	{
//		cin >> clo;
//		c |= (clo << m);
//		m += 2;
//	}
//	
//	bfs(c);
//
//	int t = v.size()-1;
//	while (1)
//	{
//		if (t == 0)
//			break;
//		ans.push_back(v[t].mov);
//		t = v[t].father;
//	}
//
//	vector<int>::reverse_iterator rit = ans.rbegin();
//	while (rit != ans.rend())
//	{
//		cout << *rit + 1 << " ";
//		rit++;
//	}
//
//	return 0;
//}


/*
 * problem:	poj 1166
 * author:	guzhoudiaoke
 * time:	2011-10-08
 */

/*
 * 有九个钟，九种操作，每种操作顺时针转某几个钟，要求最少次数，使九个钟到12点
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int move[9][9] = 
{ 
	1, 1, 0, 1, 1, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 0, 1, 1, 0, 0, 0,
	1, 0, 0, 1, 0, 0, 1, 0, 0,
	0, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 0, 1, 0, 0, 1, 0, 0, 1,
	0, 0, 0, 1, 1, 0, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 1, 1, 1,
	0, 0, 0, 0, 1, 1, 0, 1, 1,
};

const int turn[4] = { 1, 2, 3, 0 };
const int re_turn[4] = { 3, 0, 1, 2 };

queue<int> q;
vector<int> ans;
int clocks;

int visited[262145] = { 0 };

void bfs(int clock)
{
	int i, j, c, temc, m;
	
	q.push(clock);
	visited[clock] = 1;

	while (! q.empty())
	{
		c = q.front();
		q.pop();
		m = visited[c];
		
		for (i = m; i <= 9; i++)
		{
			temc = 0;
			for (j = 0; j < 9; j++)
			{
				int tur = (c >> j*2) & 0x03;
				if (move[i-1][j])
					temc |= (turn[tur] << j*2);
				else
					temc |= (tur << j*2);
			}
			
			if (visited[temc] == 0)
			{
				q.push(temc);
				visited[temc] = i;
			}

			if (temc == 0)
				return;
		}
	}
}

void get_path()
{
	int j, clo = 0, temc;
	while (clo != clocks)
	{
		ans.push_back(visited[clo]);
		temc = 0;
		for (j = 0; j < 9; j++)
		{
			int tur = (clo >> j*2) & 0x03;
			if (move[visited[clo]-1][j])
				temc |= (re_turn[tur] << j*2);
			else
				temc |= (tur << j*2);
		}
		clo = temc;
	}
}

void disp_path()
{
	vector<int>::reverse_iterator rit = ans.rbegin();
	while (rit != ans.rend())
	{
		cout << *rit<< " ";
		rit++;
	}
}

int main()
{
	int i, m, clo;
	m = 0;
	clocks = 0x0;
	for (i = 1; i <= 9; i++)
	{
		cin >> clo;
		clocks |= (clo << m);
		m += 2;
	}
	
	bfs(clocks);
	get_path();
	disp_path();

	return 0;
}