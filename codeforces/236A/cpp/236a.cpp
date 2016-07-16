#include <iostream>
#include <string>
using namespace std;

const string CHAT = "CHAT WITH HER!";
const string IGNORE = "IGNORE HIM!";

int main()
{
    bool found[26] = {false};
    string name;
    cin >> name;

    int num = 0;
    for (int i = 0; i < name.length(); i++) {
        if (!found[name[i] - 'a']) {
            found[name[i] - 'a'] = true;
            num++;
        }
    }

    if (num % 2 == 0) {
        cout << CHAT << endl;
    }
    else {
        cout << IGNORE << endl;
    }

    return 0;
}
