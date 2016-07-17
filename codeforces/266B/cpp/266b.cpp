#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, t;
    string q;
    cin >> n >> t;
    cin >> q;

    for (int i = 0; i < t; i++) {
        int index = 0;
        while (index + 1 < n) {
            if (q[index] == 'B' && q[index+1] == 'G') {
                char tmp = q[index];
                q[index] = q[index + 1];
                q[index + 1] = tmp;

                index += 2;
            }
            else {
                index++;
            }
        }
    }

    cout << q << endl;
    return 0;
}
