/*
* problem: poj 2381
* author: guzhoudiaoke
* time: 2011-09-28
*/

#include <iostream>

using namespace std;

bool r[16000001];

int main()
{
	long long a, c, m, r0, i, max, k, pre;
	cin >> a >> c >> m >> r0;

	while (1)
	{
		r[r0] = true;
		r0 = (a*r0 + c) % m;
		if (r[r0]) break;
	}

	max = 0;
	pre = -1;
	for (i = 0; i < 16000001; i++)
		if (r[i])
		{
			if (pre < 0)
				pre = i;
			
			else
			{
				if (i-pre > max)
					max = i-pre;
				pre = i;
			}	
		}

	cout << max << endl;
	return 0;
}