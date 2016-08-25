#include <stdio.h>

int an[100001];

int solve(int n)
{
    int ans = 1, cur = 1;
    int pre = an[0];
    for (int i = 1; i < n; i++) {
        if (an[i] > pre) {
            pre = an[i];
            cur++;
            if (cur > ans) {
                ans = cur;
            }
        }
        else {
            pre = an[i];
            cur = 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
    }

    printf("%d\n", solve(n));
    return 0;
}
