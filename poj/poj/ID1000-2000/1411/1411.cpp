/*
 * problem: poj 1411
 * author:  guzhoudiaoke
 * time:	2011-09-27
 */

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime[50000];

void get_prime()
{
	for (int i = 0; i < 50000; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i < 225; i++)
		if (is_prime[i])
			for (int j = i+i; j < 50000; j+=i)
				is_prime[j] = false;
}

void get_pq(int m, int a, int b, int &p, int &q)
{
	int max_area = 0;
	int max_p = (int)(sqrt((double)m)+0.5);
	int i, j;
	for (i = max_p; i >= 2; i--)
		if (is_prime[i])
		{
			j = i;
			while (1)
			{
				if (j*a > b*i || i*j > m)
					break;
				if (is_prime[j])
					if (i*j > max_area)
					{
						max_area = i*j;
						p = i;
						q = j;
					}
				j++;
			}
		}
}

int main()
{
	int m, a, b, p, q;
	get_prime();

	while (1)
	{
		scanf("%d %d %d", &m, &a, &b);
		if (m == 0) break;

		get_pq(m, a, b, p, q);
		cout << p << " " << q << endl;
	}
	return 0;
}