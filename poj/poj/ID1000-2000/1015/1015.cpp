/*
 * problem:	poj 2593
 * author:	guzhoudiaoke
 * time:	2011-10-02
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define BALANCE	400

/* d[i]: 第i 个人的d 值
 * p[i]: 第i 个人的p 值
 * dp[i][j]: 选了i 个人，总p - 总d 为j 的最大和
 */
int d[200], p[200], dp[21][801], path[21][801], sum_d, sum_p;
int n, m;
vector<int> result_path;

bool in_path(int cur, int delta, int k)
{
	int i, index;
	for (i = cur; i > 0; i--)
	{
		index = path[i][delta];
		if (index == k)
			return true;
		
		delta -= (p[index] - d[index]);
	}

	return false;
}

void get_path(int j)
{
	result_path.clear();
	int i, index;
	sum_d = sum_p = 0;
	for (i = m; i > 0; i--)
	{
		index = path[i][j];
		result_path.push_back(index);
		j -= (p[index] - d[index]);
		sum_d += d[index];
		sum_p += p[index];
	}

	sort(result_path.begin(), result_path.end());
}

void solve()
{
	int i, j, k, delta, sum;
	for (i = 0; i <= 20; i++)
		for (j = 0; j <= 800; j++)
		{
			dp[i][j] = -1;
			path[i][j] = -1;
		}
	dp[0][BALANCE] = 0;

	for (i = 0; i < m; i++)
		for (k = 0; k < n; k++)
		{
			delta = p[k] - d[k];
			sum	= p[k] + d[k];
			for (j = 0; j <= 800; j++)
				if (dp[i][j] != -1 && !in_path(i, j, k) && dp[i][j] + sum > dp[i+1][j+delta])
				{
					dp[i+1][j+delta] = dp[i][j] + sum;
					path[i+1][j+delta] = k;
				}
		}

	j = -1;
	for (i = 0; i <= 800; i++)
	{
		if (dp[m][400-i] != -1 && dp[m][400-i] > dp[m][400+i])
			j = 400-i;
		else if (dp[m][400+i] != -1)
			j = 400+i;
		if (j != -1)
			break;
	}

	get_path(j);
}

int main()
{
	int i, t = 0;
	while (1)
	{
		t++;
		scanf("%d %d", &n, &m);
		if (n == 0) break;

		for (i = 0; i < n; i++)
			scanf("%d %d", &p[i], &d[i]);

		solve();

		printf("Jury #%d\n", t);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", sum_p, sum_d);
		for (i = 0; i < m; i++)
			printf(" %d", result_path[i]+1);
		printf("\n\n");
	}

	return 0;
}