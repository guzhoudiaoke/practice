/*
 * poj 2051
 * guzhoudiaoke@126.com
 * 2011-11-03
 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct register_struct {
	int q_num;
	int period;
	int time;
} reg;

bool operator <(const reg r1, const reg r2)
{
	if (r1.time != r2.time)
		return r1.time > r2.time;
	return (r1.q_num > r2.q_num);
}

priority_queue<reg, vector<reg> > q;
int k;

void solve()
{
	int i;
	for (i = 0; i < k; i++)
	{
		reg r;
		r.q_num = q.top().q_num;
		r.period = q.top().period;
		r.time = q.top().time + r.period;
		cout << r.q_num << endl;
		q.pop();
		q.push(r);
	}
}

int main()
{
	string str;
	int i = 0;
	reg r;

	while (1) {
		cin >> str;
		if (str == "#") break;

		cin >> r.q_num >> r.period;
		r.time = r.period;
		q.push(r);
	}
	
	cin >> k;
	solve();

	return 0;
}
