#include <stdio.h>

int main()
{
    unsigned int n;;
    scanf("%u", &n);

    unsigned int xn[100001], hn[100001];
    for (int i = 0; i < n; i++) {
        scanf("%u %u", &xn[i], &hn[i]);
    }

    unsigned int cur = xn[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (i == n-1) {
            ans++;
        }
        else if (cur + hn[i] < xn[i]) {
            ans++;
            cur = xn[i];
        }
        else if (xn[i] + hn[i] < xn[i+1]) {
            ans++;
            cur = xn[i] + hn[i];
        }
        else {
            cur = xn[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
