#include <stdio.h>

char name[200001];
char map[256];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s\n", name);

    for (int i = 0; i < 256; i++) {
        map[i] = i;
    }

    char buf[5];
    for (int i = 0; i < m; i++) {
        fgets(buf, 5, stdin);
        for (char j = 'a'; j <= 'z'; j++) {
            if (map[j] == buf[0]) {
                map[j] = buf[2];
            }
            else if (map[j] == buf[2]) {
                map[j] = buf[0];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        name[i] = map[name[i]];
    }

    printf("%s\n", name);

    return 0;
}
