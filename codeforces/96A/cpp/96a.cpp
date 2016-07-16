#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const char *c_danger_0 = "0000000";
const char *c_danger_1 = "1111111";


int main()
{
    string players;
    cin >> players;

    if (strstr(players.c_str(), c_danger_0) || strstr(players.c_str(), c_danger_1)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
