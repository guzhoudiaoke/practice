#include <cstdio>

int main()
{
    int n, a, odd = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        sum += a;
        if (a % 2 != 0) {
            odd++;
        }
    }

    int ans = odd;
    if (sum % 2 == 0) {
        ans = n - odd;
    }
    printf("%d\n", ans);

    return 0;
}
