#include <iostream>
using namespace std;

const int c_max = 100;

int calc(int *count, int sum)
{
    int cur = 0, num = 0;
    for (int i = c_max; i >= 0; i--) {
        for (int j = 0; j < count[i]; j++) {
            cur += i;
            num++;
            if (cur > sum - cur)
                return num;
        }
    }

    return num;
}

int main()
{
    int n;
    cin >> n;

    int count[c_max + 1] = {0}, coin, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        count[coin]++;
        sum += coin;
    }

    cout << calc(count, sum) << endl;

    return 0;
}
