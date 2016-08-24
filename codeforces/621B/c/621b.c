#include <stdio.h>
#include <string.h>

int main()
{
    int map1[2001]; // x+y
    int map2[2001]; // 1000+x-y

    memset(map1, 0, sizeof(map1));
    memset(map2, 0, sizeof(map2));

    int n, x, y;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        map1[x+y]++;
        map2[x-y+1000]++;
    }

    int ans = 0;
    for (int i = 0; i < 2001; i++) {
        if (map1[i] > 1) {
            ans += map1[i] * (map1[i] - 1) / 2;
        }
        if (map2[i] > 1) {
            ans += map2[i] * (map2[i] - 1) / 2;
        }
    }
    printf("%d\n", ans);

    return 0;
}
