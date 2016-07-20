/*
 * poj 1013
 * guzhoudiaoke
 * 2011-10-18
 */

#include <stdio.h>
#include <string.h>

/*
 * dp[i][0]: ��ʾ�ճ�i��ֵ�����һöӲ������һ��
 * dp[i][1]: ��ʾdp[i][0] ��ʾ��Ӳ���Ѿ����˼�ö��
 */
int a[101], c[101], n, m, dp[100001][2], pre, ans;;
bool price[100001];


// ��ͨ���ر�����TLE
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

// ����Ķ��ر���
void solve2()
{
	int i, j, k;
	ans = 0;

	memset(price, 0, sizeof(bool) * (m+1));
	memset(dp, 0, sizeof(dp));
	price[0] = true;

	/*
	 * ����ÿ��Ӳ��i���ñ���j ɨ��a[i]~m ����
	 * ���price[j - a[i]] == 1 ���� price[j] == 0
	 * ��ô�п��ܿ�����һö��СΪa[i]��Ӳ����j - a[i]��ϣ�����j��ֵ��
	 * �������j - a[i]��������Ѿ�����c[i]öa[i]����ôa[i]�Ͳ��ܺ�j - a[i]����ˡ�
	 */
	for (i = 1; i <= n; i++)
		for (j = a[i]; j <= m; j++)
		{
			pre = j - a[i];
			// ���price[j - a[i]] == 1 ���� price[j] == 0���Ҹ���Ӳ��û����
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