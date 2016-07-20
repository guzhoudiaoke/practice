/*
 * problem:	poj 1010
 * author:	guzhoudiaoke
 * time:	2011-09-29
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> type;
vector<int> custom;

int tire;
int cur[4], cur_max, cur_type;

int get_type_num(int i, int j, int k, int l)
{
	set<int> s;
	if (type[i] && s.find(i) == s.end()) s.insert(i);
	if (type[j] && s.find(j) == s.end()) s.insert(j);
	if (type[k] && s.find(k) == s.end()) s.insert(k);
	if (type[l] && s.find(l) == s.end()) s.insert(l);

	return s.size();
}

int get_num(int i, int j, int k, int l)
{
	int re = 4;
	if (type[i] == 0) re--;
	if (type[j] == 0) re--;
	if (type[k] == 0) re--;
	if (type[l] == 0) re--;

	return re;
}

int get_max(int i, int j, int k, int l)
{
	if (type[l])
		return type[l];
	if (type[k])
		return type[k];
	if (type[j])
		return type[j];
	return type[i];
}

void get_ans(int index)
{
	int i, j, k, l, sum;
	for (i = 0; i < type.size(); i++)
		for (j = i; j < type.size(); j++)
			for (k = j; k < type.size(); k++)
				for (l = k; l < type.size(); l++)
				{
					sum = type[i] + type[j] + type[k] + type[l];
					if (sum == custom[index])
					{
						int t = get_type_num(i, j, k, l);
						int m = get_max(i, j, k, l);
						if (t > cur_type)
						{
							cur_type = t;
							cur_max = m;
							cur[0] = i; cur[1] = j; cur[2] = k; cur[3] = l;
							tire = 0;
						}
						else if (t == cur_type)
						{
							int s = get_num(i, j, k, l);
							int cs = get_num(cur[0], cur[1], cur[2], cur[3]);
							if (s < cs)
							{
								cur_type = t;
								cur_max = m;
								cur[0] = i; cur[1] = j; cur[2] = k; cur[3] = l;
								tire = 0;
							}
							else if (s == cs)
							{
								if (m > cur_max)
								{
									cur_type = t;
									cur[0] = i; cur[1] = j; cur[2] = k; cur[3] = l;
									cur_max = m;
									tire = 0;
								}
								else if (m == cur_max)
									tire = 1;
							}
						}
					}
				}
}

int find_times(int n)
{
	int re = 0;
	for (int i = 0; i < type.size(); i++)
		if (n == type[i])
			re++;
	return re;
}

int main()
{
	int denomination, sum, i;

	while (1)
	{
		type.clear();
		custom.clear();

		while (cin >> denomination && denomination)
		{
			if (find_times(denomination) <= 4)
				type.push_back(denomination);
		}
		if (type.empty()) break;

		while (cin >> sum && sum)
			custom.push_back(sum);

		sort(type.begin(), type.end());
		type.push_back(0);
		
		for (i = 0; i < custom.size(); i++)
		{
			cur_max = cur_type = tire = 0;
			get_ans(i);
			cout << custom[i];
			
			if (cur_type == 0)
				cout << " ---- none" << endl;
			else if (tire)
				cout << " (" << cur_type << "): tie" << endl;
			else
			{
				cout << " (" << cur_type << "):";
				for (int j = 0; j < 4; j++)
					if (type[cur[j]])
						cout << " " << type[cur[j]];
				cout << endl;
			}
		}
	}

	return 0;
} 