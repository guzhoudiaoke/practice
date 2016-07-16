#include <iostream>
using namespace std;

bool is_lucky(int num)
{
    while (num) {
        int mod = num % 10;
        if (mod != 4 && mod != 7)
            return false;
        num /= 10;
    }
    return true;
}

int main()
{
    int num;
    cin >> num;

    bool almost_lucky = false;
    for (int i = 4; i <= num; i++) {
        if (is_lucky(i)) {
            if (num % i == 0) {
                almost_lucky = true;
            }
        }
    }

    if (almost_lucky)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
