#include <iostream>
using namespace std;

bool is_beautiful(int y)
{
    bool have[10] = {false};

    while (y) {
        int mod = y % 10;
        if (have[mod]) {
            return false;
        }
        else {
            have[mod] = true;
        }
        y /= 10;
    }

    return true;
}

int main()
{
    int year;
    cin >> year;

    int result = 0;
    for (int i = year + 1; i < 10000; i++) {
        if (is_beautiful(i)) {
            result = i;
            break;
        }
    }

    cout << result << endl;
    return 0;
}
