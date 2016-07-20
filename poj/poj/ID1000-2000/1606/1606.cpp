/*
 * problem:	poj 1606
 * author:	guzhoudiaoke
 * time:	2011-10-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;

#define FILL_A		1
#define FILL_B		2
#define EMPTY_A		3
#define EMPTY_B		4
#define POUR_A_B	5
#define POUR_B_A	6
#define SUCCESS		7
#define NOTDEF		8

typedef struct state {
	int a;
	int b;
} state;

typedef struct visited {
	char opt;
	short father_a;
	short father_b;
} visited;

visited v[1001][1001];
int ca, cb, n;
vector<int> ans;
state p;

void bfs(state s)
{
	queue<state> q;
	state temp;
	q.push(s);
	v[s.a][s.b].opt = NOTDEF;

	while (! q.empty())
	{
		temp.a = q.front().a;
		temp.b = q.front().b;
		q.pop();

		// fill A
		if (temp.a != ca)
		{
			p.a = ca;
			p.b = temp.b;
			if (v[p.a][p.b].opt == 0)
			{
				v[p.a][p.b].opt = FILL_A; v[p.a][p.b].father_a = temp.a; v[p.a][p.b].father_b = temp.b;
				q.push(p);
				if (p.b == n)
					return;
			}
		}

		// fill B
		if (temp.b != cb)
		{
			p.a = temp.a;
			p.b = cb;
			if (v[p.a][p.b].opt == 0)
			{
				v[p.a][p.b].opt = FILL_B; v[p.a][p.b].father_a = temp.a; v[p.a][p.b].father_b = temp.b;
				q.push(p);
				if (p.b == n)
					return;
			}
		}

		// empty A
		if (temp.a != 0)
		{
			p.a = 0;
			p.b = temp.b;
			if (v[p.a][p.b].opt == 0)
			{
				v[p.a][p.b].opt = EMPTY_A; v[p.a][p.b].father_a = temp.a; v[p.a][p.b].father_b = temp.b;
				q.push(p);
				if (p.b == n)
					return;
			}
		}

		// empty B
		if (temp.b != 0)
		{
			p.a = temp.a;
			p.b = 0;
			if (v[p.a][p.b].opt == 0)
			{
				v[p.a][p.b].opt = EMPTY_B; v[p.a][p.b].father_a = temp.a; v[p.a][p.b].father_b = temp.b;
				q.push(p);
				if (p.b == n)
					return;
			}
		}

		// pour A B
		if (temp.a != 0 && temp.b != cb)
		{
			p.a = 0;
			p.b = temp.b + temp.a;
			if (p.b > cb)
			{
				p.a = p.b - cb;
				p.b = cb;
			}
			if (v[p.a][p.b].opt == 0)
			{
				v[p.a][p.b].opt = POUR_A_B; v[p.a][p.b].father_a = temp.a; v[p.a][p.b].father_b = temp.b;
				q.push(p);
				if (p.b == n)
					return;
			}
		}

		// pour B A
		if (temp.b != 0 && temp.a != ca)
		{
			p.a = temp.b + temp.a;
			p.b = 0;
			if (p.a > ca)
			{
				p.b = p.a - ca;
				p.a = ca;
			}
			if (v[p.a][p.b].opt == 0)
			{
				v[p.a][p.b].opt = POUR_B_A; v[p.a][p.b].father_a = temp.a; v[p.a][p.b].father_b = temp.b;
				q.push(p);
				if (p.b == n)
					return;
			}
		}
	}
}

void get_path()
{
	int opt, fa = p.a, fb = p.b, temp;
	ans.push_back(SUCCESS);
	while (1)
	{
		opt = v[fa][fb].opt;
		
		temp = v[fa][fb].father_a;
		fb = v[fa][fb].father_b;
		fa = temp;

		ans.push_back(opt);

		if (fa == 0 && fb == 0)
			break;
	}
}

void disp_ans()
{
	vector<int>::reverse_iterator rit = ans.rbegin();
	while (rit != ans.rend())
	{
		switch (*rit)
		{
		case FILL_A:
			printf("fill A\n");
			break;
		case FILL_B:
			printf("fill B\n");
			break;
		case EMPTY_A:
			printf("empty A\n");
			break;
		case EMPTY_B:
			printf("empty B\n");
			break;
		case POUR_A_B:
			printf("pour A B\n");
			break;
		case POUR_B_A:
			printf("pour B A\n");
			break;
		case SUCCESS:
			printf("success\n");
			break;
		}

		rit++;
	}
}

int main()
{
	state s;
	while (scanf("%d %d %d", &ca, &cb, &n) != EOF)
	{
		memset(v, 0, sizeof(v));
		ans.clear();
		s.a = 0;
		s.b = 0;
		bfs(s);
		get_path();
		disp_ans();
	}

	return 0;
}