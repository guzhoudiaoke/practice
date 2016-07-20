/*
#include <stdio.h>
#include <string.h>

int cow[8001];

int main()
{
	int n, i, j, p;
	scanf("%d", &n);
	cow[0] = 1;
	for (i = 1; i < n; i++)
	{
		scanf("%d", &p);
		cow[i] = p+1;
		for (j = 0; j < i; j++)
			if (cow[j] >= cow[i])
				cow[j]++;
	}
	for (i = 0; i < n; i++)
		printf("%d\n", cow[i]);
	
	return 0;
}
*/

/* 基本思路 */
/*
#include <stdio.h>
#include <string.h>

int a[8001], p[8001], visited[8001], n;

int main()
{
	int i, j;
	scanf("%d", &n);
	a[1] = 0;
	for (i = 2; i <= n; i++)
		scanf("%d", &a[i]);
	
	for (i = n; i > 0; i--)
	{
		int cnt = 0;
		for (j = 1; j <= n; j++)
			if (!visited[j])
			{
				cnt++;
				if (cnt == a[i]+1)
					break;
			}
		p[i] = j;
		visited[j] = 1;
	}

	for (i = 1; i <= n; i++)
		printf("%d\n", p[i]);
	return 0;
}
*/

/* 树状数组 */
/*
#include <stdio.h>
#include <string.h>
int a[8001], c[8001], ans[8001], n;

int low_bit(int n)
{
	return n & (-n);
}

void modify(int i, int delta)
{
	while (i <= n)
	{
		c[i] += delta;
		i += low_bit(i);
	}
}

int sum(int i)
{
	int result = 0;
	while (i != 0)
	{
		result += c[i];
		i -= low_bit(i);
	}
	
	return result;
}

int binary_search(int t)
{
	int low = 1, high = n, mid;
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		int s = sum(mid);
		
		if (s >= t)
			high = mid-1;
		else
			low = mid+1;
	}

	while (sum(mid) < t) 
		mid++;
	
	return mid;
}

int main()
{
	int i;
	scanf("%d", &n);
	
	a[1] = 0;
	modify(1, 1);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a[i]);
		modify(i, 1);
	}

	for (i = n; i > 0; i--)
	{
		int t = binary_search(a[i] + 1);
		ans[i] = t;
		modify(t, -1);
	}

	for (i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}
*/

/* 线段树 */

#include <stdio.h>
#include <string.h>

typedef struct line_tree {
	int left;
	int right;
	int cnt;
} line_tree;

line_tree t[8001 * 3];
int a[8001], ans[8001], n;

int build_tree(int left, int right, int index)
{
	t[index].left = left;
	t[index].right = right;
	t[index].cnt = right - left + 1;
	
	if (left == right)
		return 0;
	else
	{
		int mid = (left + right)/2;
		build_tree(left, mid, index*2);
		build_tree(mid+1, right, index*2+1);
	}
	
	return 0;
}

int del_node(int index, int data)
{
	t[index].cnt--;
	if (t[index].left == t[index].right)
		return t[index].left;
	else if (data <= t[index*2].cnt)
		del_node(index*2, data);
	else
		del_node(index*2+1, data - t[index*2].cnt);
}

int main()
{
	scanf("%d", &n);
	a[1] = 0;
	for (int i = 2; i <= n; i++)
		scanf("%d", &a[i]);
	
	build_tree(1, n, 1);
	
	for (int i = n; i > 0; i--)
		ans[i] = del_node(1, a[i]+1);
	
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
		
	return 0;
}

