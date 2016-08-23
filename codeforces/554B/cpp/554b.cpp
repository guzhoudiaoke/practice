#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, int> strs;
    string s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (strs.find(s) != strs.end()) {
            strs[s]++;
        }
        else {
            strs[s] = 1;
        }
        if (strs[s] > ans) {
            ans = strs[s];
        }
    }

    cout << ans << endl;

    return 0;
}
