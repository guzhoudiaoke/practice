/*
 * poj 2153
 * guzhoudiaoke@126.com
 * 2011-11-10
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef struct student {
	int score;
	int index;
} student;

student stu[10000];
int n;
map<string, int> name_index;

bool stu_cmp(student s1, student s2)
{
	return s1.score > s2.score;
}

int main()
{
	string str;
	char buf[64];
	int m, score;

	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets(buf);
		str = buf;
		name_index.insert(pair<string, int>(str, i));
		stu[i].index = i;
		stu[i].score = 0;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> score;
			getchar();
			cin.getline(buf, 64);
			int index = name_index[buf];
			stu[index].score += score;
		}

		int index = name_index["Li Ming"];
		score = stu[index].score;
		int ans = 1;

		for (int j = 0; j < n; j++)
			if (stu[j].score > score)
				ans++;

		cout << ans << endl;
	}

	return 0;
}
