#include <stdio.h>
#include <string.h>

typedef unsigned long long uint64;

int bn[200001];

int abs(int x)
{
    if (x > 0) {
        return x;
    }
    return -x;
}

uint64 solve(int n)
{
    uint64 ans = abs(bn[0]);
    for (int i = 1; i < n; i++) {
        ans += abs(bn[i] - bn[i-1]);
    }
    return ans;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bn[i]);
    }

    printf("%llu\n", solve(n));
    return 0;
}
