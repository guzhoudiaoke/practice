#include <iostream>
#include <string>
using namespace std;

bool correct(const string &s, const string &t)
{
    if (s.length() != t.length())
        return false;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] != t[len-i-1]) {
            return false;
        }
    }

    return true;
}

int main()
{
    string s, t;
    cin >> s; 
    cin >> t;
    
    if (correct(s, t)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
