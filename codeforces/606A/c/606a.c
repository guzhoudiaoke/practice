#include <stdio.h>

int solve(int a, int b, int c, int x, int y, int z)
{
    int ea = a - x;
    int eb = b - y;
    int ec = c - z;

    int ans = 0;
    if (ea > 0) {
        ans += ea / 2;
    }
    else {
        ans += ea;
    }
    if (eb > 0) {
        ans += eb / 2;
    }
    else {
        ans += eb;
    }
    if (ec > 0) {
        ans += ec / 2;
    }
    else {
        ans += ec;
    }

    return ans >= 0;
}

int main()
{
    int a, b, c, x, y, z;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    
    if (solve(a, b, c, x, y, z)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}
