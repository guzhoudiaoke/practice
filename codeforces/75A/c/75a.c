#include <stdio.h>

int nozero(int n)
{
    int an[10];
    int i = 0;
    while (n) {
        int m = n % 10;
        n /= 10;
        if (m != 0) {
            an[i++] = m;
        }
    }

    int x = 1;
    int nn = 0;
    for (int j = 0; j < i; j++) {
        nn += an[j] * x;
        x *= 10;
    }

    return nn;
}

int solve(int a, int b)
{
    int c = a + b;
    int aa = nozero(a);
    int bb = nozero(b);
    int cc = nozero(c);

    return (cc == (aa + bb));
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (solve(a, b)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
