/*
 * poj 1521
 * guzhoudiaoke@126.com
 * 2011-10-16
 */

#include <stdio.h>
#include <queue>
using namespace std;

#define GRAY 12

int n, color[13];
priority_queue<int> q;

bool greed(int kits)
{
	int i, gray, a, b, c, g;
	
	while (! q.empty())
		q.pop();

	for (i = 0; i < n; i++)
		q.push(kits*50 - color[i]);
	gray = color[GRAY];
	
	if (gray == 0)
		return true;

	g = 0;
	while (q.size() >= 3)
	{
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		c = q.top(); q.pop();

		g++; a--; b--; c--;
		
		if (a > 0) q.push(a);
		if (b > 0) q.push(b);
		if (c > 0) q.push(c);

		if (g == gray)
			return true;
	}

	return false;
}

int solve()
{
	int i, max_c = 0;
	for (i = 0; i < n; i++)
		if (color[i] > max_c)
			max_c = color[i];

	int kits = (int)((double)max_c / 50 + 0.5);
	while (1)
	{
		if (greed(kits)) break;
		kits++;
	}

	return kits;
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 0; i < n; i++)
			scanf("%d", &color[i]);
		scanf("%d", &color[GRAY]);

		printf("%d\n", solve());
	}

	return 0;
}