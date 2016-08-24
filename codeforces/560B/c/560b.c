#include <stdio.h>

int solve(int a1, int b1, int a2, int b2, int a3, int b3)
{
    if (a2 <= a1 && a3 <= a1 && (b2+b3) <= b1) {
        return 1;
    }
    if (a2 <= a1 && b3 <= a1 && (b2+a3) <= b1) {
        return 1;
    }

    if (b2 <= b1 && b3 <= b1 && (a2+a3) <= a1) {
        return 1;
    }
    if (b2 <= b1 && a3 <= b1 && (a2+b3) <= a1) {
        return 1;
    }

    if (a2 <= b1 && a3 <= b1 && (b2+b3) <= a1) {
        return 1;
    }
    if (a2 <= b1 && b3 <= b1 && (b2+a3) <= a1) {
        return 1;
    }

    if (b2 <= a1 && b3 <= a1 && (a2+a3) <= b1) {
        return 1;
    }
    if (b2 <= a1 && a3 <= a1 && (a2+b3) <= b1) {
        return 1;
    }
    return 0;
}

int main()
{
    int a1, b1, a2, b2, a3, b3;
    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);
    scanf("%d %d", &a3, &b3);
    
    if (solve(a1, b1, a2, b2, a3, b3)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
