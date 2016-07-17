#include <iostream>
#include <cmath>
using namespace std;

const int c_max = 1e6;
bool is_prime[c_max + 1];

void init_prime(int max)
{
    for (int i = 2; i <= max; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i <= sqrt(max); i++) {
        if (is_prime[i]) {
            for (int j = i; j*i <= max; j++)
                is_prime[j*i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    init_prime(n);

    int x = 0;
    for (int i = n/2; i >= 4; i--) {
        if (!is_prime[i] && !is_prime[n-i]) {
            x = i;
            break;
        }
    }

    cout << x << " " << n-x << endl;
    return 0;
}
