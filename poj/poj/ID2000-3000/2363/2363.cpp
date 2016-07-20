/*
 * problem:	poj 2363
 * author:	guzhoudiaoke
 * time:	2011-09-28
 */

#include <iostream>

using namespace std;

const int INF = 1000000;

int main()
{
	int c, n, i, j, k, min;
	cin >> c;

	while (c--)
	{
		cin >> n;
		min = INF;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				if (i*j > n) break;
				if (n % (i*j) == 0)
				{
					k = n / (i*j);
					if (i*j + i*k + j*k < min)
						min = i*j + i*k + j*k;
				}
			}

		cout << min*2 << endl;
	}
	return 0;
}