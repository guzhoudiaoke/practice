#include <iostream>
#include <string>
using namespace std;

bool is_upper(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

int main()
{
    string s, result;
    cin >> s;

    int upper = 0;
    for (int i = 1; i < s.length(); i++) {
        if (is_upper(s[i])) {
            upper++;
        }
    }

    if (upper == s.length() - 1) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                result += s[i] - 'A' + 'a';
            }
            else {
                result += s[i] - 'a' + 'A';
            }
        }
    }
    else {
        result = s;
    }

    cout << result << endl;
    return 0;
}
