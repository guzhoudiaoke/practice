#include <cstdio>
#include <algorithm>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int an[101];
    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
    }

    std::sort(an, an+n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (an[i] >= 0) {
            break;
        }
        ans -= an[i];
    }
    printf("%d\n", ans);

    return 0;
}
