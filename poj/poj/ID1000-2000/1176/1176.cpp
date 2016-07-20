/*
 * problem:	poj 1036
 * author:	guzhoudiaoke
 * time:	2011-10-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> on;
vector<int> off;

typedef struct lamps {
	char lamp[101];
} lamps;

int n, c;

vector<lamps> lamp_vec;

int judge(lamps lamp)
{
	vector<int>::iterator it = on.begin();
	while (it != on.end())
	{
		if (lamp.lamp[*it] != 1)
			return 0;
		it++;
	}
	
	it = off.begin();
	while (it != off.end())
	{
		if (lamp.lamp[*it] != 0)
			return 0;
		it++;
	}

	return 1;
}

void button_down(int no, lamps &lamp)
{
	switch (no)
	{
	case 1:
		for (int i = 1; i <= n; i++)
			lamp.lamp[i] = !lamp.lamp[i];
		break;
	case 2:
		for (int i = 1; i <= n; i+=2)
			lamp.lamp[i] = !lamp.lamp[i];
		break;
	case 3:
		for (int i = 2; i <= n; i+=2)
			lamp.lamp[i] = !lamp.lamp[i];
		break;
	case 4:
		for (int i = 1; i <= n; i+=3)
			lamp.lamp[i] = !lamp.lamp[i];
		break;
	}
}

int vec_find(lamps lamp)
{
	vector<lamps>::iterator it = lamp_vec.begin();
	while (it != lamp_vec.end())
	{
		int i;
		for (i = 1; i <= n; i++)
			if (lamp.lamp[i] != it->lamp[i])
				break;
		if (i == n+1) return 1;
		it++;
	}

	return 0;
}

void dfs(int depth, lamps la)
{
	if (depth == c)
	{
		if (judge(la) && ! vec_find(la))
			lamp_vec.push_back(la);
		return;
	}
	for (int i = 1; i <= 4; i++)
	{
		button_down(i, la);
		dfs(depth+1, la);
		button_down(i, la);
	}
}

void disp()
{
	vector<lamps>::iterator it = lamp_vec.begin();
	while (it != lamp_vec.end())
	{
		int i;
		for (i = 1; i <= n; i++)
			printf("%c", it->lamp[i] + '0');
		printf("\n");
		it++;
	}
}

bool lamp_less(const lamps &a, const lamps &b)
{
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (a.lamp[i] < b.lamp[i]) 
		{
			flag = true;
			break;
		}else if (a.lamp[i] > b.lamp[i])
		{
			flag = false;
			break;
		}
	}

	return flag;
}

int main()
{
	int temp;
	lamps la;

	scanf("%d %d", &n, &c);
	while (1)
	{
		scanf("%d", &temp);
		if (temp == -1) break;
		on.push_back(temp);
	}
	while (1)
	{
		scanf("%d", &temp);
		if (temp == -1) break;
		off.push_back(temp);
	}

	for (int i = 1; i <= n; i++)
		la.lamp[i] = 1;

	if (c > 4) c = c%4 + 4;
	
	dfs(0, la);
	sort(lamp_vec.begin(), lamp_vec.end(), lamp_less);
	disp();

	return 0;
}