#include <stdio.h>

int an[100001];
int sum[1000001];

int solve(int n, int t)
{
    int left = 0, right = 1;
    int ans = 0, pre = 0;
    for (right = 0; right < n; right++) {
        while (left <= right && sum[right] - pre > t) {
            pre = sum[left];
            left++;
        }
        if (right - left + 1 > ans) {
            ans = right - left + 1;
        }
    }
    return ans;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
        if (i == 0) {
            sum[i] = an[i];
        }
        else {
            sum[i] = an[i] + sum[i-1];
        }
    }

    printf("%d\n", solve(n, t));
    return 0;
}
