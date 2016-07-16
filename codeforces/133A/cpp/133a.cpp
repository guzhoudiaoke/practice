#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool find = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
            find = true;
    }

    if (find) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
