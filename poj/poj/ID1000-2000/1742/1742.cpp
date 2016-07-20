/*
 * poj 1013
 * guzhoudiaoke
 * 2011-10-18
 */

#include <stdio.h>
#include <string.h>

/*
 * dp[i][0]: 表示凑成i面值的最后一枚硬币是哪一种
 * dp[i][1]: 表示dp[i][0] 表示的硬币已经用了几枚了
 */
int a[101], c[101], n, m, dp[100001][2], pre, ans;;
bool price[100001];


// 普通多重背包：TLE
void solve()
{
	int i, j, k, w;

	memset(price, 0, sizeof(bool) * (m+1));
	price[0] = true;

	for (i = 1; i <= n; i++)
		for (j = m-1; j >= 0; j--)
			if (price[j] == true)
				for (k = 1; k <= c[i]; k++)
				{
					w = a[i] * k;
					if (j+w > m) break;
					else price[j+w] = true;
				}
	ans = 0;
	for (i = 1; i <= m; i++)
		if (price[i] == true)
			ans++;
}

// 更快的多重背包
void solve2()
{
	int i, j, k;
	ans = 0;

	memset(price, 0, sizeof(bool) * (m+1));
	memset(dp, 0, sizeof(dp));
	price[0] = true;

	/*
	 * 对于每种硬币i，用变量j 扫描a[i]~m 区间
	 * 如果price[j - a[i]] == 1 并且 price[j] == 0
	 * 那么有可能可以用一枚大小为a[i]的硬币与j - a[i]组合，构成j面值。
	 * 但是如果j - a[i]的组合中已经有了c[i]枚a[i]，那么a[i]就不能和j - a[i]组合了。
	 */
	for (i = 1; i <= n; i++)
		for (j = a[i]; j <= m; j++)
		{
			pre = j - a[i];
			// 如果price[j - a[i]] == 1 并且 price[j] == 0，且该种硬币没用完
			if (!price[j] && price[pre] && !(dp[pre][0] == i && dp[pre][1] == c[i]))
			{
				ans++;
				price[j] = true;
				dp[j][0] = i;
				dp[j][1] = dp[pre][0] == i ? dp[pre][1] + 1 : 1;
			}
		}
}


int main()
{
	int i;
	while (1)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= n; i++)
			scanf("%d", &c[i]);

		solve2();
		printf("%d\n", ans);
	}

	return 0;
}