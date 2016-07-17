#include <iostream>
using namespace std;

typedef long long s64;


s64 sum(s64 a1, s64 an)
{
    return (a1 + an) * (an - a1 + 1) / 2;
}

int main()
{
    s64 k, n, w;
    cin >> k >> n >> w;
    cout << max(0ll, sum(1, w) * k - n) << endl;
    return 0;
}
