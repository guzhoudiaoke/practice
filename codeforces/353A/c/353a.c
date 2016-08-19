#include <stdio.h>

int xxn[101];
int yyn[101];

int main()
{
    int n, x, y, sumx = 0, sumy = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x % 2 == 0) {
            xxn[i] = 0;
        }
        else {
            xxn[i] = 1;
        }
        if (y % 2 == 0) {
            yyn[i] = 0;
        }
        else {
            yyn[i] = 1;
        }

        sumx += x;
        sumy += y;
    }

    if (sumx % 2 == 0 && sumy % 2 == 0) {
        printf("0\n");
    }
    else if (sumx % 2 + sumy % 2 == 1) {
        printf("-1\n");
    }
    else {
        if (n == 1) {
            printf("-1\n");
        }
        else {
            int find = 0;
            for (int i = 0; i < n; i++) {
                if (xxn[i] != yyn[i]) {
                    find = 1;
                    break;
                }
            }
            if (find == 1) {
                printf("1\n");
            }
            else {
                printf("-1\n");
            }
        }
    }

    return 0;
}

