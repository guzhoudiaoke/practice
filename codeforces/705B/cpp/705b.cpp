#include <cstdio>

int main()
{
    int n, a, ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 1) {
        }
        else {
            if ((a-1) % 2 == 0) {
            }
            else {
                ans = !ans;
            }
        }

        printf("%d\n", 1+ans);
    }
    return 0;
}
