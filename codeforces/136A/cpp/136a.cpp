#include <iostream>
using namespace std;

const int c_max = 128;

int main()
{
    int n, f;
    cin >> n;

    int result[c_max] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> f;
        result[f] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
