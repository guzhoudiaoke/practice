#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    int num = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1])
            num++;
    }

    cout << num << endl;
    return 0;
}
