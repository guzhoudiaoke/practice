#include <iostream>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    unsigned long seq[n];
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    int maxlen = 1, cur = 1;
    for (unsigned int i = 1; i < n; i++) {
        if (seq[i] >= seq[i-1]) {
            cur++;
        }
        else {
            cur = 1;
        }
        if (cur > maxlen) {
            maxlen = cur;
        }
    }

    cout << maxlen << endl;
    return 0;
}
