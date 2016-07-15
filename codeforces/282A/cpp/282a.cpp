#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "++X" || cmd == "X++") {
            result++;
        }
        else if (cmd == "--X" || cmd == "X--") {
            result--;
        }
    }
    cout << result << endl;

    return 0;
}
