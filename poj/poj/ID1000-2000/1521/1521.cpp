/*
 * poj 1521
 * guzhoudiaoke@126.com
 * 2011-10-16
 */

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

char str[10000];
int  num[256];
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	int i, a, b, c, len, sum;
	while (1)
	{
		scanf("%s", str);
		if (strcmp(str, "END") == 0)
			break;

		while (! q.empty())
			q.pop();
		
		for (i = 0; i < 256; i++)
			num[i] = 0;

		len = strlen(str);
		for (i = 0; i < len; i++)
			num[str[i]]++;

		for (i = 0; i < 256; i++)
			if (num[i] != 0)
				q.push(num[i]);

		if (q.size() == 1)
		{
			printf("%d %d 8.0\n", len*8, len);
			continue;
		}

		sum = 0;
		while (1)
		{
			a = q.top();
			q.pop();

			if (q.empty())
				break;

			b = q.top();
			q.pop();

			c = a + b;
			sum += c;

			q.push(c);
		}

		printf("%d %d %.1lf\n", 8*len, sum, 8.0*len/sum);
	}
	return 0;
}
