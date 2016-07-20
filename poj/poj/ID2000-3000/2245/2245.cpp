/*
 * problem: poj 2245
 * author : guzhoudiaoke
 * time:	2011-09-26
 */

#include <iostream>

using namespace std;

// 从num[m...k-1] 中选n 个数
int ans[6];
void select(int m, int k, int n, int num[])
{
	int i;
	if (n == 0)
	{
		for (i = 0; i < 6; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	else if (k - m == n)
	{
		for (i = 0; i < 6-n; i++)
			cout << ans[i] << " ";
		for (i = m; i < k; i++)
			cout << num[i] << " ";
		cout << endl;
	}
	else
	{
		ans[6-n] = num[m];
		select(m+1, k, n-1, num);
		select(m+1, k, n, num);
	}
}

int main()
{
	int k;
	int num[13];

	while (1)
	{
		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++)
			cin >> num[i];

		select(0, k, 6, num);
		cout << endl;
	}

	return 0;
}