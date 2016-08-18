#include <stdio.h>
#include <string.h>

int row[100001];
int col[100001];

int main()
{
    memset(row, 0, sizeof(int) * 100001);
    memset(col, 0, sizeof(int) * 100001);

    int n, m, r, c;
    unsigned long long cntx = 0, cnty = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &r, &c);
        if (row[r] == 0) {
            row[r] = 1;
            cntx++;
        }
        if (col[c] == 0) {
            col[c] = 1;
            cnty++;
        }
        printf("%lld ", (unsigned long long)n*n - (unsigned long long)n*(cntx+cnty) + cntx*cnty);
    }
    printf("\n");

    return 0;
}
