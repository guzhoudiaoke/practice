#include <cstdio>
#include <cstring>

int main()
{
    int p, n, x, ans = -1;
    int table[301];
    memset(table, 0, sizeof(table));
    scanf("%d %d", &p, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (table[x % p] == 1) {
            ans = i+1;
            break;
        }
        table[x % p] = 1;
    }

    printf("%d\n", ans);

    return 0;
}
