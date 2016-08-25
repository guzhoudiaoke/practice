#include <iostream>
#include <algorithm>
using namespace std;

int an[300001];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> an[i];
    }
    sort(an, an+n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i + 1 - an[i] > 0 ? i + 1 - an[i] : an[i] - i - 1;
    }

    cout << ans << endl;

    return 0;
}
