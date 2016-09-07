#include <cstdio>

long long an[100001];
int main()
{
    long long n, h, k;
    scanf("%lld %lld %lld", &n, &h, &k);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &an[i]);
    }

    long long ans = 0, i = 0, height = 0;
    for (; i < n; i++) {
        if (height + an[i] <= h) {
            height += an[i];
        }
        else {
            ans++;
            height = an[i];
        }

        ans += height / k;
        height %= k;
    }

    if (height != 0) {
        ans += height / k;
        height %= k;
        if (height != 0) {
            ans++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
