#include <stdio.h>

typedef unsigned long long uint64;

int solve(uint64 a, uint64 b)
{
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < i-1; j++) {
            uint64 cur = (1ULL << i) - 1 - (1ULL << j);
            if (cur >= a && cur <= b)
                ans++;
        }
        if ((1ULL << 1) / 2 > b) {
            return ans;
        }
    }
    return ans;
}

int main()
{
    uint64 a, b;
    scanf("%llu %llu", &a, &b);
    printf("%d\n", solve(a, b));
    return 0;
}
