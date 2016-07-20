/*
 * poj 1065
 * guzhoudiaoke@126.com
 * 2011-10-16
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stick {
	int length;
	int weight;
	bool visited;
} stick;

stick s[50001];
int n;

int cmp_stick(const void *a, const void *b)
{
	stick *sa = (stick *)a;
	stick *sb = (stick *)b;
	
	if (sa->length == sb->length)
		return sa->weight - sb->weight;
	
	return sa->length - sb->length;
}

void greed(int index)
{
	int i, j;
	
	s[index].visited = true;
	j = index;
	
	for (i = index+1; i < n; i++)
		if (s[i].visited == false && s[i].weight >= s[j].weight)
		{
			s[i].visited = true;
			j = i;
		}
}

int main()
{
	int t, i, ans;

	scanf("%d", &t);
	while (t--)
	{
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d %d", &s[i].length, &s[i].weight);
		
		qsort(s, n, sizeof(stick), cmp_stick);
		ans = 0;
		for (i = 0; i < n; i++)
			if (s[i].visited == false)
			{
				greed(i);
				ans++;
			}
		printf("%d\n", ans);
	}

	return 0;
}
