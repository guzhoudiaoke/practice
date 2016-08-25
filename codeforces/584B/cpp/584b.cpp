#include <cstdio>

typedef unsigned long long uint64;

const uint64 c_mod = 1e9 + 7;

uint64 mod(uint64 a, uint64 b)
{
    uint64 ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % c_mod;
        }
        a = (a * a) % c_mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    uint64 n;
    scanf("%lld", &n);
    uint64 a = mod(27, n);
    uint64 b = mod(7, n);
    printf("%lld\n", (((a % c_mod) - (b % c_mod)) + c_mod) % c_mod);
    return 0;
}
