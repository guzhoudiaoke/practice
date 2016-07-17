#include <iostream>
using namespace std;

typedef unsigned long long u64;

bool is_lucky(u64 num)
{
    if (num == 0)
        return false;

    while (num) {
        u64 mod = num % 10;
        num /= 10;
        if (mod != 4 && mod != 7)
            return false;
    }

    return true;
}

bool is_nearly_lucky(u64 num)
{
    if (num == 0)
        return false;

    int n = 0;
    while (num) {
        u64 mod = num % 10;
        num /= 10;
        if (mod == 4 || mod == 7)
            n++;
    }

    return is_lucky(n);
}

int main()
{
    u64 num;
    cin >> num;

    if (is_nearly_lucky(num)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
