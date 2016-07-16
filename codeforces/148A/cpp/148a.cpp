#include <iostream>
using namespace std;

const int c_max = 1e5;

int main()
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int num = 0;
    for (int i = 1; i <= d; i++) {
        if (i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0)
            num++;
    }

    cout << (d - num) << endl;
    return 0;
}
