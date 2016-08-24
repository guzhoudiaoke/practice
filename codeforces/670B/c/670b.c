#include <stdio.h>
#include <string.h>
#include <math.h>

int idn[100001];

int main()
{
    unsigned long long n, k;
    scanf("%llu %llu", &n, &k);
    memset(idn, 0, sizeof(idn));

    for (unsigned long long i = 1; i <= n; i++) {
        scanf("%d", &idn[i]);
    }

    unsigned long long x = sqrt(2*k);
    while (x * (x+1) >= 2*k) {
        x--;
    }
    printf("%d\n", idn[k - (x+1) * x / 2]);

    return 0;
}
