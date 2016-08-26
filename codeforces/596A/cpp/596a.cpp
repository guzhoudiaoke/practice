#include <cstdio>
#include <set>
using namespace std;

int abs(int x)
{
    if (x > 0) {
        return x;
    }
    return -x;
}

int main()
{
    int n, x[4], y[4];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int ans = 0;
    if (n >= 3) {
        int j = 0;
        while (j < n && ans == 0) {
            int i = j+1;
            while (i < n && ans == 0) {
                ans = abs(x[j] - x[i]) * abs(y[j] - y[i]);
                i++;
            }
            j++;
        }
    }
    else if (n == 2) {
        if (x[0] != x[1] && y[0] != y[1]) {
            ans = abs(x[0] - x[1]) * abs(y[0] - y[1]);
        }
    }

    if (ans == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", ans);
    }
    
    return 0;
}
