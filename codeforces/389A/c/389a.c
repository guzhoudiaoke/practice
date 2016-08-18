#include <stdio.h>

int an[101];

int solve(int n)
{
    int min = 101;
    for (int i = 0; i < n; i++) {
        if (an[i] < min) {
            min = an[i];
        }
    }

    while (1) {
        int m = min;
        for (int i = 0; i < n; i++) {
            while (an[i] > min) {
                an[i] -= min;
                if (an[i] < m) {
                    m = an[i];
                }
            }
        }
        if (m == min) {
            break;
        }
        min = m;
    }

    return n*an[0];
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
    }
    printf("%d\n", solve(n));
    return 0;
}
