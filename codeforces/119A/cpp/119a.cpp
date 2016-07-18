#include <iostream>
using namespace std;

int gcd(int a, int b)
{
        if (b == 0)
                return a;

        return gcd(b, a % b);
}

int main()
{
        int n, a, b;
        cin >> a >> b >> n;

        int result = 1;
        int rm = 0;
        while (n > 0) {
                rm = gcd(result ? a : b, n);

                if (n < rm)
                        break;
                n -= rm;
                result = !result;
        }
        cout << result << endl;
        return 0;
}

