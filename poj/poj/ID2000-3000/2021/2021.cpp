#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

string name_list[100];
int map[100][100];
int x, num;

typedef struct person_age {
	int id;
	int age;
} person_age;

person_age p[100];

void solve(int t)
{
	for (int i = 0; i < num; i++)
	{
		if (map[t][i])
		{
			p[i].age = p[t].age - map[t][i];
			p[i].id = i;
			solve(i);
		}
	}
}

int cmp_p(const void *a, const void *b)
{
	person_age *pa = (person_age *)a;
	person_age *pb = (person_age *)b;
	
	if (pb->age != pa->age)
		return pb->age - pa->age;
	return strcmp(name_list[pa->id].c_str(), name_list[pb->id].c_str());
}

int main()
{
	int n, age, set_no, i, j, k;
	string fname, cname;

	cin >> n;
	set_no = 1;
	while (n--)
	{
		cin >> x;
		num = 0;
		memset(map, 0, sizeof(map));
		for (i = 0; i < x; i++)
		{
			cin >> fname >> cname >> age;
			for (j = 0; j < num; j++)
				if (name_list[j] == fname)
					break;
			if (j == num) {
				name_list[num] = fname;
				num++;
			}
			for (k = 0; k < num; k++)
				if (name_list[k] == cname)
					break;
			if (k == num) {
				name_list[num] = cname;
				num++;
			}
			map[j][k] = age;
		}

		for (i = 0; i < num; i++)
			if (name_list[i] == "Ted")
				break;

		p[i].id = i;
		p[i].age = 100;

		cout << "DATASET " << set_no << endl;
		solve(i);

		qsort(p, num, sizeof(person_age), cmp_p);

		set_no++;
		for (i = 1; i < num; i++)
			cout << name_list[p[i].id] << " " << p[i].age << endl;
	}

	return 0;
}
