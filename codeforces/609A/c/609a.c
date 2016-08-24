#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int count[1001];
    memset(count, 0, sizeof(count));

    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        count[a]++;
    }

    int ans = 0;
    int i = 1000;
    while (i > 0 && m > 0) {
        if (count[i] == 0) {
            i--;
            continue;
        }

        m -= i;
        count[i]--;
        ans++;
        if (count[i] == 0) {
            i--;
        }
    }
    printf("%d\n", ans);

    return 0;
}
