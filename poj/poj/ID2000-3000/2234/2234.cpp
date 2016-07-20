#include <iostream>
using namespace std;

// 只要给对方剩下的异或为0，则可赢
int main()
{
	int m, piles, result, i;

	while (cin >> m)
	{
		result = 0;
		for (i = 0; i < m; i++)
		{
			cin >> piles;
			result ^= piles;
		}
		if (result)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}

