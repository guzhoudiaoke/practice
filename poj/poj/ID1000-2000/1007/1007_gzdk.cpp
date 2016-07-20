#include<iostream>
using namespace std;

struct Seq
{
	int inver;
	char line[51];
};

int inver_num(char* s,int n)
{
	int inv_counter = 0;
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] > s[j])
			inv_counter++;
		}
	return inv_counter;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Seq data[100],temp;

    for(int i = 0; i < m; i++)
	{
		cin>>data[i].line;
		data[i].inver = inver_num(data[i].line, n);
	}                    
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (data[i].inver > data[j].inver)
			{
				temp.inver = data[i].inver;
				data[i].inver = data[j].inver;
				data[j].inver = temp.inver;

				for (int k = 0; k < n; k++)
				{
					temp.line[k] = data[i].line[k];
					data[i].line[k] = data[j].line[k];
					data[j].line[k] = temp.line[k];
				}
			}
	for (int i = 0; i < m; i++)
		//cout<<data[i].line<<endl;
		cout<<data[i].inver<<endl;
    return 0;
}
