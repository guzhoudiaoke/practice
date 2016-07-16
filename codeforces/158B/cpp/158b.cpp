#include <iostream>
using namespace std;

const int c_max_group = 4;

int main()
{
    int n;
    cin >> n;

    int groups[c_max_group + 1] = {0};
    unsigned int g;
    for (int i = 0; i < n; i++) {
        cin >> g;
        groups[g]++;
    }

    unsigned int ret = groups[4] + groups[3];
    groups[1] = max(0, groups[1] - groups[3]);
    ret += (groups[2] + 1) / 2;
    groups[1] = max(0, groups[1] - 2*(groups[2]%2));
    ret += (groups[1] + 3) / 4;

    cout << ret << endl;

    return 0;
}
