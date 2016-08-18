#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MID 1000

int map[MID*2+1][MID*2+1];
int col_min[MID*2+1];
int col_max[MID*2+1];
int row_min[MID*2+1];
int row_max[MID*2+1];

int solve()
{
    for (int i = 0; i < MID*2+1; i++) {
        col_min[i] = -1;
        col_max[i] = -1;
        for (int j = 0; j < MID*2+1; j++) {
            if (map[j][i] == 1) {
                col_min[i] = j;
                break;
            }
        }
        if (col_min[i] == -1) {
            continue;
        }

        for (int j = MID*2; j > col_min[i]; j--) {
            if (map[j][i] == 1) {
                col_max[i] = j;
                break;
            }
        }

        if (col_min[i] == col_max[i]) {
            col_min[i] = -1;
            col_max[i] = -1;
        }
    }

    for (int i = 0; i < MID*2+1; i++) {
        row_min[i] = -1;
        row_max[i] = -1;
        for (int j = 0; j < MID*2+1; j++) {
            if (map[i][j] == 1) {
                row_min[i] = j;
                break;
            }
        }
        if (row_min[i] == -1) {
            continue;
        }

        for (int j = MID*2; j > row_min[i]; j--) {
            if (map[i][j] == 1) {
                row_max[i] = j;
                break;
            }
        }

        if (row_min[i] == row_max[i]) {
            row_min[i] = -1;
            row_max[i] = -1;
        }
    }

    int ans = 0;
    for (int i = 0; i < MID*2+1; i++) {
        for (int j = 0; j < MID*2+1; j++) {
            if (map[i][j] == 1) {
                if (j > row_min[i] && j < row_max[i] && i > col_min[j] && i < col_max[j]) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, x, y, i;
    memset(map, 0, sizeof(int) * (MID*2+1) * (MID*2+1));
    memset(col_min, 0, sizeof(int) * (MID*2+1));
    memset(col_max, 0, sizeof(int) * (MID*2+1));
    memset(row_min, 0, sizeof(int) * (MID*2+1));
    memset(row_max, 0, sizeof(int) * (MID*2+1));

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        map[x+MID][y+MID] = 1;
    }

    printf("%d\n", solve());
        
    return 0;
}
