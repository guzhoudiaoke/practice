#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m = 0, current = 0;
    for (int i = 0; i < n; i++) {
        int leave, enter;
        cin >> leave >> enter;
        current -= leave;
        current += enter;

        m = max(m, current);
    }

    cout << m << endl;

    return 0;
}
