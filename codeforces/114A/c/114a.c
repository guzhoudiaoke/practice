#include <stdio.h>

typedef unsigned long long uint64;

int main()
{
    uint64 k, l;
    scanf("%llu", &k);
    scanf("%llu", &l);

    unsigned int ans = 0;
    uint64 tmp = k;
    while (k < l) {
        k *= tmp;
        ans++;
    }

    if (k == l) {
        printf("YES\n%u\n", ans);
    } else {
        printf("NO\n");
    }

    return 0;
}
