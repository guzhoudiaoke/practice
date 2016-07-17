#include <iostream>
using namespace std;

int play(int m, int n)
{
    if (m == 1 || n == 1) {
        return 1;
    }

    return play(m-1, n-1) ^ 1;
}

int main()
{
    int m, n;
    cin >> m >> n;

    if (play(m, n) & 0x01) {
        cout << "Akshat" << endl;
    }
    else {
        cout << "Malvika" << endl;
    }

    return 0;
}
