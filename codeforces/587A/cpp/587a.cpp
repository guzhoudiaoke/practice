#include <cstdio>

int main()
{
    int n, x;
    scanf("%d", &n);

    int counts[1000100] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        counts[x]++;
    }

    int ans = 0;
    for (int i = 0; i < 1000100; i++) {
        if (counts[i] == 0) {
            continue;
        }

        counts[i+1] += counts[i] >> 1;
        if (counts[i] & 1) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
