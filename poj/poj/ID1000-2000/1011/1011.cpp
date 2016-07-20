/*
 * problem: poj 1011
 * author:	guzhoudiaoke
 * time:	2011-09-30
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, sum, max_len, num, len;
int stick[65];
bool used[65];
bool found;

int cmp_stick(const void *a, const void *b)
{
	return (*(int *)b) - (*(int *)a);
}

bool dfs(int cur_len, int cur_num)
{
	if (found) return true;
	if (cur_num == num) found = 1;
	if (cur_len == len) 
		return dfs(0, cur_num + 1);

	for (int i = 0; i < n; i++)
		if (used[i] == false)
		{
			if (cur_len + stick[i] > len) continue;
			if (i > 0 && stick[i] == stick[i-1] && used[i-1] == 0) continue;
			used[i] = true;
			dfs(cur_len + stick[i], cur_num);
			used[i] = false;
			if (cur_len == 0)
				return false;
		}

	return false;
}

int main()
{
	int i;
	while (1)
	{
		cin >> n;
		if (n == 0) break;

		sum = 0;
		memset(used, false, sizeof(used));

		for (i = 0; i < n; i++)
		{
			cin >> stick[i];
			sum += stick[i];
		}

		qsort(stick, n, sizeof(int), cmp_stick);
		max_len = stick[0];

		for (i = max_len; i <= sum; i++)
			if (sum % i == 0)
			{
				found = false;
				len = i;
				num = sum / len;
				dfs(0, 0);
				if (found)
					break;
			}
		cout << i << endl;
	}
	return 0;
}