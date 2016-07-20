/*
 * poj 2352
 * guzhoudiaoke@126.com
 * 2011-11-18
 */

#include <stdio.h>
#include <string.h>

typedef struct star_line_tree {
	int left;
	int right;
	int level;
} star;

star s[32001 * 3];
int level[15001];

void build_tree(int index, int left, int right)
{
	s[index].left = left;
	s[index].right = right;
	s[index].level = 0;

	if (left == right) return;

	int mid = (left+right) >> 1;
	build_tree(index*2, left, mid);
	build_tree(index*2+1, mid+1, right);
}

int find_tree(int index, int left, int right)
{
	if (left <= s[index].left && right >= s[index].right)
		return s[index].level;

	int mid = (s[index].left + s[index].right) >> 1;
	if (mid >= right)
		return find_tree(index*2, left, right);
	else if (left > mid)
		return find_tree(index*2+1, left, right);
	else
		return find_tree(index*2, left, right) + find_tree(index*2+1, left, right);
}

void add_tree(int index, int left, int right)
{
	s[index].level++;
	if (s[index].left == s[index].right)
		return;
	
	int mid = (s[index].left + s[index].right) >> 1;
	if (mid >= right)
		add_tree(index*2, left, right);
	else
		add_tree(index*2+1, left, right);
}

int main()
{
	int n, x, y, i;
	memset(level, 0, sizeof(level));
	build_tree(1, 0, 32000);

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		int lev = find_tree(1, 0, x);
		level[lev]++;
		add_tree(1, 0, x);
	}

	for (i = 0; i < n; i++)
		printf("%d\n", level[i]);

	return 0;
}
