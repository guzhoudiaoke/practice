#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    unsigned long long counts[10] = {0};
    for (int i = a; i <= b; i++) {
        int x = i;
        while (x != 0) {
            counts[x % 10]++;
            x /= 10;
        }
    }

    int digits[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    unsigned long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += (unsigned long long)(counts[i] * digits[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
