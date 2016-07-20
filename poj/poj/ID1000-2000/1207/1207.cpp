/*
 * poj 1207
 * guzhoudiaoke@126.com
 * 2011-11-22 20:21
 */

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_BACKUP 1000001

int backup[MAX_BACKUP + 1];

int get_iterator(int num)
{
	int iter = 1;
	vector<int> vec;

	while (1)
	{
		vec.push_back(num);
		if (num <= MAX_BACKUP && backup[num]) {
			iter += backup[num]-1;
			num = 1;
		}
		if (num == 1)
		{
			int i = 0;
			vector<int>::iterator it = vec.begin();
			while (it != vec.end()) {
				num = *it;
				if (num <= MAX_BACKUP)
					backup[num] = iter-i;
				i++;
				it++;
			}
			return iter;
		}
		if (num % 2)
			num = num*3 + 1;
		else
			num = num / 2;
		
		iter++;
	}
}

int solve(int begin, int end)
{
	int max = 0;
	for (int i = begin; i <= end; i++)
	{
		int iter = get_iterator(i);
		if (iter > max)
			max = iter;
	}

	return max;
}

int main()
{
	int begin, end, i, j;
	memset(backup, 0, sizeof(backup));

	while (scanf("%d %d", &i, &j) != EOF)
	{
		begin = i > j ? j : i;
		end = i > j ? i : j;

		printf("%d %d %d\n", i, j, solve(begin, end));
	}

	return 0;
}

