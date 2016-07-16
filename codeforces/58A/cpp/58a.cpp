#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string dst = "hello";
    int id = 0;
    for (int i = 0; i < str.length() && id < dst.length(); i++) {
        if (str[i] == dst[id]) {
            id++;
        }
    }

    if (id == dst.length())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
