#include <stdio.h>

int an[100001];

int main()
{
    int n; 
    scanf("%d", &n);

    int pre = 0;
    int increase = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
        if (increase == -1) {
            if (an[i] < pre) {
                increase = i;
            }
            pre = an[i];
        }
    }

    int ans = -1;
    if (increase == -1) {
        ans = 0;
    }
    else {
        if (an[0] < an[n-1]) {
            ans = -1;
        }
        else {
            pre = an[increase];
            ans = n - increase;
            for (int i = increase+1; i < n; i++) {
                if (an[i] < pre) {
                    ans = -1;
                    break;
                }
                pre = an[i];
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
