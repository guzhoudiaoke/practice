/*
 * poj 2038
 * guzhoudiaoke
 * 2011-10-21
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 100000;

int n;
vector<string> ranks;

bool cmp_alphabetically(char c1, char c2)
{
	return c1 < c2;
}

int calc_dif_order(string str1, string str2, char c1, char c2)
{
	bool flag = false;
	int i, j;
	for (i = 0; i < 5; i++)
		if (str1[i] == c1 || str1[i] == c2)
			break;
	for (j = 0; j < 5; j++)
		if (str2[j] == c1 || str2[j] == c2)
			break;

	if (str1[i] == str2[j])
		return 0;

	return 1;
}

int calc_distances(string str1, string str2)
{
	int dis = 0;
	for (char i = 'A'; i < 'E'; i++)
		for (char j = i+1; j <= 'E'; j++)
			dis += calc_dif_order(str1, str2, i, j);

	return dis;
}

int calc_distances_sum(string str)
{
	int sum = 0;
	vector<string>::iterator it = ranks.begin();
	while (it != ranks.end())
	{
		sum += calc_distances(str, *it);
		it++;
	}

	return sum;
}

int main()
{
	int i, min_dis;
	string str, min_str;

	while (1)
	{
		cin >> n;
		if (n == 0) break;

		ranks.clear();
		for (i = 0; i < n; i++)
		{
			cin >> str;
			ranks.push_back(str);
		}

		str = "ABCDE";
		min_dis = INF;
		do 
		{
			int dis = calc_distances_sum(str);
			if (dis < min_dis)
			{
				min_str = str;
				min_dis = dis;
			}
		} while (next_permutation(str.begin(), str.end(), cmp_alphabetically));

		cout << min_str << " is the median ranking with value " << min_dis << "." << endl;
	}

	return 0;
}