#include <iostream>
#include <algorithm>
using namespace std;

const int c_max = 50;

int main()
{
    int f[c_max] = {0};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }
    sort(f, f+m);

    int result = 1000;
    for (int i = 0; i <= m-n; i++) {
        result = min(result, f[i+n-1] - f[i]);
    }
    cout << result << endl;
    return 0;
}
