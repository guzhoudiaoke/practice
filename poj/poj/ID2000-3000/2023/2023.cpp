/*
 * poj 2023
 * guzhoudiaoke@126.com
 * 2011-11-01
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

typedef struct page {
	char line_type;
	char text[257];
	int next1, next2;
	string end_type;
} page;

int page_count;
page pages[100];
bool visited[100];
int ans[100], ans_index, find_ans;

bool dfs(int index)
{
	visited[index] = true;

	if (pages[index].line_type == 'E')
	{
		if (pages[index].end_type == "HAPPY")
			return true;
	}
	else
	{
		if (!visited[pages[index].next1])
		{
			ans[ans_index++] = pages[index].next1;
			if (dfs(pages[index].next1))
				return true;
			ans_index--;
		}
		
		if (!visited[pages[index].next2])
		{
			ans[ans_index++] = pages[index].next2;
			if (dfs(pages[index].next2))
				return true;
			ans_index--;
		}
	}

	return false;
}

int main()
{
	int t, set_no = 1;
	char ch;

	cin >> t;
	while (t--)
	{
		cin >> page_count;
		for (int i = 1; i <= page_count; i++)
		{
			cin >> pages[i].line_type;
			int j = 0;
			while (1)
			{
				cin >> ch;
				if (ch == '"') break;
			}
			while (1)
			{
				ch = getchar();
				if (ch == '"') break;
				pages[i].text[j++] = ch;
			}
			pages[i].text[j] = '\0';

			if (pages[i].line_type == 'C')
				cin >> pages[i].next1 >> pages[i].next2;
			else
				cin >> pages[i].end_type;
		}
		ch = getchar();
		
		memset(visited, false, sizeof(visited));
		find_ans = false;
		ans[0] = 1;
		ans_index = 1;
		dfs(1);

		cout << "STORY " << set_no << endl;
		set_no++;

		for (int i = 0; i < ans_index; i++)
			cout << pages[ans[i]].text << endl;
	}

	return 0;
}