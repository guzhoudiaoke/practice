#include <stdio.h>
#include <string.h>

int count[1001];

int main()
{
    memset(count, 0, sizeof(count));

    int n;
    scanf("%d", &n);

    int a, max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        count[a]++;
        if (count[a] > max) {
            max = count[a];
        }
    }
    printf("%d\n", n-max);
    return 0;
}
