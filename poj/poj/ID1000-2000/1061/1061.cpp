/*
 * problem: poj 1061
 * author:	guzhoudiaoke
 * time:	2011-10-01
 */

#include <iostream>
using namespace std;

__int64 extend_gcd(__int64 a, __int64 b, __int64 &x0, __int64 &y0)
{
	if (b == 0)
	{
		x0 = 1;
		y0 = 0;
		return a;
	}
	
	__int64 r = extend_gcd(b, a%b, x0, y0);
	__int64 t = x0;
	x0 = y0;
	y0 = t - a/b*y0;

	return r;
}

int main()
{
	__int64 x, y, m, n, l;
	__int64 m_n, x_y, x0, y0, d, ans;

	cin >> x >> y >> m >> n >> l;
	m_n = m - n;
	x_y = y - x;
	if (m_n < 0)
	{
		m_n = -m_n;
		x_y = -x_y;
	}

	d = extend_gcd(m_n, l, x0, y0);

	if (x_y % d != 0)
		cout << "Impossible" << endl;
	else
	{
		ans = x0 * x_y / d;
		l = l / d;
		ans = (l + ans%l) % l;
		
		cout << ans << endl;
	}
}