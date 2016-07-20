/*
 * poj 1256
 * guzhoudiaoke
 * 2011-10-11
 */

//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//bool cmp(char c1, char c2)
//{
//	if(tolower(c1) == tolower(c2)) 
//		return c1 < c2;
//	else
//		return tolower(c1) < tolower(c2);
//}
//
//int main()
//{
//	int n, i;
//	string str;
//
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		cin >> str;
//		sort(str.begin(), str.end(), cmp);
//		do
//		{
//			cout << str << endl;
//		} while (next_permutation(str.begin(), str.end(), cmp));
//	}
//	return 0;
//}


#include <iostream>
#include <cstring>
using namespace std;

bool flag[13];
char x[13], str[13];
int len;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//// 产生list[k:m] 的所有排列
//void perm(char list[], int k, int m)
//{
//	int i;
//	if (k == m)
//	{
//		cout << list << endl;
//	}else
//	{
//		for (i = k; i <= m; i++)
//		{
//			if (flag[i] || flag[i-1] == 0 && list[i] == list[i-1] && i > 0)//去重
//				continue;
//			swap(list[k], list[i]);
//			flag[i] = true;
//			perm(list, k+1, m);
//			swap(list[k], list[i]);
//			flag[i] = false;
//		}
//	}
//}

void dfs(int d)
{
	int i;
	if (d == len)
		cout << x << endl;
	for (i = 0; i < len; i++)
	{
		if (flag[i]) // 去重
			continue;
		flag[i] = true;
		x[d] = str[i];
		dfs(d+1);
		flag[i] = false;
		while (i+1 < len && str[i+1] == str[i]) i++;
	}
}

char format(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	
	return c - 'a';
}

int cmp(const void *a, const void *b)
{
	char fa, fb;
	fa = format(*((char *)a));
	fb = format(*((char *)b));

	if (fa == fb)
		return *((char *)a) - *((char *)b);
	
	return fa - fb;
}

int main()
{
	int n, i, j;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> str;
		for (j = 0; j < 13; j++)
			flag[j] = false;
		len = strlen(str);
		qsort(str, len, sizeof(char), cmp);
		x[len] = '\0';
		dfs(0);
	}

	return 0;
}