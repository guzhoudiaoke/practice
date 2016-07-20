/*
 * poj 1120
 * guzhoudiaoke
 * 2011-10-25
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;

int main()
{
	string str;
	int len;

	while (cin >> str)
	{
		if (str != "\n" && str != " ")
			vec.push_back(str);
	}

	len = 0;
	vector<string>::iterator it = vec.begin();
	while (it != vec.end())
	{
		if (*it == "<br>")
		{
			cout << endl;
			len = 0;
		}
		else if (*it == "<hr>")
		{
			if (len != 0)
				cout << endl;
			for (int i = 0; i < 8; i++)
				cout << "----------";
			cout << endl;

			len = 0;
		}
		else
		{
			if (len+it->length()+1 > 80)
			{
				cout << endl;
				cout << *it;
				len = it->length();
			}
			else
			{
				if (len != 0)
				{
					cout << " ";
					len++;
				}
				cout << *it;
				len = len + it->length();
			}
		}
		
		it++;
	}

	printf("\n");

	return 0;
}