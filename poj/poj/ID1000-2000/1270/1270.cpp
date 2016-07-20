/*
 * poj 1270
 * guzhoudiaoke
 * 2011-10-12
 */

#include <iostream>
#include <cstring>
using namespace std;

char variables[21];
char ans[21];
bool flag[21];
int constraints[27][27];
int len;

void dfs(int d)
{
	int i, j;
	if (d == len)
		cout << ans << endl;
	
	for (i = 0; i < len; i++)
	{
		if (flag[i])
			continue;
		for (j = 0; j < d; j++)
			if (constraints[ans[j]-'a'][variables[i]-'a'] == -1)
				return;
		flag[i] = true;
		ans[d] = variables[i];
		dfs(d+1);
		flag[i] = false;
	}
}

int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int main()
{
	char buf[128];
	int i;

	while (1)
	{
		memset(buf, 0, sizeof(buf));
		if (! cin.getline(buf, 128))
			break;
		char *p = buf;
		i = 0;
		while (*p)
		{
			variables[i++] = *p;
			p++; p++;
		}
		len = i;

		memset(buf, 0, sizeof(buf));
		memset(constraints, 0, sizeof(constraints));
		cin.getline(buf, 128);
		p = buf;
		while (*p)
		{
			char first, second;
			first = *p;
			p++; p++;
			second = *p;
			p++; p++;

			constraints[first-'a'][second-'a'] = 1;
			constraints[second-'a'][first-'a'] = -1;
		}

		qsort(variables, len, sizeof(char), cmp);
		memset(flag, 0, sizeof(flag));
		ans[len] = '\0';
		dfs(0);
		cout << endl;
	}

	return 0;
}