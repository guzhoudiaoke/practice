#include <stdio.h>

int max(int a, int b)
{
    if (a < b) {
        return b;
    }
    return a;
}

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    int min_a = 101, max_a = 0, min_b = 101;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a < min_a) {
            min_a = a;
        }
        if (a > max_a) {
            max_a = a;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &b);
        if (b < min_b) {
            min_b = b;
        }
    }

    int ans = -1;
    int tmp = max(max_a, 2*min_a);
    if (tmp < min_b) {
        ans = tmp;
    }

    printf("%d\n", ans);
    
    return 0;
}
