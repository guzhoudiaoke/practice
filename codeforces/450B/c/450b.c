#include <stdio.h>

int main()
{
    int x, y, n;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    int fn[6] = {x, y, y-x, -x, -y, x-y};

    int ans = fn[(n-1) % 6] % 1000000007;
    if (ans < 0) {
        ans += 1000000007;
    }
    printf("%d\n", ans);

    return 0;
}
