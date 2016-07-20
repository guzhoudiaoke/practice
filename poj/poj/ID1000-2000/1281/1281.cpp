/*
 * problem: poj 1281
 * author:	guzhoudiaoke
 * time:	2011-10-01
 */

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int, greater<int> > greater_list;
map<int, int, less<int> > less_list;
vector<int> removal;

map<int, int, greater<int> >::iterator it_greater;
map<int, int, less<int> >::iterator it_less;

int max_cost, length, policie, tem, time;
char buf[512], ch;

int main()
{
	while (1)
	{
		policie = 1;
		time = 0;
		removal.clear();
		greater_list.clear();
		less_list.clear();

		scanf("%d\n%d\n", &max_cost, &length);
		while (1)
		{
			scanf("%d%c", &tem, &ch);
			removal.push_back(tem);
			if (ch == '\n')
				break;
		}

		sort(removal.begin(), removal.end());
		
		while (1)
		{
			ch = getchar();
			if (ch == 'a')
			{
				//cin >> tem >> ch;
				scanf(" %d\n", &tem);
				it_greater = greater_list.find(tem);
				if (it_greater != greater_list.end())
				{
					it_greater->second++;
					it_less = less_list.find(tem);
					it_less->second++;
				}
				else
				{
					greater_list.insert(make_pair(tem, 1));
					less_list.insert(make_pair(tem, 1));
				}
			}
			else if (ch == 'r')
			{
				getchar();
				time++;
				if (! less_list.empty())
				{
					if (policie == 1)
					{
						it_less = less_list.begin();
						tem = it_less->first;
						if (it_less->second > 1)
						{
							it_less->second--;
							it_greater = greater_list.find(tem);
							it_greater->second--;
						}
						else
						{
							less_list.erase(it_less);
							it_greater = greater_list.find(tem);
							greater_list.erase(it_greater);
						}
					}
					else
					{
						it_greater = greater_list.begin();
						tem = it_greater->first;
						if (it_greater->second > 1)
						{
							it_greater->second--;
							it_less = less_list.find(tem);
							it_less->second--;
						}
						else
						{
							greater_list.erase(it_greater);
							it_less = less_list.find(tem);
							less_list.erase(it_less);
						}
					}
				}
				else
					tem = -1;

				if (removal[0] == time)
				{
					cout << tem << endl;
					removal.erase(removal.begin());
				}
			}
			else if (ch == 'p')
			{
				//cin >> tem >> ch;
				scanf(" %d\n", &tem);
				//getchar();
				policie = tem;
			}
			else if (ch == 'e')
			{
				getchar();
				break;
			}
		}
		
		ch = getchar();
		if (ch != '\n')
			break;
		else
		{
			cout << endl;
		}
	}

	return 0;
}